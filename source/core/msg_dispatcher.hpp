
//msg_dispatcher.hpp

/*msgs_dispatcher handles, basic entities, and give them the ability
to communcate.  their is a delay msgs functionianlty though not implmeted
with the trains as yet. though would be useful for adding singalings!
or having trains be able to give eachother hault on delay. etc
it uses a telgram struct with sender resiver info and othe information
it is inilizaed in a single instance in this implimintation but, i see the
advatage of isolating diffrent msgign services insitnace for paitular
needs or objects pools,. aka. these work for the lines and trains whom drivred
from base classes, the hubs, are not of the same object type and do not inhearnt
this msgsing service. but they could have thier OWN, msgs system
*/

#pragma once

#include <set>
#include <chrono>

#include "../h_libs/telagram.h"

#include "componentablez.hpp"

#define tranzmitor Msg_Dispatcher::instance()

const int SENDER_ID_IRRELEVANT = -1;
//typedef const std::chrono::steady_clock::time_point NODELAY = std::chrono::steady_clock::now();

class Base_TSym_entity;

class Msg_Dispatcher
{
  private :
    Msg_Dispatcher(){}
    Msg_Dispatcher(const Msg_Dispatcher&)=delete;
    Msg_Dispatcher& operator =(const Msg_Dispatcher&)= delete;

    std::set<telagram> dispatch_que;

    void call_receiver_handle(Base_TSym_entity* receiver, const telagram& tela);
  public :

    static Msg_Dispatcher* instance();

    void tranzmit(std::chrono::steady_clock::time_point  trazmission_t,
                  int sender,
                  int receiver,
                  float priority,
                  msg_cmdz msg,
                  void* Other_data);

    void tranzmit_delayed();

};


class tela_reciver : compoent
{

}; 