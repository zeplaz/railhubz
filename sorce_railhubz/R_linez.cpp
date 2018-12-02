

#include "R_linez.h"
#include <iostream>


class vector_math;
class railhubz;
                                  //(const railhubz& hub1, const railhubz& hub2, int& total_R_linez)

 void R_linez::initialize(railhubz* hub_1,  railhubz* hub_2,
      int& total_TS_entityz)
 {
      line_id = total_TS_entityz+1;
      total_TS_entityz++;

     hub_Orign = hub_1;
     out_post =  hub_2;

     rail_linez_array.setPrimitiveType(sf::Lines);
     sf::Vector2f temp1;
     temp1= hub_1->getLocation();
                                         float RL_x1 = temp1.x;
                                         float RL_y1 = temp1.y;
     sf::Vector2f temp2(hub_2->getLocation());
                                         float RL_x2 = temp2.y;
                                         float RL_y2 = temp2.y;

     vertex_slop =(RL_x1 - RL_y2)/(RL_x1-RL_x2);

                 //printf("info about temp1 posx %s posy %r vertexslop: %d \n",
                         //        x, y ,vertex_slop ); //,x,y,);
                                                     //%f y %a info about slop %s


                                 /*
                                     if (temp2 ==sf::Vector2f(200.f,100.f))
                                         {std::cout <<"true temp2;" << std::endl; }

                                     if (temp1 ==sf::Vector2f(700.f, 100.f))
                                     {std::cout <<"true temp1;" << std::endl; }
                                     */


    sf::Vertex rail_L_vertex;

     rail_linez_array.append(rail_L_vertex);
     rail_linez_array.append(rail_L_vertex);

     rail_linez_array[0].position =temp1;
     rail_linez_array[0].color = sf::Color::Red;

     rail_linez_array[1].position =temp2;
     rail_linez_array[1].color = sf::Color::Blue;

     }



 bool R_linez::Handle_telagram(const telagram& tela)
{

    switch (tela.msg)
        {

        case enter_line :
        {             //   if (tela.Other_data > 0)

                                //const  double * drectional_info_train =
                            //                (double const *)(tela.Other_data);

          Acess_Drection =+ (tela.Other_data*vertex_slop);
                                //else {Acess_Drection =- tela.Other_data;}
                    if (AcessArray_channels[0] == false)
                        {
                         AcessArray_channels[0] = true;
                        }

                    else
                        {AcessArray_channels[1] =true;}

            time_t msgcurrnt = clock();

           telagram  cmd_telamove(msgcurrnt,this->line_id,tela.sender,
                                 -1,move_cmd,0);
                                 this->Handle_telagram(cmd_telamove);

            return true;
            break;
         }


        case exit_line :

                if (AcessArray_channels[1] ==true)
                    {
                      AcessArray_channels[1] =false;

                     // const  double * drectional_info_train =
                                        //     (double const *)(tela.Other_data);

                      Acess_Drection =- (tela.Other_data*vertex_slop);
                      return true;
                      break;
                    }

                if (AcessArray_channels[1] ==false)
                    {
                     AcessArray_channels[0]=  false;
                     Acess_Drection =0;
                     return true;
                     break;
                    }


            case report_status :
                                    //can_add_train_tochannel();
                return true;
                break;

            default : return false;

    }
}


    void R_linez::draw(sf::RenderWindow &window)
    {
        window.draw(rail_linez_array);

    }


    double  R_linez::line__drection_status()
    {
        return(Acess_Drection);
    }


bool R_linez::can_add_train_tochannel(sf::Vector2f* currnt_l, sf::Vector2f* next_l)
{
    double temp_distance =  vector_math::Distance_cal(*currnt_l , *next_l);

        if (AcessArray_channels[0] == true && AcessArray_channels[1] == true)
                {
                return false;
                }

        if (AcessArray_channels[0] == false && AcessArray_channels[1] == false)
                {
                return true;
                }

        if (AcessArray_channels[0] == true && AcessArray_channels[1] == false)
            {
             if (sign(vector_math::Drectional_dxr(temp_distance,
                                                *currnt_l,*next_l)) == sign(Acess_Drection))
                {
                return true;
                }
            }

        if (AcessArray_channels[0] == false && AcessArray_channels[1] == true)
            {

             if (sign(vector_math::Drectional_dxr(temp_distance,*currnt_l,*next_l))
                            == sign(Acess_Drection))
               {
               return true;
               }
            else {
            return false;}

           }
           return false;
}
