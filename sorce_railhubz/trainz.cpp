//trainz.cpp

#include "mathz.hpp"
void trainz::draw(sf::RenderWindow &window)
  {
   window.draw(cr_traingraphic);
  }

void trainz::hault()
  {
    if (arrived_final == false)
    {
      if(train_route.is_empty() == true)
      {
        arrived_final = true;
        cr_traingraphic.setFillColor(sf::Color::Red);
      }
      else
      {
        active_line = -1;
      //  next_station->;
        next_station = train_route.get_next_hub();
        trnz_positional.next_hub_location = next_station->get_location();
        diz_next_hub = mathz::distance_eulidean(tr_positional.currentLocation.x,
                                                tr_positional.next_hub_location.x,
                                                tr_positional.currentLocation.y,
                                                tr_positional.next_hub_location.y);

            }
    }
    trnz_positional.is_halt = true;
  }
