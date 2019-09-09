#pragma once

#include "msg_cmdz.h"
#include "msg_dispatcher.h"
//#include "vector_math.h"
//#include "priorty_Objc_que.h"

#include "Base_TSym_entity.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "enity_2test.h"
#include "Defined_train_path.h"

#include <time.h>
#include <iostream>
//#include <R_linez.h>

struct telagram;
class Defined_train_path;
class enity_2test;


//class vector_math;

//typedef Defined_train_path paths_for_train;
//template <class Fw_def_trainpath = Defined_train_path>

class enity_1test: public Base_TSym_entity
{
private :



   int entity_1_id;
   time_t train_enity_cra;


       int speed;

       double train_x;
       double train_y;

    enity_2test* start_station;
    enity_2test* end_station;
    int currnet_station_id=-1;

    sf::Vector2f currentLocation;
    sf::Vector2f next_hub_location;

   //Fw_def_trainpath trainrout;

   double distance_toNext_from_last;
   double distance_traveld=0;
    bool arived_f = false;
    double active_line;
    double  dre_dxr;
    bool is_halt = true;

    int tr_priority =-1;
    //R_linez* currentline;

    double Drectional_dxr(double L,sf::Vector2f C_vec1,sf::Vector2f D_vec2);


public :
    enity_2test* next_station;
    double esclatcatator_priority;
   void load_data(double priority, float spd, Defined_train_path* path_take);

   void update();

   bool Handle_telagram(const telagram& tela);


  int get_id();

  double  get_train_priority() const;

  sf::Vector2f  cur_location()
  {
      return (currentLocation);
  }

  int curr_station()
  {
      return currnet_station_id;
  }

  void initialize(time_t c_time, enity_2test* start_enity, enity_2test* des_entity);

  void draw(sf::RenderWindow &window);

double  dot ( sf::Vector2f vec1,  sf::Vector2f vec2);

  ~enity_1test();

  enity_1test (time_t cur_time, enity_2test* start, enity_2test* destiation, int& total_enty): Base_TSym_entity(total_enty)
    {
        entity_1_id = total_enty;
        total_enty++;
    //    Defined_train_path trainrout;
      //  printf("enitycount: %s\n", total_enty );
        initialize(cur_time, start,destiation);
    }

  sf::Vector2f normalize_and_Drectional_vector(double len,sf::Vector2f C_vec1,double x2, double y2);


    void hault();

    void move(int enter_line_id);

    bool  arived_final();


 bool in_station();



  };

//typedef enity_1test<> enity_1test;
