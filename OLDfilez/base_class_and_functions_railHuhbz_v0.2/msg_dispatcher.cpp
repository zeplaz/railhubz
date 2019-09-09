
                #include "msg_dispatcher.h"

                #include "Sym_Map.h"
                #include "msg_cmdz.h"


    msg_dispatcher* msg_dispatcher::instance()
        {
            printf("msg_dis_alizaed");
        static msg_dispatcher instance;
        return &instance;
        }


    void msg_dispatcher::call_receiver_transmit(Base_TSym_entity* prt_receiver,
                                                const telagram& tela)
        {
            if(!prt_receiver->Handle_telagram(tela))
            {
                printf("msg not figured /n");
            }
        }

    /*void  msg_dispatcher::trazmit_telagram(const telagram& tela)
{

    if (time<=0.0f)
         {
            printf(" dispatch of undelayed msg at: %s \n",clock());
            call_receiver_transmit(tela.reciver,tela);}


}*/


    void  msg_dispatcher::trazmit_telagram( double time, int sender,
                                            int reciver, float priority,
                                            int msg, double other_data)

    { printf("inside tramiz_tella1");
    //    Base_TSym_entity* prt_sender = sym_manger->get_entity_via_id(sender);
        Base_TSym_entity* prt_reciver = sym_manger->get_entity_via_id(reciver);

            //double currnent_t = Clock::now();
            //time_t currnent_t = clock();

            //if (prt_reciver== NULL)
             //  { printf("inproper ID, of reciver: %s \n", reciver);}

        telagram tela_prep(0,sender,reciver,  priority, msg, other_data);

            if (time<=0.0f)
                 { printf(" dispatch of undelayed msg at: %s \n",clock());
                // std::chrono::duration_cast<std::chrono::nanoseconds>(currnent_t)



                 call_receiver_transmit(prt_reciver, tela_prep);
                 }
/*
            else
            {
                tela_prep.trazmission_t+time;
                dispatch_time_que.insert(tela_prep);

                printf("msg %r has been added to que at: %s \n",
                clock());

            }*/

    }


/// delaytremzitonz

/*
void msg_dispatcher::trazmit_delayed_telagram()
{
            time_t currnent_t = clock();

     while (!dispatch_time_que.empty() &&
            (dispatch_time_que.begin()->trazmission_t <currnent_t) &&
            (dispatch_time_que.begin()->trazmission_t>0) )
    {
        const telagram& tela_q = *dispatch_time_que.begin();

        Base_TSym_entity* prt_reciver = sym_manger->get_entity_via_id(tela_q.receiver);

        printf("quedtela readto trazmit to %s \n",prt_reciver->ID() );

        call_receiver_transmit(prt_reciver, tela_q);

        dispatch_time_que.erase(dispatch_time_que.begin());
    }
}
*/
