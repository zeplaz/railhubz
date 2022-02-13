//telagram.h

/*
telagram is a strucutre used currntly for the msgs dispatcher
but i could see it being used by other msgs and comuncation services. implments a opratore overloader on == and <,. for priority msg comparsons.
*/

#ifndef TELAGRAM_H
#define TELAGRAM_H


//#define USING_CHRONO
#define USING_CTIME

#ifdef USING_CHRONO
  #include <chrono>

#elifdef USING_CTIME
  #include<time.h>
#endif 



#include <math.h>
#include "msg_cmdz.h"


#ifdef USING_CHRONO
  #include <chrono>


using stdc_steady_clock = std::chrono::steady_clock; 
using Active_clock = stdc_steady_clock;

const std::chrono::milliseconds Smallest_Delay{200};
using Smallest_Delay = const std::chrono::milliseconds{200};
#endif

#ifdef USING_CTIME
//using Active_clock = clock_t;
constexpr double Smallest_Delay = 0.2; 
#endif 


  template <class Type>
  Type derefrence_Type(void * ponter)
  {
    return *(Type*)(ponter);
  }

///theres a problem here. thiers no way chrono is c comatable this ineed to be a time_t
extern "C"{

  struct telagram

  {
    //Active_clock::time_point  trazmission_t;
    
    double trazmission_t; 
    int sender;
    int receiver;
    double priority;
    msg_cmdz msg;
    void* Other_data;

    telagram():
     //trazmission_t(Active_clock::now()),   
      sender(-1),
      receiver(-1),
      priority(-1),
      msg(msg_cmdz::NULLCMD),
      Other_data(nullptr)
    {
       time_t tp = time(NULL); 
       trazmission_t = (double)tp; 
    }
  telagram ( time_t time, int sender, int receiver, float priority, msg_cmdz msg,
               void* data):
              trazmission_t(time),
              sender(sender),
              receiver(receiver),
              priority(priority),
              msg(msg),
              Other_data(data)
    {}
  /*
  telagram ( Active_clock::time_point time, int sender, int receiver, float priority, msg_cmdz msg,
               void* data):
              trazmission_t(trazmission_t),
              sender(sender),
              receiver(receiver),
              priority(priority),
              msg(msg),
              Other_data(data)
    {}
*/
};


 inline bool operator ==( const telagram& tela1, const telagram& tela2)
   {

#ifdef USING_CHRONO
    auto dif_time = std::chrono::duration_cast<std::chrono::milliseconds>(tela1.trazmission_t - tela2.trazmission_t);
  
#endif
     double dif_time  =  tela1.trazmission_t - tela2.trazmission_t;

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



//typedef std::chrono::steady_clock::time_point stdc_steady_clock_tp; 
// Smallest_Delay =0.20;
#endif
