

#ifndef RAILHUBZ_COMPOENTABLEZ_HPP
#define RAILHUBZ_COMPOENTABLEZ_HPP

//#include "msg_dispatcher.hpp"
#include <cstdint>

using Tela_Priority = double; 


class compoentable
{

};

class compoent
{
    public : 
    compoent(class Base_TSym_entity* owner, Tela_Priority order_place = 1.0);
    virtual ~compoent();
    virtual void update(double dt); 
    virtual void process_input(const uint8_t* keystate) {}

    double get_priority() const {return order_place; }

    protected: 
    Tela_Priority order_place;
    class Base_TSym_entity* myowner;  
};

#endif