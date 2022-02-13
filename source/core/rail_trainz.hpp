//rail_trainz.hpp

#pragma once

#include <chrono>



//myheadz
#include "Base_TSym_entity.hpp"
#include "Defined_train_path.hpp"
#include "railhubz.hpp"

  using namespace std::chrono;

  class railhubz;


 

class R_linez : public Base_TSym_entity
{
  protected :
    E_ID line_id;
    sf::VertexArray rail_linez_array;
    bool acess_channels[2] = {false,false};
    double vertex_slop;
    double Acess_Drection;

  public :
    virtual ~R_linez() = default;
    R_linez() : Base_TSym_entity(){set_type(Entity_Type::R_LINEZ);}

    inline E_ID get_ID() {return line_id;}
    void update(){};
    bool Handle_telagram(const telagram& tela);
    void draw(sf::RenderWindow &window);

    void set_pos (float hub1_x,float hub1_y, float hub2_x, float hub2_y);
    void set_pos (const sf::Vector2f vecloc1,const sf::Vector2f vecloc2);

    bool can_train_enter(const sf::Vector2f& currnt_l,const  sf::Vector2f& next_l);

    inline double line__drection_status() {return Acess_Drection;}
    inline auto get_channel_stat_prt()-> bool(&)[2] {return acess_channels;}
};
