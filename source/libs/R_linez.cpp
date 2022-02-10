//R_linez.cpp

#include "rail_trainz.hpp"
#include "mathz.hpp"
#include "msg_dispatcher.hpp"

void R_linez::draw(sf::RenderWindow &window)
 {
  window.draw(rail_linez_array);
 }

 void R_linez::set_pos (const sf::Vector2f vecloc1,const sf::Vector2f vecloc2)
 {
   sf::Vertex rail_L_vertex;
   sf::Vector2f sfvec;
   rail_linez_array.setPrimitiveType(sf::Lines);
   rail_linez_array.append(rail_L_vertex);
   rail_linez_array.append(rail_L_vertex);

   sfvec = vecloc1;
   sfvec.x +=10;
   sfvec.y +=10;
   rail_linez_array[0].position =sfvec;
   rail_linez_array[0].color = sf::Color::Red;

   sfvec =vecloc2;
   sfvec.x +=10;
   sfvec.y +=10;
   rail_linez_array[1].position =sfvec;
   rail_linez_array[1].color = sf::Color::Blue;

   vertex_slop = mathz::slope(vecloc1.x,vecloc2.x,vecloc1.y,vecloc2.y);

 }
 void R_linez::set_pos(float hub1_x,float hub1_y, float hub2_x, float hub2_y)
 {
   sf::Vertex rail_L_vertex;
   sf::Vector2f sfvec;
   rail_linez_array.setPrimitiveType(sf::Lines);
   rail_linez_array.append(rail_L_vertex);
   rail_linez_array.append(rail_L_vertex);

   sfvec.x = hub1_x;
   sfvec.y = hub1_y;
   rail_linez_array[0].position =sfvec;
   rail_linez_array[0].color = sf::Color::Red;

   sfvec.x = hub2_x;
   sfvec.y = hub2_y;
   rail_linez_array[1].position =sfvec;
   rail_linez_array[1].color = sf::Color::Blue;

   vertex_slop = mathz::slope(hub1_x,hub2_x,hub1_y,hub2_y);
 }

 bool R_linez::Handle_telagram(const telagram& tela)
  {
    double inbounddrection;

    switch (tela.msg)
    {
      case msg_cmdz::enter_line :
      {

        std::memcpy(&inbounddrection, &tela.Other_data, sizeof inbounddrection);

        Acess_Drection =+ (inbounddrection*vertex_slop);

        if (acess_channels[0] == false)
           {acess_channels[0] = true;}
        else
           {acess_channels[1] =true;}

        std::chrono::steady_clock::time_point traz_time = std::chrono::steady_clock::now();

        //tranzmitor->tranzmit(traz_time,this->line_id,tela.sender,
      //                       -1,msg_cmdz::move_cmd,nullptr);

         return true;
        break;
        }

        case msg_cmdz::exit_line :
        {
          if(acess_channels[1] == true)
          {
            acess_channels[1] = false;
            std::memcpy(&inbounddrection, &tela.Other_data, sizeof inbounddrection);
            std::cout <<"##DEBUG:::Inbounddrectionz"<<inbounddrection <<'\n' <<'\n';
            Acess_Drection =- (inbounddrection*vertex_slop);
            return true;
          break;
          }
          if(acess_channels[0] == true && acess_channels[0] == false )
          {
            acess_channels[0] = false;
            std::memcpy(&inbounddrection, &tela.Other_data, sizeof inbounddrection);
            std::cout <<"##DEBUG:::Inbounddrectionz"<<inbounddrection <<'\n' <<'\n';
            Acess_Drection =- (inbounddrection*vertex_slop);
            return true;
          break;
          }
        return false;
        break;
        }

        default : return false;
      }
   }

   bool R_linez::can_train_enter(const sf::Vector2f& currnt_l, const sf::Vector2f& next_l)
   {

     if(acess_channels[0] == true && acess_channels[1] == true)
      {
        std::cout <<"LINE IS FULL" <<'\n';
       return false;
      }

     if(acess_channels[0] == false && acess_channels[1] == false)
      {
        std::cout <<"LINE IS empty woo!" <<'\n';
       return true;
      }

     double temp_eclidDis =  mathz::distance_euclidean(currnt_l.x,currnt_l.y, next_l.x,next_l.y);

     if(acess_channels[0] == true && acess_channels[1] == false || acess_channels[0] == false && acess_channels[1] == true)
      {
        if(mathz::sign(mathz::Drectional_dxr(temp_eclidDis,currnt_l,next_l))==mathz::sign(Acess_Drection))
        {
          std::cout <<"LINE allows as same drection!" <<'\n';
          return true;
        }
        else
        { std::cout <<"LINE denyz as opposite drection!" <<'\n';
          return false;
        }
      }
      std::cout <<"something went wrong and your defulting no..."<<'\n';
      return false;
    }
