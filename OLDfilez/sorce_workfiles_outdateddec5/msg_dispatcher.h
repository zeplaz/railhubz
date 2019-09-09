//msg_dispatcher.h

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
#include "telagram.h"
                    #include <chrono>
    #include "Base_TSym_entity.h"
    #include <time.h>

                typedef std::chrono::high_resolution_clock Clock;

class Base_TSym_entity;

const double send_zero_t = 0.0;
const int no_info = 0;
const int void_id_sender =-1;


#define tranzmitor msg_dispatcher::instance()


class msg_dispatcher
{
    private:

        std::set<telagram> dispatch_time_que;

        void call_receiver_transmit(Base_TSym_entity* prt_receiver,
                                    const telagram& tela);

        msg_dispatcher(){}

        msg_dispatcher(const msg_dispatcher&);
        msg_dispatcher& operator =(const msg_dispatcher&);

    public:

        static msg_dispatcher* instance();

        void trazmit_telagram( double time, int sender,
                        int reciver, float priority, int msg, double other_data);

        void trazmit_delayed_telagram();


};
