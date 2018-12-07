


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



    Cmd_agent_operator::create_trainz(int numtraincreat, int priorty, int speed,
                                        int beinghub ,int endhub)
            {
                int = numoftrains;

                for (i=0; i < numoftrains; i++ )

                {   trainz* temp_train = new trainz(enity_count,train_count,orginhub,destion);
                    temp_train.load_data(priorty,speed);
                    Sym_map->Register_entity(temp_train);
                    train_list.push(temp_train->ID());


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


        Cmd_agent_operator::establish_link();
        {
        //
            R_linez*Sherb_mtl =  new R_linez(mtl, otw, total_linez);
            R_linez* mtl_ottaw = new R_linez(mtl, otw, total_linez);
            R_linez* otaw_Toronto = new R_linez(Toronto, otw, total_linez);


        }

void Cmd_agent_operator::create_paths();
{



}



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
