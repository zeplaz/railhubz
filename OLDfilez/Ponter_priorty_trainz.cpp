


#include "Ponter_priorty_trainz.h"


    bool Ponter_priorty_trainz::operator()(const enity_1test* lhs, const enity_1test* rhs) const
    {
        return lhs->get_train_priority() < rhs->get_train_priority();
    }
