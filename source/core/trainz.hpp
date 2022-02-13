 
 #ifndef RAILHUBZ_TRAINZ_HPP
 #define RAILHUBZ_TRAINZ_HPP 
 
 #include "Base_TSym_entity.hpp"
//#include "railhubz.hpp"
#include "Defined_train_path.hpp"
 
#include <memory>
 class railhubz;
 class trainz :  public Base_TSym_entity
  {
    protected :

    struct trnz_positional
    {
      int current_station_id;
      double entry_time;
      int active_line;
      sf::Vector2f currentLocation;
      sf::Vector2f next_hub_loc;
      double drex_dxr;
      double diz_next_hub;
      double diz_traveled;

      bool arrived_final = false;
      bool is_halt = false;
    };

      E_ID train_id;
      sf::CircleShape cr_traingraphic;
      float tr_priority = 1.f;
      float esclatcatator_priority;
      float t_speed=15;
      trainz::trnz_positional tr_positional;
      Defined_train_path<std::shared_ptr<railhubz>> train_route;



    public :
    railhubz* orign_station = nullptr;
    railhubz* destination_station = nullptr;
    railhubz* next_station = nullptr;

      virtual ~trainz() = default;
      trainz();
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

#endif