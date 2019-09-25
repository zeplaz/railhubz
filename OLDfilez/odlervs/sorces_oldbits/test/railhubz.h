#ifndef RAILHUBZ_H
#define RAILHUBZ_H


#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include <time.h>
#include <vector>
//#include <queue>


class railhubz

{
protected :

time_t H_creation_t;
sf::CircleShape cr_hubgraphic;
sf::Vector2f hub_location;

float x;
float y;
    public:

    railhubz(time_t& orgin, sf::Vector2f hub_vec, int& hubz_countz);
    ~railhubz();

    int id;

    sf::Vector2f getLocation() const ;
    void draw(sf::RenderWindow &window);


};
#endif
