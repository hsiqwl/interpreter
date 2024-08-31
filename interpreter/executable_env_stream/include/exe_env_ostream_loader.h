#ifndef INTERPRETER_EXE_ENV_OSTREAM_LOADER_H
#define INTERPRETER_EXE_ENV_OSTREAM_LOADER_H
#include "loader.h"
#include <filesystem>
#include "executable_environment_ostream.h"

template<>
class Loader<ExecutableEnvironmentOutputStream> {
public:
    static ExecutableEnvironmentOutputStream Create() {
        SetConfigPath();
        libconfig::Config config;
        config.readFile(path_to_config);
        if (!config.exists("ostream_setting"))
            return {std::string()};
        std::string buffer_name = config.lookup("ostream_setting")["name"];
        return {buffer_name};

    }

private:
    static inline std::string path_to_config{};

    static void SetConfigPath() {
        auto path = std::filesystem::current_path().parent_path();
        path /= "config.cfg";
        if(std::filesystem::exists(path)){
            path_to_config = path.string();
        } else {
            throw std::runtime_error("Cannot find config file."
                                     "It must be placed under the name 'config.cfg' in the parent directory of current path");
        }
    }
};

#endif //INTERPRETER_EXE_ENV_OSTREAM_LOADER_H
