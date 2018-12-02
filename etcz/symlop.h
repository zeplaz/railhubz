

#ifndef SYMLOP_H
#define SYMLOP_H

#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "States/StateBase.h"

class symloop

{
public:
    symlop()
    time_t current_t;
    clock_t Orgin_t;

    template <typename T, typename... Args>

    void pushState(Args&&... args);
    void popState ();

    private :

        void handleEvents();
        void tryPop_st();

        StateBase& getCurrentState;

        sf::RenderWindow PRIM_window;

std::vector<std::unique_ptr<StateBase> sym_states;

        bool Sym_shouldPop = false;
};



template <typename T, typename... Args>
void symlop::pushState()
{


}

#endif //


//symlop.cpp

#include "symlop.h"


symlop::symlop()
: PRIM_window ((1280,720), "title")
{

}

symlop::run()
{
 constexpr unsigned TPS =60;
 const sf::Time TPU = sf::seconds(1.0f/float(TPS));
 unsigned ticks =0;


clock_t run_start_t = clock();

//sf::Clock run_clock;
//sf::Time last_chk_time
//sf::Time elapsed;


{ while (PRIM_window.isopen() && !Sym_states.empty())
auto& deltatime = clock();
 auto& curr_state. = getCurrentState();

curr_state.handleInput();
curr_state.update(deltatime);


    PRIM_window.clear();

    state.render(PRIM_window);
    PRIM_window.display();

    handleEvents();
    tryPop_st();

}
}



void symlop::tryPop_st()
{
    if (Sym_shouldPop)
    {Sym_states.push_back();
}
}

void symlop::handleEvents()
{
    sf::Event Hand_e;
    while (PRIM_window.pollEvent(Hand_e))
    {
        getCurrentState().handleEvent(Hand_e);

            switch (Hand_e.type)
            {
                case sf::Event::Close;
                    PRIM_window.close();
                    break;

                default: break;

            }
     }
}


 void symlop::popState()
 {
     Sym_shouldPop = true;

 }

Vrt_baseState& symlop::getCurrentState()
{
return *Sym_states.back();

}
