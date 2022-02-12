
#include "system_org.hpp"
#include "rail_trainz.hpp"


#include "Cmd_agent_v3Operaor.hpp"


#include <iostream>

  bool  train_tuple_comparor(train_on_line_priory_tuple lhs, train_on_line_priory_tuple rhs)
  {
    return std::get<2>(lhs) < std::get<2>(rhs);
  };

  bool operator<(const train_on_line_priory_tuple& tt1, const train_on_line_priory_tuple& tt2)
  {
    return std::get<2>(tt1)<std::get<2>(tt2);
  }

  bool operator>(const train_on_line_priory_tuple& tt1, const train_on_line_priory_tuple& tt2)
  {
    return std::get<2>(tt1)>std::get<2>(tt2);
  }



void Cmd_agent_operator::dispatchtrain()
{
  for (size_t i = 0; i< trainLine_que.size(); i++)
  {
    std::tuple<trainz*,R_linez*,float> temp_tuple = trainLine_que.top();
    std::get<0>(temp_tuple)->move(std::get<1>(temp_tuple)->get_ID());

      trainLine_que.pop();
  }

}


void Cmd_agent_operator::scan_hubs_for_dispatch_cadiates()
{

  railhubz* temp_hub;
  railhubz* hub_dest;
  trainz* temp_train;
  R_linez* temp_R_line;

for (auto ittr_hub = sym_manger.hubz_map.begin(); ittr_hub!=sym_manger.hubz_map.end();++ittr_hub)
  {

    std::cout << "##LOOP1 SCAN HUBZ" <<'\n';
     temp_hub = ittr_hub->second;
     temp_train = temp_hub->rtn_priority_train();
     if(temp_train != nullptr)
     {
     std::vector<R_linez*>& line_vec  = temp_hub->line_connect_ref();
     std::vector<R_linez*>& line_dest = temp_train->next_station->line_connect_ref();
     bool foundMatch= false;
     //std::vector<R_linez*>::iterator line_itter;

     for(auto it = line_vec.begin();it != line_vec.end(); ++it)
     {
       std::cout << "##loop2 SCAN HUBZ" <<'\n';
       auto line_itter = std::find(std::begin(line_dest),std::end(line_dest),*it);

       if (line_itter == std::end(line_dest))
         {
           std::cout <<"nopath found :("<<'\n';
         }

       else{
          std::cout << "##findfun SCAN HUBZ" <<'\n';
          temp_R_line= *it;
          foundMatch = true;
          break;
         }
     } if(foundMatch==true)
     {
         std::cout << "##FOUND MATCH LINE" <<'\n';
         sf::Vector2f temp_next_nub_loc = temp_train->next_station->get_location();
         sf::Vector2f temp_curr_loc = temp_train->cur_location();


         if(temp_R_line->can_train_enter(temp_curr_loc,temp_next_nub_loc))
           {
              std::cout << "##FOUND TRAIN CAN ENTTR" <<'\n';
            if(temp_R_line->line__drection_status() ==0)
            {
            std::cout<<"line is empty thus comapre with other station waiting trainz" <<'\n';
             trainz* other_train  = temp_train->next_station->rtn_priority_train();

             if(other_train->next_station == temp_hub)
             {  std::cout <<"seems other train is waiting to come here!" <<'\n';
                std::cout <<"PRIOTY tain A::"<< temp_train->get_Esk_priority() << " Priorty train other::"
                          << other_train->get_Esk_priority() << '\n';
               if(other_train->get_Esk_priority()>temp_train->get_Esk_priority())
               {
                  std::cout <<"OTHER TRAIN HIHER PRIORYZ ADDEING TO QUE" <<'\n';
                trainLine_que.push(std::make_tuple(other_train,temp_R_line,other_train->get_Esk_priority()));
               }
               else
               {
                 trainLine_que.push(std::make_tuple(temp_train,temp_R_line,temp_train->get_Esk_priority()));
               }
             }
            }
            else
            {
             trainLine_que.push(std::make_tuple(temp_train,temp_R_line,temp_train->get_Esk_priority()));
            }
          }
        }}

  }//end loop1
}
