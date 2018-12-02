

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>

#include  "enity_2test.h"
#include  "enity_1test.h"
#include "Sym_Map.h"
#include "Defined_train_path.h"
#include "Base_TSym_entity.h"

#include <algorithm>
#include <time.h>
#include <list>
//#include "test_entity1.h"

int main ()

{printf("nnewtestpage.1111...\n");
    int total_ent_count=0;
time_t main_runtime_o;
 main_runtime_o = clock();


//enity_1test takez:
/* (time_t* cur_time, int& Total_enty, sf::Vector2f(x,y),
        startlocation, endlocation)

        //entity_2_takes;
    (time_t* cur_time,int total_enty,sf::Vector2f(x,y));
*/

//create other needed obejc
//test_entity1* test1;

//test_entity1 newent1(total_ent_count);
//test1=  &newent1;

//sym_manger->Register_entity(test1);
float x;
float y;

x=300.f;
y=200.f;
printf("nnewtestpage....\n");
enity_2test* tst_e2_0 = new enity_2test(main_runtime_o,sf::Vector2f(x,y),total_ent_count);

x=40.f;
y=70.f;
enity_2test* tst_e2_1 = new enity_2test(main_runtime_o,sf::Vector2f(x,y),total_ent_count);
x=30.f;
y=250.f;
enity_2test* tst_e2_2 = new enity_2test(main_runtime_o,sf::Vector2f(x,y),total_ent_count);

x=200.f;
y=10.f;
enity_2test* tst_e2_3 = new enity_2test(main_runtime_o,sf::Vector2f(x,y),total_ent_count);

x=400.f;
y=30.f;
enity_2test* tst_e2_4 = new enity_2test(main_runtime_o,sf::Vector2f(x,y),total_ent_count);


/*
enity_1test tst_e1_1();
enity_1test tst_e1_2();
enity_1test tst_e1_3();
enity_1test tst_e1_4();
*/



//inlization regisation.

 std::list<int> enity_1_idlist;
 std::list<int> enity_2_idlist;


sym_manger->Register_entity(tst_e2_0);
sym_manger->Register_entity(tst_e2_1);
sym_manger->Register_entity(tst_e2_2);
sym_manger->Register_entity(tst_e2_3);
sym_manger->Register_entity(tst_e2_4);


enity_2_idlist.push_front(tst_e2_0->get_id());
enity_2_idlist.push_front(tst_e2_1->get_id());
enity_2_idlist.push_front(tst_e2_2->get_id());
enity_2_idlist.push_front(tst_e2_3->get_id());
enity_2_idlist.push_front(tst_e2_4->get_id());


///trainz

enity_1test* tst_e1_t0 = new enity_1test(main_runtime_o,tst_e2_0,tst_e2_3,total_ent_count);
enity_1test* tst_e1_t1 = new enity_1test(main_runtime_o,tst_e2_3,tst_e2_0,total_ent_count);


sym_manger->Register_entity(tst_e1_t0);
sym_manger->Register_entity(tst_e1_t1);


enity_1_idlist.push_front(tst_e1_t0->get_id());
enity_1_idlist.push_front(tst_e1_t1->get_id());


printf("beforepathgen\n");


Defined_train_path* sher_tro = new Defined_train_path;

printf("postepathge2n\n");
sher_tro->addhubtoPath(tst_e2_0);
printf("postepathge3n\n");
sher_tro->addhubtoPath(tst_e2_2);
sher_tro->addhubtoPath(tst_e2_3);

Defined_train_path* tor_sher = new Defined_train_path;
tor_sher->addhubtoPath(tst_e2_3);
tor_sher->addhubtoPath(tst_e2_2);
tor_sher->addhubtoPath(tst_e2_0);



//load data into train

int priority01= 1;
int priorty02 =3;
int priorty03=5;
int speed1 =1;
int speed5=5;

tst_e1_t0->load_data(priority01,speed1,tor_sher);
tst_e1_t1->load_data(priorty03,speed5,sher_tro);
/*

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
        for (std::list<int>::iterator it = enity_2_idlist.begin();
            it != enity_2_idlist.end(); it++)
        {

            enity_2test* tmp_prt_enity2;

             tmp_prt_enity2 =     dynamic_cast<enity_2test*> (sym_manger->get_entity_via_id(*it));
            tmp_prt_enity2->draw(window);
        }


        for (std::list<int>::iterator it = enity_1_idlist.begin();
            it != enity_1_idlist.end(); it++)
        {

            enity_1test* tmp_prt_enity1;

             tmp_prt_enity1 =     dynamic_cast<enity_1test*> (sym_manger->get_entity_via_id(*it));
            tmp_prt_enity1->draw(window);
        }
    //    tst_e2_2->draw(window);
    window.display();
//    printf("loop\n");

    tst_e1_t0->update();
    tst_e1_t1->update();
}

// cleanup


sym_manger->removeenity(tst_e2_0);
sym_manger->removeenity(tst_e2_1);
sym_manger->removeenity(tst_e2_2);
sym_manger->removeenity(tst_e2_3);
sym_manger->removeenity(tst_e2_4);

sym_manger->removeenity(tst_e1_t0);
sym_manger->removeenity(tst_e1_t1);


return 0;

}
