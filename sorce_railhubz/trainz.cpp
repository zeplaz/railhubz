//trainz.cpp

//myheaderz
#include "rail_trainz.hpp"
#include "mathz.hpp"
#include "msg_dispatcher.hpp"

//sfml
//#include <SFML/System.hpp>


void trainz::draw(sf::RenderWindow &window)
  {
   window.draw(cr_traingraphic);
  }

bool trainz::in_station()
 {
  if (tr_positional.arrived_final == false && tr_positional.is_halt == true)
  {return true;}

  return false;
 }

 bool trainz::has_arrived_final()
 {
   if(tr_positional.arrived_final == true)
   {
     std::cout << "->Train:" << train_id<<" has arived at:"<<destination_station->get_ID() << '\n';
     return true;
   }
   return false;
 }

 void trainz::Path_Next_hub()
 {
   next_station = train_route.get_next_hub();
   tr_positional.next_hub_loc = next_station->get_location();
   tr_positional.diz_next_hub = mathz::distance_euclidean(tr_positional.currentLocation.x,
                                           tr_positional.next_hub_loc.x,
                                           tr_positional.currentLocation.y,
                                           tr_positional.next_hub_loc.y);
 }

 void trainz::hault()
  {
    if (tr_positional.arrived_final == false)
    {
      if(train_route.is_empty() == true)
      {
        tr_positional.arrived_final = true;
        cr_traingraphic.setFillColor(sf::Color::Red);
      }
      else
      {
        this->Path_Next_hub();

         tr_positional.drex_dxr = mathz::Drectional_dxr(tr_positional.diz_next_hub,
                                                tr_positional.currentLocation,
                                                tr_positional.next_hub_loc);

        std::chrono::steady_clock::time_point traz_time = std::chrono::steady_clock::now();

        std::cout <<"##DEBUG:: drex_DRX:" << tr_positional.drex_dxr <<'\n';
        tranzmitor->tranzmit(traz_time,this->get_ID(),tr_positional.active_line,-1.f,
                             msg_cmdz::exit_line,&tr_positional.drex_dxr);

        tr_positional.active_line = -1;
       }
    }
    tr_positional.is_halt = true;
  }

  void trainz::update()
  {
    if(tr_positional.arrived_final == false)
    {
     steady_clock::time_point current_t_point = steady_clock::now();
     duration<double> movmentDuration = current_t_point-tr_positional.entry_time;

     if(tr_positional.is_halt == true && tr_positional.arrived_final == false)
     {
      cr_traingraphic.setFillColor(sf::Color::Blue);
     }

     if (tr_positional.is_halt == false)
     {
      if(tr_positional.diz_traveled > tr_positional.diz_next_hub)
      {
        printf("train has traveld correct distance \n");
        tr_positional.diz_traveled = 0.f;
        hault();
      }
      else
      {
        sf::Vector2f old_vec;
        float t_velocity = (movmentDuration.count()*t_speed);
        old_vec = tr_positional.currentLocation;
        sf::Vector2f normilzec_vec = mathz::normalize_and_Drectional_vector(tr_positional.diz_next_hub,
                                                               old_vec,tr_positional.next_hub_loc.x,
                                                               tr_positional.next_hub_loc.y);
        tr_positional.currentLocation.x = normilzec_vec.x*t_velocity;
        tr_positional.currentLocation.y = normilzec_vec.y*t_velocity;

        double dist_sqrz = mathz::dot_abs_sqrd(tr_positional.currentLocation.x,
                                               tr_positional.currentLocation.y,
                                               old_vec.x,old_vec.y);

        double diz_euldz = mathz::distance_euclidean(tr_positional.currentLocation.x,
                                                   tr_positional.currentLocation.y,
                                                   old_vec.x,old_vec.y);

        tr_positional.diz_traveled =abs(tr_positional.diz_next_hub-dist_sqrz);
        cr_traingraphic.setPosition(tr_positional.currentLocation);
       }
      }
     }
    }

  void trainz::move(int enty_line_id)
  {
    printf("Train enity given move order on line: %d\n", enty_line_id);
    tr_positional.is_halt = false;
    tr_positional.entry_time = steady_clock::now();
    tr_positional.active_line = enty_line_id;
    cr_traingraphic.setFillColor(sf::Color::Magenta);

    tr_positional.drex_dxr = mathz::Drectional_dxr(tr_positional.diz_next_hub,
                                           tr_positional.currentLocation,
                                           tr_positional.next_hub_loc);

    tranzmitor->tranzmit(tr_positional.entry_time,this->get_ID(),enty_line_id,
                         -1.f,msg_cmdz::enter_line,&tr_positional.drex_dxr);

   }

   void trainz::set_path()
   {
     
   }
