#include <iostream>
#include "interpreter.h"

int main(int argc, char *argv[]) {
    try {
        Interpreter interpreter;
        interpreter.SetLogStream();
        interpreter.Run(argv[1]);
    } catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }
}
