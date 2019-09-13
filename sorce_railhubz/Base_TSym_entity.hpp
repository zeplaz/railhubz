
//Base_TSym_entity.h

#ifndef ENTITY_H
#define ENTITY_H

//#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>
#include "telagram.h"

class Base_TSym_entity

{
  private:

  int be_id;
  inline static int be_NextValidID = 0;

  //testz the id.
  void set_id(int& val);

public :

 Base_TSym_entity(int& id_in);


virtual ~Base_TSym_entity(){};

virtual void update() = 0;

virtual  bool Handle_telagram(const telagram& tela) {return false;}

//virtual void draw(sf::RenderWindow &window)= 0;

inline int get_ID() const {return be_id;}
//inline int
inline static int get_next_id() { return be_NextValidID;}
};

#endif
