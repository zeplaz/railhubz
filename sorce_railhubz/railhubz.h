#ifndef RAILHUBZ_H
#define RAILHUBZ_H


#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include <time.h>
#include <vector>
#include <queue>
//#include "Cmd_agent_operator.h"

#include "trainz.h"

#include "R_linez.h"

class trainz;
class R_linez;

class railhubz

{
protected :



time_t H_creation_t;
sf::CircleShape cr_hubgraphic;
sf::Vector2f hub_location;

                    //class Cmd_agent_operator;
std::vector<R_linez*>* line_connections;


    public:

    railhubz(time_t& orgin, sf::Vector2f hub_l, int& hubz_countz);
    ~railhubz();

    int id;

    sf::Vector2f getLocation() const ;

    void add_train_toque(trainz* traintoQues);

    void add_line_connection(R_linez* newline);

    int return_highest_prioty_train_id();

    void  put_priotytrain_on_line();

    void draw(sf::RenderWindow &window);

    std::vector<R_linez*> return_prt_lineconections()
   { return *line_connections; }

};
#endif
