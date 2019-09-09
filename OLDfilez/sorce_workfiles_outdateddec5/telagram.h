//telagram.h

/*
telagram is a strucutre used currntly for the msgs dispatcher
but i could see it being used by other msgs and comuncation services. implments a opratore overloader on == and <,. for priority msg comparsons.
*/

#ifndef TELAGRAM_H
#define TELAGRAM_H

#include <math.h>
#include "msg_cmdz.h"


const double Smallest_Delay =0.20;

template <class Type>
inline Type derefrence_Type(void * ponter)
{
    return *(Type*)(ponter);
}

//std::ostream& operator<<(std::ostream& os, const Telegram& t)



struct telagram

{


double trazmission_t;
int sender;
int receiver;
int msg;
float priority;
double Other_data;

telagram():
    trazmission_t(-1),
    sender(-1),
    receiver(-1),
    priority(-1),
    msg(-1),
    Other_data(-1)
{}

telagram ( double time, int sender, int receiver, float priority, int msg,
             double data):
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
    return ( fabs(tela1.trazmission_t-tela2.trazmission_t) < Smallest_Delay) &&

              (tela1.sender == tela2.sender)        &&
              (tela1.receiver == tela2.receiver)    &&
              (tela1.msg == tela2.msg)                &&
                (tela1.priority ==tela2.priority);


}


 inline bool operator<(const telagram& tela1, const telagram& tela2)
{   if(tela1 == tela2)
        {return false;}

else {
        if (tela1.priority == -1)
            {return false;}

        if(tela2.priority == -1 )
        {return true;}

return (tela1.priority<tela2.priority);

}

}






#endif
