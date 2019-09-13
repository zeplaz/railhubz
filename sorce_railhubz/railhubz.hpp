
#pragma once

//sdlib
#include <vector>
#include <queue>
//sfml libz
#include <SFML/Graphics.hpp>
//mylibz
#include "rail_trainz.hpp"

class R_linez;
class trainz;

 class railhubz
  {
    protected :
      inline static size_t next_hub_id = 0;
      size_t hub_id;
      sf::CircleShape cr_hubgraphic;
      sf::Vector2f hub_location;
      std::vector<R_linez*> line_connections;
      std::priority_queue<trainz*> train_que;
    public :
      railhubz(sf::Vector2f hub_l);
      ~railhubz() = default;
      inline size_t get_ID() const
      {return hub_id;}
      inline size_t get_next_id()
      {
        return next_hub_id;
      }
      sf::Vector2f get_location() const;
      void draw(sf::RenderWindow &window);
      void add_train_toque(trainz* tr_prt);
      void add_R_line(R_linez* r_lin_prt);
      void exit_train();
      trainz* rtn_priority_train();
      auto line_connect_ref() -> std::vector<R_linez*>(&);
  };
