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


  class trainz :  public Base_TSym_entity
  {
    protected :

    struct trnz_positional
    {
      int current_station_id;
      steady_clock::time_point entry_time;
      int active_line;
      sf::Vector2f currentLocation;
      sf::Vector2f next_hub_loc;
      double drex_dxr;
      double diz_next_hub;
      double diz_traveled;

      bool arrived_final = false;
      bool is_halt = false;
    };

      int train_id;
      sf::CircleShape cr_traingraphic;
      float tr_priority = 1.f;
      float esclatcatator_priority;
      float t_speed=15;
      trainz::trnz_positional tr_positional;
      Defined_train_path<railhubz> train_route;



    public :
    railhubz* orign_station = nullptr;
    railhubz* destination_station = nullptr;
    railhubz* next_station = nullptr;

      virtual ~trainz() = default;
      trainz() : Base_TSym_entity(train_id){set_type(Entity_Type::TRAIN);}
      trainz(trainz&& train_m) noexcept = default;
      trainz& operator = (const trainz&) = default;
      trainz& operator = (trainz&&) = default;

      void update();
      
      template<class Type>
      void set_pos_overide(Type invec)
      {
        tr_positional.currentLocation.x = invec.x;
        tr_positional.currentLocation.y  = invec.y;
        cr_traingraphic.setPosition(tr_positional.currentLocation);
      }

      void Init()
      {
        cr_traingraphic.setRadius(5.f);
        cr_traingraphic.setFillColor(sf::Color::Magenta);
      }
      bool Handle_telagram(const telagram& tela){};
      void draw(sf::RenderWindow &window);
      void set_path(const Defined_train_path<railhubz>& inpath);
      void hault();
      void move(int enter_line_id);
      bool in_station();
      bool has_arrived_final();
      void Path_Next_hub();
      inline float get_priority()
        {
          return tr_priority;
        }

        inline float get_Esk_priority()
        {
            return esclatcatator_priority;
        }

        inline void update_Esk_priority(float in)
        {
          esclatcatator_priority += in*tr_priority;
        }

        inline void re_set_Esk_priority()
        {
          esclatcatator_priority =tr_priority;
        }

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
    bool acess_channels[2] = {false,false};
    double vertex_slop;
    double Acess_Drection;

  public :
    virtual ~R_linez() = default;
    R_linez() : Base_TSym_entity(line_id){set_type(Entity_Type::R_LINEZ);}

    inline int get_ID() {return line_id;}
    void update(){};
    bool Handle_telagram(const telagram& tela);
    void draw(sf::RenderWindow &window);

    void set_pos (float hub1_x,float hub1_y, float hub2_x, float hub2_y);
    void set_pos (const sf::Vector2f vecloc1,const sf::Vector2f vecloc2);

    bool can_train_enter(const sf::Vector2f& currnt_l,const  sf::Vector2f& next_l);

    inline double line__drection_status() {return Acess_Drection;}
    inline auto get_channel_stat_prt()-> bool(&)[2] {return acess_channels;}
};
