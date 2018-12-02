

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>

#include  "enity_2test.h"
#include "Sym_Map.h"
#include "Defined_train_path.h"
#include "Base_TSym_entity.h"


int main ()

{
    int total_ent_count;
time_t* main_runtime_o;
 *main_runtime_o = clock();


//enity_1test takez:
/* (time_t* cur_time, int& Total_enty, sf::Vector2f(x,y),
        startlocation, endlocation)

        //entity_2_takes;
    (time_t* cur_time,int total_enty,sf::Vector2f(x,y));
*/

//create other needed obejc

float x;
float y;

x=300.f;
y=200.f;
enity_2test* tst_e1_0 = new enity_1test(main_runtime_o,sf:Vector2f(x,y),total_ent_count);

x=40.f;
y=70.f;
enity_2test* tst_e1_1 = new enity_1test(main_runtime_o,sf:Vector2f(x,y),total_ent_count);
x=30.f;
y=250.f;
enity_2test* tst_e1_2 = new enity_1test(main_runtime_o,sf:Vector2f(x,y),total_ent_count);

x=200.f;
y=10.f;
enity_2test* tst_e1_3 = new enity_1test(main_runtime_o,sf:Vector2f(x,y),total_ent_count);

x=400.f;
y=30.f;
enity_2test* tst_e1_4 = new enity_1test(main_runtime_o,sf:Vector2f(x,y),total_ent_count);


/*
enity_1test tst_e1_1();
enity_1test tst_e1_2();
enity_1test tst_e1_3();
enity_1test tst_e1_4();
*/




//inlization regisation.
int entitycount;
 //std::list<int> enity_1_id_list;
 std::list<int> enity_2_idlist;


sym_manger->Register_entity(tst_e2_0);
sym_manger->Register_entity(tst_e2_1);
sym_manger->Register_entity(tst_e2_2);
sym_manger->Register_entity(tst_e2_3);
sym_manger->Register_entity(tst_e2_4);


enity_2_id_list.push(tst_e2_0->get_id());
enity_2_id_list.push(tst_e2_1->get_id());
enity_2_id_list.push(tst_e2_2->get_id());
enity_2_id_list.push(tst_e2_3->get_id());
enity_2_id_list.push(tst_e2_4->get_id());


///

Defined_train_path* sher_tro;


sher_tro->addhubtoPath(tst_e2_0);
sher_tro->addhubtoPath(tst_e2_2);
sher_tro->addhubtoPath(tst_e2_3);

Defined_train_path* tor_sher;
tor_sher->addhubtoPath(tst_e2_0);
tor_sher->addhubtoPath(tst_e2_2);
tor_sher->addhubtoPath(tst_e2_3);


//load data into train

int priority01= 1;
int priorty02 =3;
int priorty03=5;

/*
tst_e1_0->load_data(priority01,sher_tro);
tst_e1_1->load_data(priorty02,tor_sher);
tst_e1_2->load_data(priorty03,sher_tro);
tst_e1_3->load_data(priorty02,tor_sher);
*/
//create window and framez
sf::RenderWindow window (sf::VideoMode(700,600), "Test_hub1");
window.setFramerateLimit(60);

//work


/// MAINLOOP

while (window.isOpen())
{ sf::Event prevent;


        while (window.pollEvent(prevent))
            {
                {if (prevent.type ==sf::Event::Closed)
                            window.close();
                    }

                {if (prevent.type == sf::Event::Resized)
                    glViewport(0, 0, prevent.size.width, prevent.size.height);
                }
            }




// itraor processing




// clear and draw
        window.clear();
    //draw itorarrs
        for (std::list<int>::iterator it = enity_2_id_list.begin();
            it != enity_2_id_list.end(); it++)
        {
            enity_2test* tmp_prt_enity2;

             tmp_prt_enity2 =sym_manger->get_entity_via_id(it);
            tmp_prt_enity2->draw(window);
        }
    window.display();
}

// cleanup


sym_manger->removeenity(tst_e2_0);
sym_manger->removeenity(tst_e2_1);
sym_manger->removeenity(tst_e2_2);
sym_manger->removeenity(tst_e2_3);
sym_manger->removeenity(tst_e2_4);



return 0;

}
