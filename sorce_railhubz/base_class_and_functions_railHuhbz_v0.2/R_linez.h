// R_linez.h

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>

#include "enity_2test.h"
#include "Base_TSym_entity.h"

//#include "railhubz.h"

#include "msg_cmdz.h"
#include "msg_dispatcher.h"
//#include "vector_math.h"

#include <time.h>

//class railhubz;
class enity_2test;
struct telagram;


template <typename T> float sign(T val) {
    return (T(0) < val) - (val < T(0));
}

class R_linez : public Base_TSym_entity

{

protected:
    	sf::VertexArray rail_linez_array;


                                float RL_x1  =0.f;
                                float RL_y1 =0.f;
                                float RL_x2  =0.f;
                                float RL_y2 =0.f;

	double Acess_Drection;
	bool *AcessArray_channels= new  bool[2] {false,false};
    int line_id;
	//railhubz *rOrign_Station;
	//railhubz *rDestination_station;


        double Drectional_dxr(double L,sf::Vector2f C_vec1,sf::Vector2f D_vec2)
    {     printf("in Drectional_dxr\n");

        double S;
        double mx =D_vec2.x-C_vec1.x;
        double my= D_vec2.x-C_vec1.x;
        S = (mx)/(my);


        return (S*(mx/L)+(mx/L)/S);
    }


    double Distance_cal(sf::Vector2f& vec1,sf::Vector2f& vec2)
    {
        printf("in distanc cal\n");
           double xL= (vec2.x-vec1.x)*(vec2.x-vec1.x);
           double yL= (vec2.y-vec1.y)*(vec2.y-vec1.y);

        return  (sqrt(abs(xL/yL)));
    }

public:


    enity_2test *hub_Orign;
    enity_2test *out_post;

    double vertex_slop;

    void initialize(enity_2test* hub_1, enity_2test* hub_2);

	R_linez( enity_2test* hub_1,  enity_2test* hub_2,
		    int& total_TS_entityz): Base_TSym_entity(total_TS_entityz)


{
    line_id = total_TS_entityz+1;
    total_TS_entityz++;

    initialize(hub_1,hub_2);

}


    ~R_linez(){};

    int get_id(){ return line_id;}

	void update(){};

	bool Handle_telagram(const telagram& tela);

	void draw(sf::RenderWindow &window);

	double  line__drection_status();

	bool can_add_train_tochannel(sf::Vector2f currnt_l, sf::Vector2f next_l);


};

















//
