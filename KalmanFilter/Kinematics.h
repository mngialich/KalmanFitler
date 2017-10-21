#ifndef KINEMATICS_H
#define KINEMATICS_H

#include <assert.h>
#include <iostream>
#include <vector>

class Kinematics
{
    public:
    
        Kinematics()
        {}
    
        template<typename T, typename A>
        std::vector<T,A> PropogateVelocity(
            const std::vector<T,A> state, 
            const std::vector<T,A> velocity,
            const T step_size)
        {
            assert(state.size() == 3);
            assert(velocity.size() == 3);
        
            std::vector<T,A> propogated_state(3,0);
            
            propogated_state[0] = state[0] + velocity[0] * step_size;
            propogated_state[1] = state[1] + velocity[1] * step_size;
            propogated_state[2] = state[2] + velocity[2] * step_size;
            
            return propogated_state;
        }
        
        
};

#endif