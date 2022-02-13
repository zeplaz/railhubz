
//Base_TSym_entity.h
#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

#include "../h_libs/id_gen.h"
#include "../h_libs/telagram.h"
#include "msg_dispatcher.hpp"

class Msg_Dispatcher; 

enum class Entity_Type: char{TRAIN='T',R_LINEZ ='R'};

class Base_TSym_entity
{
  public:
   enum class State
  {
    ACTIVE,
    HALT,
    FINSHED,
    LOST,
    DERAILED,
    UNCONECTED
  };

  protected :
  E_ID id;
  Entity_Type entity_type;
  Msg_Dispatcher* my_dispatcher = nullptr;
  State status = State::ACTIVE;

  public :
  Base_TSym_entity();

  void set_type(Entity_Type&& char_idenity);
  void update_compoents(double dt);

  const Entity_Type& get_Etype(){return entity_type;}

  virtual void update() = 0;
  //void update(double dt);

  virtual  bool Handle_telagram(const telagram& tela) =0;
  virtual void draw(sf::RenderWindow& window)= 0;

  inline E_ID get_ID()  {return id;}
  inline void set_dispatcher(Msg_Dispatcher* in_d) {my_dispatcher = in_d; }

  virtual ~Base_TSym_entity(){};

};

#endif
