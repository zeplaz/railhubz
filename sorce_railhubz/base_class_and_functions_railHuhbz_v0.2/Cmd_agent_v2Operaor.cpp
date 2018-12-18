

#include "Cmd_agent_v2Operaor.h"






void Cmd_agent_v2Operaor::dispatchtrain()
{
    enity_1test* temp_train;

    if (!trainpriorty_master_que.empty())
        printf("dispatchtrain1\n");
     {
        for (int i=0; i < trainpriorty_master_que.size(); i++)
        {
            priority_train_paket = trainpriorty_master_que.top();
            printf("dispatchtrain2\n");
            temp_train = dynamic_cast<enity_1test*> (sym_manger->get_entity_via_id(priority_train_paket.train_id));
                printf("dispatchtrain3\n");
            std::cout << "premove:lineid" << priority_train_paket.line_id << "move for train id:"<< priority_train_paket.train_id << std::endl;
            temp_train->move(priority_train_paket.line_id);

                printf("dispatchtrain4\n");
            trainpriorty_master_que.pop();
            //trainpriorty_master_que.pop();

        }
    }

}


Cmd_agent_v2Operaor::~Cmd_agent_v2Operaor(){
    printf("agentdown!\n");
}




void Cmd_agent_v2Operaor::scan_hubs_for_dispatch()
{

      std::vector<int>* current_dispatch_hublist = sym_manger->hublist();
      sf::Vector2f train_Next_hub_vec;
      sf::Vector2f  train_currnt_loc_vec;
      int temp_hub_id;
      int temp_train_id;
      int temp_train_id2 =-1;

      enity_1test* prt_train;
      enity_1test* prt_train2;
      R_linez* Prt_temp_line;
      enity_2test* temp_hub;
     std::vector<R_linez*>  tempLine_vector;

     //printf("scan ilization\n");


      for (int i=0; i < current_dispatch_hublist->size(); i++)
        {       //    printf("forloop dispachhublist1...\n");
            temp_hub_id = current_dispatch_hublist->at(i);
            temp_hub = dynamic_cast<enity_2test*> (sym_manger->get_entity_via_id(temp_hub_id));

                    //     curr_station()

              if (temp_hub->are_train_waiting())
        {  // printf("forloop dispachhublist2...\n");
            temp_train_id =temp_hub->return_highest_prioty_train_id();

            prt_train = dynamic_cast<enity_1test*> (sym_manger->get_entity_via_id(temp_train_id));

            tempLine_vector = temp_hub->return_prt_lineconections();


                for (int i = 0; i<tempLine_vector.size(); i++ )

                {//printf("forloop dispachhublist3...\n");
                    Prt_temp_line = tempLine_vector[i];

                    train_Next_hub_vec  = prt_train->next_station->get_location();
                    train_currnt_loc_vec = prt_train->cur_location();
                //    printf("forloop dispachhublist4...\n");

                        if(Prt_temp_line->out_post->get_location() ==  train_Next_hub_vec)
                        {       out_crt = true;

                        }

                        if (Prt_temp_line->hub_Orign->get_location() == train_Next_hub_vec)
                        {   out_crt = false;

                        }

                        if (Prt_temp_line->can_add_train_tochannel(train_currnt_loc_vec,train_Next_hub_vec))
                        {
                          printf("inside if can to chanel dispachhublist4.2...\n");
                            if(Prt_temp_line->hub_Orign == temp_hub)
                                {
                                  is_hub_out_post = false;
                                  printf("inside if can to chanel dispachhublist4.3 goingtoorgin...\n");
                                }

                            else {
                                   is_hub_out_post = true;
                                   printf("inside if can to chanel dispachhublist4.4 going_tooutpost...\n");
                                 }

                            if (Prt_temp_line->out_post->are_train_waiting() && is_hub_out_post==false )
                                {
                                    train_waiting = true;
                                    temp_train_id2 = Prt_temp_line->out_post->return_highest_prioty_train_id();
                                    printf("waiting train at other station outpost!\n");
                                }

                            if (Prt_temp_line->hub_Orign->are_train_waiting() && is_hub_out_post == true)
                                {
                                   train_waiting = true;
                                   temp_train_id2 = Prt_temp_line->hub_Orign->return_highest_prioty_train_id();
                                   printf("waiting train at other station orgin!\n");
                                }

                            if  ( train_waiting ==true)
                                {
                                  printf("train id: found:  \n");
                                  prt_train2 = dynamic_cast<enity_1test*> (sym_manger->get_entity_via_id(temp_train_id2));

                                  std::cout << "the priorty of train 2:" << prt_train2->get_id() << " "<< prt_train2->esclatcatator_priority
                                  << "the priorty of train 1: "<<  prt_train->get_id() << " :" << prt_train->esclatcatator_priority << std::endl;

                                  if (prt_train2->esclatcatator_priority > prt_train->esclatcatator_priority)
                                        {
                                            printf("forloop dispachhublist5.1...\n");
                                            priority_train_paket.priority = prt_train2->get_train_priority();
                                            priority_train_paket.train_id = temp_train_id2;
                                            priority_train_paket.line_id = Prt_temp_line->get_id();

                                            trainpriorty_master_que.push(priority_train_paket);

                                            if (is_hub_out_post == true)
                                            {
                                             Prt_temp_line->hub_Orign->put_priotytrain_on_line();
                                            }

                                            if(is_hub_out_post == false)
                                            {
                                             Prt_temp_line->out_post->put_priotytrain_on_line();
                                            }
                                         }

                                     else //if (prt_train2->esclatcatator_priority < prt_train->esclatcatator_priority)
                                      {     printf("forloop dispachhublist5.2...\n");
                                            priority_train_paket.priority = prt_train->get_train_priority();
                                            priority_train_paket.train_id = temp_train_id;
                                            priority_train_paket.line_id = Prt_temp_line->get_id();

                                            trainpriorty_master_que.push(priority_train_paket);
                                            temp_hub->put_priotytrain_on_line();
                                        }
                                    }

                                if ( train_waiting == false )
                                {
                                    printf("forloop dispachhublist5.3...\n");
                                    priority_train_paket.priority = prt_train->get_train_priority();
                                    priority_train_paket.train_id = temp_train_id;
                                    priority_train_paket.line_id = Prt_temp_line->get_id();

                                    trainpriorty_master_que.push(priority_train_paket);
                                    temp_hub->put_priotytrain_on_line();
                                }

                            }//end of check for avlable line

                        }// end scanlinez

                    }// end if about waiting trains at sation of hub for trainz
                }// end of scan of hubs

                 train_waiting = false;
}
