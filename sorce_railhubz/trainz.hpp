//trainz.hpp

#pragma once

//sfml libz
#include <SFML/Graphics.hpp>

//myheadz
#include "Base_TSym_entity.h"
#include "Defined_train_path.h"

namespace train
{
  struct trnz_positional
  {
    extern int current_station_id;

    sf::Vector2f currentLocation;
    sf::Vector2f next_hub_location;

    double diz_next_hub;
    double diz_traveled;

    bool arrived_final = false;
    bool is_halt = false;
  };

  class trainz :  public Base_TSym_entity
  {
    protected :

      int train_id;
      sf::CircleShape cr_traingraphic;

      int tr_priority;
      int t_speed;

      trnz_positional tr_positional;
      Defined_train_path train_route;
    public :
      ~trainz();
      trainz(int& total_enty) : Base_TSym_entity(total_enty)
      {
        train_id = total_enty;
        total_enty++;
      }

      inline int get_ID()
      {
        return train_id;
      }

      inline sf::Vector2f  cur_location()
      {
          return (tr_positional.currentLocation);
      }

      void update();
      bool Handle_telagram(const telagram& tela);
      void draw(sf::RenderWindow &window);

      void hault();

      bool move(int enter_line_id);
      bool arrive_final();
      bool in_station();

      int curr_station();

};

}
