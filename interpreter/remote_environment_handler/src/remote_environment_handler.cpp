#include "remote_environment_handler.h"

std::any RemoteEnvironmentHandler::HandleXrayRequest() {
    auto &map = SingletonHolder<Map, Loader>::Instance();
    auto &robot = SingletonHolder<Robot, Loader>::Instance();
    MapVisionCommand xray(map, robot);
    xray.Run();
    return xray.GetAccumulatedValue();
}

void RemoteEnvironmentHandler::HandleMovementRequest(MoveDirection direction) {
    auto &robot = SingletonHolder<Robot, Loader>::Instance();
    auto &map = SingletonHolder<Map, Loader>::Instance();
    DrawCommand draw_cmd(map, robot);
    draw_cmd.Run();
    usleep(100000);
    RobotMoveCommand move_cmd(robot, direction);
    move_cmd.Run();
    draw_cmd.Run();
    usleep(300000);
}
