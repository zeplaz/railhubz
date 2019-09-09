#include "Defined_train_path.h"

railhubz* Defined_train_path::get_next_hub()
  {
   if (!train_path_stk.empty())
   {
     railhubz* temp_hub_prt = train_path_stk.top();
     train_path_stk.pop();
     printf("you arein getnexthub_definePath\n");
     return(temp_hub_prt);
    }
    else
    {
     printf("you arein else requet emptystack error\n");
     return nullptr;
    }
   }

void Defined_train_path::addhubtoPath(enity_2test* newrailhub)
  {
   train_path_stk.push(newrailhub);
  }

bool Defined_train_path::is_empty()
  {
   return (train_path_stk.empty());
  }
