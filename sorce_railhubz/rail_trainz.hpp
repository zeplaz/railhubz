//rail_trainz.hpp

#pragma once

#include <chrono>

//sfml libz
#include <SFML/Graphics.hpp>

//myheadz
#include "Base_TSym_entity.hpp"
#include "Defined_train_path.hpp"
#include "railhubz.hpp"

  using namespace std::chrono;

  class railhubz;

  struct trnz_positional
  {
    int current_station_id;
    steady_clock::time_point entry_time;
    int active_line;
    sf::Vector2f currentLocation;
    sf::Vector2f next_hub_loc;

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
      float tr_priority = 1.f;
      int t_speed=1;
      trnz_positional tr_positional;
      Defined_train_path<railhubz> train_route;

    public :
      ~trainz() = default;
      trainz() : Base_TSym_entity(train_id){}


      void update();
      bool Handle_telagram(const telagram& tela){};
      void draw(sf::RenderWindow &window);

      void hault();
      void move(int enter_line_id);
      //bool arrive_final();
      bool in_station();

      inline  int curr_station()
      {
        return tr_positional.current_station_id;
      }

      inline int get_ID()
      {
        return train_id;
      }

      inline sf::Vector2f  cur_location()
      {
          return (tr_positional.currentLocation);
      }

      bool operator <(const trainz& train) const {return tr_priority < train.tr_priority;}

};

class R_linez : public Base_TSym_entity
{
  protected :
    int line_id;
    sf::VertexArray rail_linez_array;
    bool acess_channels[2];// = {false,false};
    double vertex_slop;
    double Acess_Drection;

  public :
    ~R_linez() = default;
     R_linez() : Base_TSym_entity(line_id){}


    void update(){};
    bool Handle_telagram(const telagram& tela){};
    void draw(sf::RenderWindow &window);


    inline int get_ID() {return line_id;}

    void initialize (float hub1_x,float hub1_y, float hub2_x, float hub2_y);



    bool can_train_enter();

    inline double line__drection_status() {return Acess_Drection;}
    inline auto get_channel_stat_prt()-> bool(&)[2] {return acess_channels;}
};
