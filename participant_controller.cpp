#include <webots/Robot.hpp>

#include <iostream>

int main(int argc, char **argv)
{
    webots::Robot *robot = new webots::Robot();

    std::cout << "Hello World from c++!" << std::endl;

    delete robot;
    return 0;
}
