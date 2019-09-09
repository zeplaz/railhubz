//mathz.cpp
#include "mathz.hpp"
#include <iostream>
int main(int argc, char** argv)
{
  int x=2,y=3,x2=20,y2=12;
  double dx= 2.f ,dy=44.f,dx2 = 30.f,dy2 = 66.f;

  std::cout <<"ditancezqrdz:" << mathz::distance_sqrd(dx,dx2,dy,dy2) << '\n';
  std::cout << "ditanceeqluidz:" << mathz::distance_eulidean(dx,dx2,dy,dy2) <<'\n';
  std::cout << "disz_mahattan:" << mathz::distance_manhattan(dx,dx2,dy,dy2) << '\n';


  std::cout <<"intditancezqrdz:" << mathz::distance_sqrd(x,x2,y,y2) << '\n';
  std::cout << "intditanceeqluidz:" << mathz::distance_eulidean(x,x2,y,y2) <<'\n';
  std::cout << "intdisz_mahattan:" << mathz::distance_manhattan(x,x2,y,y2) << '\n';
  return 0;
}
