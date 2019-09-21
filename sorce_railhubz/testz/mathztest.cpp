//mathz.cpp
#include "mathz.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <chrono>

int main(int argc, char** argv)
{
  using namespace std::chrono;
  steady_clock::time_point entry_time;
  int x=2,y=3,x2=20,y2=12;
  double dx= 2.f ,dy=44.f,dx2 = 30.f,dy2 = 66.f;
  entry_time = steady_clock::now();

  std::cout <<"ditancezqrdz:" << mathz::dot_abs_sqrd(dx,dx2,dy,dy2) << '\n';
  std::cout << "ditanceeqluidz:" << mathz::distance_euclidean(dx,dx2,dy,dy2) <<'\n';
  std::cout << "disz_mahattan:" << mathz::distance_manhattan(dx,dx2,dy,dy2) << '\n';


  std::cout <<"intditancezqrdz:" << mathz::dot_abs_sqrd(x,x2,y,y2) << '\n';
  std::cout << "intditanceeqluidz:" << mathz::distance_euclidean(x,x2,y,y2) <<'\n';
  std::cout << "intdisz_mahattan:" << mathz::distance_manhattan(x,x2,y,y2) << '\n';

sf::Vector2f test_vec_1;
sf::Vector2f test_vec_2;
test_vec_1.x =3.3;
test_vec_1.y =5.3;

test_vec_2.x =712.66;
test_vec_2.y =510.34;

sf::Vector2f normized = mathz::normalize_and_Drectional_vector(100.f,test_vec_2, 20.f,14.f);

std::cout <<"dotsfml:" << mathz::dot(test_vec_1,test_vec_2) << '\n';
std::cout <<"normilz x:" << normized.x << " y:"  <<  normized.y << '\n';

steady_clock::time_point othert = steady_clock::now();
duration<double> movmentDuration = othert-entry_time;

std::cout <<"timescanz" << movmentDuration.count() <<'\n';
  return 0;
}
