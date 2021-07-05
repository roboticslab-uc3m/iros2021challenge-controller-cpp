#include <webots/Robot.hpp>
#include <webots/Motor.hpp>
#include <webots/GPS.hpp>

#include <iostream>
#include <sstream>
#include <limits>

int main(int argc, char **argv)
{
    // Initialize the robot
    webots::Robot *robot = new webots::Robot();
    int timestep = int(robot->getBasicTimeStep());

    // Obtain waypoints
    double waypoints[10][2];
    const std::string waypoints_string = robot->getCustomData();
    std::istringstream waypoints_stream(waypoints_string);
    int i=0;
    double waypoints_element;
    while(waypoints_stream >> waypoints_element)
    {
        waypoints[i/2][i%2] = waypoints_element;
        i++;
    }
    std::cout << "Waypoints: ";
    for(int i=0; i<10; i++)
    {
        std::cout << "[" << waypoints[i][0] << " " << waypoints[i][1] << "] ";
    }
    std::cout << std::endl;

    // Initialize devices
    webots::Motor* motor_left = robot->getMotor("wheel_left_joint");
    webots::Motor* motor_right = robot->getMotor("wheel_right_joint");
    webots::GPS* gps = robot->getGPS("gps");

    motor_left->setVelocity(0.0);
    motor_right->setVelocity(0.0);

    motor_left->setPosition(std::numeric_limits<double>::infinity());
    motor_right->setPosition(std::numeric_limits<double>::infinity());

    gps->enable(timestep);

    // Main loop:
    // - perform simulation steps until Webots is stopping the controller
    while (robot->step(timestep) != -1)
    {
        const double * pos = gps->getValues();
        std::cout << "Hello World from c++! ["
                  << pos[0] << " " << pos[1] << " " << pos[2]
                  << "]" << std::endl;
        motor_left->setVelocity(5.0);
        motor_right->setVelocity(5.0);
    }

    delete robot;
    return 0;
}
