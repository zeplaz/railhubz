

#include "Defined_train_path.h"





//template<class pathed_entity>
railhubz* Defined_train_path::get_next_hub()

{
    railhubz* temp_hub_prt = train_path_stk->top();
    train_path_stk->pop();
    return(temp_hub_prt);
}

//template<class pathed_entity>
void Defined_train_path::addhubtoPath(railhubz* newrailhub)
{
    train_path_stk->push(newrailhub);
}
