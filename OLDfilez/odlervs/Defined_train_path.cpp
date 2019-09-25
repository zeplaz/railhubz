

#include "Defined_train_path.h"



Defined_train_path::Defined_train_path(){};
Defined_train_path::~Defined_train_path(){};


railhubz* Defined_train_path::get_next_hub()

{
    pathed_entity* temp_hub_prt = train_path_stk->top();
    train_path_stk->pop();
    return(temp_hub_prt);
}

void Defined_train_path::addhubtoPath(pathed_entity* newrailhub)
{
    train_path_stk->push(newrailhub);
}
