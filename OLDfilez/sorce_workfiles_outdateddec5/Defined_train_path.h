
#ifndef D_TR_PATH_H
#define D_TR_PATH_H


#include <stack>
#include "railhubz.h"

//template<typename pathed_entity>
class railhubz;
class Defined_train_path

{
    //class entity_2test;

    private :

    std::stack<railhubz*>* train_path_stk;

    public :
           Defined_train_path(){};
          ~Defined_train_path(){};

     railhubz* get_next_hub();

     void addhubtoPath(railhubz* newrailhub);

};


#endif
