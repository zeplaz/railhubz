
//Base_TSym_entity.h

#ifndef ENTITY_H
#define ENTITY_H

//#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>
#include "telagram.h"

class Base_TSym_entity

{
  private:

  extern int be_id;
  static int be_NextValidID;

  //testz the id.
  void set_id(int val);

public :

 Base_TSym_entity(int be_id)
    {set_id(be_id);}

virtual ~Base_TSym_entity(){};

virtual void update() = 0;

virtual  bool Handle_telagram(const telagram& tela)= 0;

//virtual void draw(sf::RenderWindow &window)= 0;

int get_ID() const {return be_id;}

};

#endif
