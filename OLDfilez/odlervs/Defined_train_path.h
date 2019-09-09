
#ifndef D_TR_PATH_H
#define D_TR_PATH_H


#include <stack>


template<typename pathed_entity>
class Defined_train_path

{
    class entity_2test;

    private :

    std::stack<pathed_entity*>* train_path_stk;

    public :
           Defined_train_path();
          ~Defined_train_path();

     entity_2test* get_next_hub();

     void addhubtoPath(pathed_entity* newrailhub);

};


#endif
