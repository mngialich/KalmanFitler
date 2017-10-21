#include "KalmanFilter/Kinematics.h"
#include "KalmanFilter/KalmanFilter.h"
#include "Inputs/Truth.h"

#include <chrono>
#include <iostream>
#include <vector>


int main(void)
{
    std::cout << "Navigation is running!" << std::endl;
    
    KalmanFilter kalman_filter;
    
    // Initialize a state
    std::vector<double> position(3, 0);
    std::vector<double> velocity(3 ,1);
    double time_step = 1;
    
    //Start Timer
    auto start = std::chrono::steady_clock::now();
    
    for(int i=0; i<100000; i++)
    {
        position = kalman_filter.PropogateVelocity(
            truth::position, 
            truth::velocity,
            time_step);

    }
    //Stop Timer
    auto end = std::chrono::steady_clock::now();
    
    auto diff = end - start;
    
    std::cout << "Executation time took: " << 
        std::chrono::duration <double, std::milli> (diff).count() <<
        "\n";
}