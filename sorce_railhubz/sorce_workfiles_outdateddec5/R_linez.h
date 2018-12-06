// R_linez.h

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>


#include "Base_TSym_entity.h"

#include "railhubz.h"

#include "msg_cmdz.h"
#include "msg_dispatcher.h"
#include "vector_math.h"

#include <time.h>

class railhubz;
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

	//railhubz *rOrign_Station;
	//railhubz *rDestination_station;

public:
    int line_id;

    railhubz *hub_Orign;
    railhubz *out_post;

    double vertex_slop;

    void initialize(railhubz* hub_1,  railhubz* hub_2,
                    int& total_TS_entityz);

	R_linez( railhubz* hub_1,  railhubz* hub_2,
		    int& total_TS_entityz): Base_TSym_entity(total_TS_entityz)


{
initialize(hub_1,hub_2,total_TS_entityz);

}


    ~R_linez(){};

	void update(){};

	bool Handle_telagram(const telagram& tela);

	void draw(sf::RenderWindow &window);

	double  line__drection_status();

	bool can_add_train_tochannel(sf::Vector2f* currnt_l, sf::Vector2f* next_l);


};














//
