#ifndef INTERPRETER_LOADER_H
#define INTERPRETER_LOADER_H
#include "robot.h"
#include "map.h"
#include <string>
#include <filesystem>
#include <libconfig.h++>

template<class T>
class Loader {
public:
    static T Create() { static_assert(false, "Loader class must be specialized"); }
};


template<>
class Loader<Robot> {
public:
    static Robot Create() {
        SetConfigPath();
        return {LoadRobotLocation()};
    }

private:
    inline static std::string path_to_config{};

    static void SetConfigPath() {
        auto path = std::filesystem::current_path().parent_path();
        path /= "config.cfg";
        if (std::filesystem::exists(path))
            path_to_config = path.string();
        else
            throw std::runtime_error(
                    "Cannot find config file."
                    "It must be placed under the name 'config.cfg' in the parent directory of current path");
    }

    static UnitLocation LoadRobotLocation() {
        int x, y;
        libconfig::Config config;
        config.readFile(path_to_config);
        x = config.getRoot()["robot"]["location"]["x"];
        y = config.getRoot()["robot"]["location"]["y"];
        return {static_cast<size_t>(x), static_cast<size_t>(y)};
    }
};


template<>
class Loader<Map> {
public:
    static Map Create() {
        SetConfigPath();
        return LoadMap();
    }

private:
    inline static std::string path_to_config {};

    static void SetConfigPath() {
        auto path = std::filesystem::current_path().parent_path();
        path /= "config.cfg";
        if (std::filesystem::exists(path))
            path_to_config = path.string();
        else
            throw std::runtime_error(
                    "Cannot find config file."
                    "It must be placed under the name 'config.cfg' in the parent directory of current path");
    }

    static Map LoadMap() {
        libconfig::Config config;
        config.readFile(path_to_config);
        Map map = GetSizedMap(config);
        for (int i = 0; i < map.Lines(); ++i)
            LoadRow(map, config, i);
        auto matrix_map = Map::MapToMatrix(map);
        matrix_map.SetValue(matrix_map.Hash());
        return Map::MatrixToMap(matrix_map);
    }

    static Map GetSizedMap(libconfig::Config &config) {
        int lines = 0, columns = 0;
        lines = config.getRoot()["map"]["size"]["lines"];
        columns = config.getRoot()["map"]["size"]["columns"];
        return {static_cast<size_t>(lines), static_cast<size_t>(columns)};
    }

    static void LoadRow(Map &map, libconfig::Config &config, int row_number) {
        auto iter = map.begin_from(row_number, 0), end = map.begin_from(row_number + 1, 0);
        int column_number = 0;
        for (; iter != end; ++iter) {
            int mask = config.lookup("map.data")[row_number][column_number];
            *iter = MaskToCell(mask);
            column_number = ++column_number % map.Columns();
        }
    }

    static Cell MaskToCell(int mask) {
        bool top = mask / 1000;
        bool bottom = (mask % 1000) / 100;
        bool right = (mask % 100) / 10;
        bool left = mask % 10;
        return {top, bottom, right, left};
    }
};
#endif //INTERPRETER_LOADER_H
