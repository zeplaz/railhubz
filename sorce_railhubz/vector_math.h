//vector_math.h

#pragma once

#include <math.h>
#include <SFML/System/Vector2.hpp>
//typedef sf::Vector2f vector2d;

class vector_math {

public:

    static  float dot (const sf::Vector2f& vec1, const sf::Vector2f& vec2)
    {
    return vec1.x*vec2.x + vec1.y*vec2.y;

    }

    static double Distance_cal(sf::Vector2f& vec1,sf::Vector2f& vec2)
     {
            double xL= (vec2.x-vec1.x)*(vec2.x-vec1.x);
            double yL= (vec2.y-vec1.y)*(vec2.y-vec1.y);

         return  (sqrt(xL/yL));
     }

static    double Drectional_dxr(double L,sf::Vector2f C_vec1,sf::Vector2f D_vec2)
    {
        double S;
        double mx =D_vec2.x-C_vec1.x;
        double my= D_vec2.x-C_vec1.x;
        S = (mx)/(my);


        return (S*(mx/L)+(mx/L)/S);
    }

};



static sf::Vector2f normalize_and_Drectional_vector(float len,sf::Vector2f C_vec1,sf::Vector2f D_vec2){
    sf::Vector2f    temp_move_vec;
    float dx = D_vec2.x-C_vec1.x;
    float dy = D_vec2.x-C_vec1.y;

     dx /= len;
     dy /= len;
     temp_move_vec.x =dx;
     temp_move_vec.y= dy;

return (temp_move_vec);

};



    /*
        void rotate (sf::Vector2f& res, const sf::Vector2f& v, float angle)
        {
            const float rad = DEG2RAD * angle;
            const float sin0 = sin(rad);
            const float cos0 = cos(rad);
            res.x = v.x * cos0 + v.y * -sin0;
            res.y = v.x * sin0 + v.y * cos0;
        }

        sf::Vector2f :rotate (sf::Vector2f& v, float angle)
        {
           Vec2 res;
           rotate(res, v, angle);
           return res;
        }
    */
