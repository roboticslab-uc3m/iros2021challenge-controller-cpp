#include <webots/Robot.hpp>
#include <webots/Motor.hpp>

#include <iostream>
#include <limits>

int main(int argc, char **argv)
{
    // Initialize the robot
    webots::Robot *robot = new webots::Robot();
    int timestep = int(robot->getBasicTimeStep());

    // Initialize devices
    webots::Motor* motor_left = robot->getMotor("wheel_left_joint");
    webots::Motor* motor_right = robot->getMotor("wheel_right_joint");

    // Main loop:
    // - perform simulation steps until Webots is stopping the controller
    while (robot->step(timestep) != -1)
    {
        std::cout << "Hello World from c++!" << std::endl;
    }

    delete robot;
    return 0;
}
