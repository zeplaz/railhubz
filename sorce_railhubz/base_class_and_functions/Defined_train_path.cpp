



#include "Defined_train_path.h"

//Defined_train_path::Defined_train_path(){};
//Defined_train_path::~Defined_train_path() {};

enity_2test* Defined_train_path::get_next_hub()
{
    enity_2test* temp_hub_prt = train_path_stk.top();
    train_path_stk.pop();
    return(temp_hub_prt);
}

    void Defined_train_path::addhubtoPath(enity_2test* newrailhub)
    {
        train_path_stk.push(newrailhub);
    }

 bool Defined_train_path::is_empty()
 {
     train_path_stk.empty();
 }
