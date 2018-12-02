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

struct telagram;
class Defined_train_path;
class enity_2test;
//class vector_math;
class enity_1test: public Base_TSym_entity
{
protected :


    sf::CircleShape cr_traingraphic;

   int entity_1_id;
   time_t train_enity_cra;

       double esclatcatator_priority;
       int speed;


    enity_2test* start_station;
    enity_2test* end_station;
    enity_2test* next_station;

    sf::Vector2f currentLocation;
    sf::Vector2f next_hub_location;

   Defined_train_path* trainrout;

   double distance_toNext_from_last;
   float distance_traveld=0;
    bool arived = false;

public :
   void load_data(double priority, int spd, Defined_train_path* path_take);

   void update();

   bool Handle_telagram(const telagram& tela);


  int get_id();

  void initialize(time_t c_time, enity_2test* start_enity, enity_2test* des_entity);

  void draw(sf::RenderWindow &window);

double  dot ( sf::Vector2f vec1,  sf::Vector2f vec2);

  ~enity_1test();

  enity_1test (time_t cur_time, enity_2test* start, enity_2test* destiation, int& total_enty): Base_TSym_entity(total_enty)
  {
      entity_1_id = total_enty;
      total_enty++;
      initialize(cur_time, start,destiation);
  }
sf::Vector2f normalize_and_Drectional_vector(double len,sf::Vector2f C_vec1,sf::Vector2f D_vec2);
  };
