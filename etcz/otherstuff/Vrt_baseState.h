#pragma once



class symlop;

class Vrt_baseState
{  sym_pontersymLop (&symlop)

    public :
        Vrt_baseState(symlop& symlop)
        : th_z_ptr_symlop (&symlop)
        {}
        virtual ~Vrt_baseState() = default;

        virtual void handleEvent (sf::Event e) =0;
        virtual void handleInput ()=0;
        virtual void update (sf::Time deltaTime)=0;
        virtual void render (sf::RenderTarget& renderer);

    protected :
        symlop* th_z_ptr_symlop;
}
