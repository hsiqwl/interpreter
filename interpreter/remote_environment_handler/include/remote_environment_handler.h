#ifndef INTERPRETER_REMOTE_ENVIRONMENT_MANAGER_H
#define INTERPRETER_REMOTE_ENVIRONMENT_MANAGER_H
#include "singleton_holder.h"
#include "map_commands.h"
#include "robot_commands.h"
#include "draw_commands.h"
#include "loader.h"

class RemoteEnvironmentHandler {
public:
    static std::any HandleXrayRequest();

    static void HandleMovementRequest(MoveDirection direction);
};

#endif //INTERPRETER_REMOTE_ENVIRONMENT_MANAGER_H
