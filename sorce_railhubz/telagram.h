//telagram.h

/*
telagram is a strucutre used currntly for the msgs dispatcher
but i could see it being used by other msgs and comuncation services. implments a opratore overloader on == and <,. for priority msg comparsons.
*/

#ifndef TELAGRAM_H
#define TELAGRAM_H

#include <math.h>
#include "msg_cmdz.h"
#include <chrono>
// Smallest_Delay =0.20;
const std::chrono::milliseconds Smallest_Delay{200};

  template <class Type>
  Type derefrence_Type(void * ponter)
  {
    return *(Type*)(ponter);
  }


//std::ostream& operator<<(std::ostream& os, const Telegram& t)


extern "C"{

  struct telagram

  {
    std::chrono::steady_clock::time_point  trazmission_t;
    int sender;
    int receiver;
    float priority;
    msg_cmdz msg;
    void* Other_data;

    telagram():
      trazmission_t(std::chrono::steady_clock::now()),
      sender(-1),
      receiver(-1),
      priority(-1),
      msg(msg_cmdz::NULLCMD),
      Other_data(nullptr)
    {}

  telagram ( std::chrono::steady_clock::time_point time, int sender, int receiver, float priority, msg_cmdz msg,
               void* data):
              trazmission_t(trazmission_t),
              sender(sender),
              receiver(receiver),
              priority(priority),
              msg(msg),
              Other_data(data)
    {}
};


 inline bool operator ==( const telagram& tela1, const telagram& tela2)
   {

    auto dif_time = std::chrono::duration_cast<std::chrono::milliseconds>(tela1.trazmission_t - tela2.trazmission_t);

    return ( dif_time < Smallest_Delay) &&
           (tela1.sender == tela2.sender)       &&
           (tela1.receiver == tela2.receiver)   &&
           (tela1.msg == tela2.msg)             &&
           (tela1.priority ==tela2.priority);


}


 inline bool operator<(const telagram& tela1, const telagram& tela2)
  {
    if (tela1 == tela2)
       {return false;}
    else
     {
       if (tela1.priority == tela2.priority)
        {
          if(tela1.trazmission_t < tela2.trazmission_t)
          {return false;}
          else return true;
        }
       return (tela1.priority<tela2.priority);
      }

   }

}//end c func

#endif
