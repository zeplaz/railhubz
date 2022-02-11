
//Base_TSym_entity.h

#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>


//#include <SFML/Window.hpp>
#include "telagram.h"

 enum class Entity_Type: char{TRAIN='T',R_LINEZ ='R'};


class Base_TSym_entity

{ 
  public: 
  enum State
  {
    Active,
    Paused,
    Dead
  };
  private:


  int be_id;
  inline static int be_NextValidID = 0;


  void set_id(int& val);

  protected :
  Entity_Type entity_type;

  public :
  Base_TSym_entity(int& id_in);

  virtual ~Base_TSym_entity();

  void update(double dt);
  void update_compoents(double dt);

  virtual  bool Handle_telagram(const telagram& tela);

  //virtual void draw(sf::RenderWindow &window)= 0;

  inline int get_ID() const {return be_id;}
  //inline int
  inline static int get_next_id() { return be_NextValidID;}

  void set_type(Entity_Type&& char_idenity);

  const Entity_Type& get_Etype(){return entity_type;}
};

#endif
