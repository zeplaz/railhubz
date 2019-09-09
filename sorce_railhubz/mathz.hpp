
//mathz.hpp
#include <cmath>

namespace mathz
 {
   template <typename Type>
   Type distance_sqrd(Type x1,Type y1, Type x2, Type y2)
   {
     return sqrt(abs(x1*x2)+abs(y1*y2));
   }

   template <typename Type>
   Type distance_eulidean(Type x1,Type y1, Type x2, Type y2)
   {
     return sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
   }

   template <typename Type>
   Type distance_manhattan(Type x1,Type y1, Type x2, Type y2)
   {
     return abs(x1-x2)+abs(y1-y2);
   }

 }

 /*  template<typename Type, template<typename> class varclass>
   class calz
   {
     varclass<Type> mathrz;
   };
   */
