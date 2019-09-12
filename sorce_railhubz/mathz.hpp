
//mathz.hpp
#include <cmath>

namespace mathz
 {
   template <typename Type>
   Type dot_abs_sqrd(Type x1,Type y1, Type x2, Type y2)
   {
     return sqrt(abs(x1*x2)+abs(y1*y2));
   }

   template <typename Type>
   Type distance_euclidean(Type x1,Type y1, Type x2, Type y2)
   {
     return sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
   }

   template <typename Type>
   Type distance_manhattan(Type x1,Type y1, Type x2, Type y2)
   {
     return abs(x1-x2)+abs(y1-y2);
   }

   template<typename Type>
   double dot(Type vec1,  Type vec2)
   {return ((vec1.x*vec2.x) + (vec1.y*vec2.y));}

   template<typename Type>
   Type dot( Type x, Type x2, Type y, Type y2)
   {return ((x*x2) + (y*y2));}

   template <typename T> float get_sign(T val) {
       return (T(0) < val) - (val < T(0));
   }

   template<typename Type>
   double Drectional_dxr(double L,Type C_vec1,Type D_vec2)
    {
      double S;
      double mx = D_vec2.x-C_vec1.x;
      double my = D_vec2.x-C_vec1.x;
    //  std::cout << '\n' << "mx: " << mx << "my" << my << '\n';

      if (mx==my)
       {
        //printf("prereutn mx==my\n");
        return ((mx*L)*(my*L));
        }
       if (mx!= my)
        {
          S = (mx)/(my);
          //printf("in drx3\n");
          return (S*(mx/L)+(mx/L)/S);
        }
      }


  /* template<typename Type,class r_type>
   r_type normalize_and_Drectional_vector(double len, Type x, Type y, double x2, double y2)
   {
     r_type temp_move_vec;

     double x1 =(double) x;
     double y1 =(double) y;

     double dx = abs(x2-x1);
     double dy = abs(y2-y1);
 //std::cout << "normalz info:" << dy <<" dx" << dx <<std::endl;
      dx /= len;
      dy /= len;
     // std::cout << "normalz post deived:" << dy <<" dx" << dx <<std::endl;

      temp_move_vec.x =(float) dx;
      temp_move_vec.y= (float) dy;
     return temp_move_vec;
   }*/

   template<class r_type>
   r_type normalize_and_Drectional_vector(double len, r_type vec, double x2, double y2)
   {
     r_type temp_move_vec;

     double x1 =(double) vec.x;
     double y1 =(double) vec.y;

     double dx = abs(x2-x1);
     double dy = abs(y2-y1);
 //std::cout << "normalz info:" << dy <<" dx" << dx <<std::endl;
      dx /= len;
      dy /= len;
     // std::cout << "normalz post deived:" << dy <<" dx" << dx <<std::endl;

      temp_move_vec.x =(float) dx;
      temp_move_vec.y= (float) dy;
     return temp_move_vec;
   }

   template<typename Type>
   Type slope(Type x1, Type x2, Type y1, Type y2)
   {
     return (y1-y2)/(x1-x2);
   }

 }

 /*  template<typename Type, template<typename> class varclass>
   class calz
   {
     varclass<Type> mathrz;
   };
   */
