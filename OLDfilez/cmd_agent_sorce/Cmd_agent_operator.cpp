

#include Cmd_agent_operator

class R_lines;
//class trainz;
//class railhubz;
class Sym_Map;

    void Cmd_agent_operator::dispatchtrain()
    {  trainz* temp_train;

        for (i=0; i < trainpriorty_master_que.size(); i++)
        {
            priority_train_paket = trainpriorty_master_que.top();

          temp_train = get_entity_via_id(priority_train_paket.train_id);
            temp_train->move(priority_train_paket.line_id);

            trainpriorty_master_que.pop();

        }
    }

    void Cmd_agent_operator::scan_hubs_for_dispatch()
        {
      std::vector<int>* current_dispatch_hublist = Sym_map->hublist();
      sf::Vector2f* train_Next_hub_vec;
      sf::Vector2f*  train_currnt_loc_vec;
      int temp_hub_id;
      int temp_train_id;
      int temp_train_id2;

      trainz* prt_train;
      trainz* prt_train2;
      R_linez* Prt_temp_line;
      railhubz* temp_hub;
     std::vector<R_linez*>  tempLine_vector;
     bool out_crt;
      for (i=0; i < current_dispatch_hublist->size(); i++)
        {
            temp_hub_id = current_dispatch_hublist->at(i);
            temp_hub = get_hub_via_id(temp_hub_id);

            temp_train_id =temp_hub->return_highest_prioty_train_id());
            prt_train = get_entity_via_id(temp_train_id);

            tempLine_vector = temp_hub->return_ptr_lineconections();

                for (int i = 0; i<tempLine_vector->size(); i++ )
                {  Prt_temp_line = tempLine_vector[i];

                    *train_Next_hub_vec  = prt_train->Nexthub->getLocation();
                    train_currnt_loc_vec = prt_train->get_prt_location_train();

                    if(Prt_temp_line->out_post->getLocation() ==  *train_Next_hub_vec
                    || Prt_temp_line->hub_creator->getLocation() == *train_Next_hub_vec)
                    {
                        if (Prt_temp_line->can_add_train_tochannel(train_currnt_loc_vec,train_Next_hub_vec))
                        {
                            if(Prt_temp_line->hub_creator == temp_hub)
                                {
                                out_crt = false;
                                temp_train_id2 = Prt_temp_line->outpost_hub->return_highest_prioty_train_id();
                                }
                            else
                                {
                                out_crt = true;
                                temp_train_id2 = Prt_temp_line->creator_hub->return_highest_prioty_train_id();
                                }

                            prt_train2 = get_entity_via_id(temp_train_id2);

                            if (prt_train2->esclatcatator_priority > prt_train1->esclatcatator_priority)
                                        {
                                            priority_train_paket.priority = prt_train2-> esclatcatator_priority;
                                            priority_train_paket.train_id = temp_train_id2;
                                            priority_train_paket.line_id = Prt_temp_line->line_id;

                                            trainpriorty_master_que.push(priority_train_paket);


                                            if (out_crt == true)
                                            {
                                            rt_temp_line->creator_hub->put_priotytrain_on_line();
                                            }
                                            else
                                            {
                                                rt_temp_line->outpost_hub->put_priotytrain_on_line();
                                            }
                                        }
                                else    {
                                        priority_train_paket.priority = prt_train-> esclatcatator_priority;
                                        priority_train_paket.train_id = temp_train_id;
                                        priority_train_paket.line_id = Prt_temp_line->line_id;

                                        trainpriorty_master_que.push(temp_train_id);
                                        temp_hub->put_priotytrain_on_line();
                                        }

                        }
                    }
                }
            }
    }


/* create railhubz
sherbyz
tro
mtl
Qcity
otta

*/
        void Cmd_agent_operator::create_hubz(int location)
        {

         switch (hubNamez.location)

         {

         case Sherbrooke :

             float x = 45.4042f;
             float y = 71.8923f;

             railhubz* sherbyz = new railhubz(cmd_time_start,sf:Vector2f(x,y),hubz_count);
             Sym_map->Register_hubz(sherbyz);
                printf("sherbyz_ID: %s \n",sherbyz->id);
             break;

         case Toronto :

             float x = 43.6532f;
             float y = 79.3832f;

             railhubz* tro = new railhubz(cmd_time_start,sf:Vector2f(x,y),hubz_count);
             Sym_map->Register_hubz(tro);
              printf("Toronto_ID: %s \n",tro->id);
             break;
         case Montreal :

             float x = 45.5088f;
             float y = 73.552f;

             railhubz* mtl = new railhubz(cmd_time_start,sf:Vector2f(x,y),hubz_count);
             Sym_map->Register_hubz(mtl);
             printf("Montreal_ID: %s \n",mtl->id);

             break;
         case QubecCity :

             float x = 46.8257f;
             float y = 71.2349f;

             railhubz* Qcity = new railhubz(cmd_time_start,sf:Vector2f(x,y),hubz_count);
             Sym_map->Register_hubz(Qcity);
             printf("Qcity_ID: %s \n",Qcity->id);

             break;

         case Ottowa :

             float x = 75.69f;
             float y = 45.421f;

             railhubz* otta = new railhubz(cmd_time_start,sf:Vector2f(x,y),hubz_count);
             Sym_map->Register_hubz(otta);
             printf("OttAWA_ID: %s \n",otta->id);

             break;

             default :
                 { printf("unknown hub name, enter cordnets:...possblz\n");
                 float tempy;
                 float tempx;

                    printf("inoutxfloat:\n")
                    std::cin >> tempx;
                    printf("inoutyfloat:\n")
                    std::cin >> tempy;
                    railhubz* temp = new railhubz(cmd_time_start,sf:Vector2f(tempx,tempy),hubz_count);
                    Sym_map->Register_hubz(temp);
                    printf("newHub_ID: %s \n",temp->id);
             break;
                    }
            }
        }

        Cmd_agent_operator::establish_link();
        {
        //
            R_linez*Sherb_mtl =  new R_linez(mtl, otw, enity_count);
            R_linez* mtl_ottaw = new R_linez(mtl, otw, enity_count);
            R_linez* otaw_Toronto = new R_linez(Toronto, otw, enity_count);

            sym_manger->Register_entity(Sherb_mtl);
            sym_manger->Register_entity(mtl_ottaw);
            sym_manger->Register_entity(otaw_Toronto);

        }





        void Cmd_agent_operator::create_paths();
        {

        Defined_train_path sher_tro;
        sher_tro.addhubtoPath(mtl);
        sher_tro.addhubtoPath(otto);
        sher_tro.addhubtoPath(tro);

        Defined_train_path tor_sher;
        tor_sher.addhubtoPath(otto);
        tor_sher.addhubtoPath(mtl);
        tor_sher.addhubtoPath(sherbyz);

        Defined_train_path tor_mtl;
        tor_mtl.addhubtoPath(otto);
        tor_mtl.addhubtoPath(mtl);

        Defined_train_path Qcity_sher;
        Qcity_sher.addhubtoPath(mtl);
        Qcity_sher.addhubtoPath(sherbyz);

        Defined_train_path sherbyz_Qcity;
        sherbyz_Qcity.addhubtoPath(mtl);
        sherbyz_Qcity.addhubtoPath(Qcity)

        Defined_train_path Qcity_tro;
        Qcity_tro.addhubtoPath(mtl);
        Qcity_tro.addhubtoPath(otto);
        Qcity_tro.addhubtoPath(tro);


        }


        Cmd_agent_operator::create_trainz()
                {


                            temp_train.load_data(priorty,speed,);


     trainz* train_1 = new trainz(enity_count,sherbyz,tro);
     trainz* train_2 = new trainz(enity_count,sherbyz,mtl);
      trainz* train_3 = new trainz(enity_count,sherbyz,tro);
       trainz* train_4 = new trainz(enity_count,Qcity,tro);
        trainz* train_5 = new trainz(enity_count,sherbyz,tro);
         trainz* train_6 = new trainz(enity_count,tro,mtl);
          trainz* train_7 = new trainz(enity_count,tro,sherbyz);
        trainz* train_8 = new trainz(enity_count,sherbyz,mtl);
      trainz* train_9 = new trainz(enity_count,sherbyz,tro);
       trainz* train_10 = new trainz(enity_count,mtl,otta);

    Sym_map->Register_entity(train_1);
    Sym_map->Register_entity(train_2);
    Sym_map->Register_entity(train_3);
    Sym_map->Register_entity(train_4);
    Sym_map->Register_entity(train_5);
    Sym_map->Register_entity(train_6);
    Sym_map->Register_entity(train_7);
    Sym_map->Register_entity(train_8);
    Sym_map->Register_entity(train_9);
    Sym_map->Register_entity(train_10);
        train_count+=10;

        train_list.push(train_1->ID());
        train_list.push(train_2->ID());
        train_list.push(train_3->ID());
        train_list.push(train_4->ID());
        train_list.push(train_5->ID());
        train_list.push(train_6->ID());
        train_list.push(train_7->ID());
        train_list.push(train_8->ID());
        train_list.push(train_9->ID());
        train_list.push(train_10->ID());
                    }
                }

            void Cmd_agent_operator::check_cleanup_train_enityz_arrival()
                {
                    trainz* temptrain;

                    for (i=0; i<train_list.size(); i++ )
                    {
                        temptrain = sym_manger->get_entity_via_id(int train_list[i]);

                        if (temptrain->arived_final())
                            {temptrain->removeenity();
                            numberofarrvails++;
                            }
                    }
                }
