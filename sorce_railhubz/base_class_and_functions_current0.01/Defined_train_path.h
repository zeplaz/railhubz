
#ifndef D_TR_PATH_H
#define D_TR_PATH_H


#include <stack>

#include "enity_2test.h"
class enity_2test;
//template<class pathed_entity>
class Defined_train_path

{


    private :

    std::stack<enity_2test*> train_path_stk;

    public :
           Defined_train_path(){}
          ~Defined_train_path(){}

     enity_2test* get_next_hub();

     void addhubtoPath(enity_2test* newrailhub);
     bool is_empty();


};


#endif
