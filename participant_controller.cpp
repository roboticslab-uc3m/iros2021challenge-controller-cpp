#include <webots/Robot.hpp>

#include <iostream>

int main(int argc, char **argv)
{
    // Initialize the robot
    webots::Robot *robot = new webots::Robot();
    int timestep = int(robot->getBasicTimeStep());

    // Main loop:
    // - perform simulation steps until Webots is stopping the controller
    while (robot->step(timestep) != -1)
    {
        std::cout << "Hello World from c++!" << std::endl;
    }

    delete robot;
    return 0;
}
