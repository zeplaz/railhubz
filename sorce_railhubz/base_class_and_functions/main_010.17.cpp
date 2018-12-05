

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>

#include  "enity_2test.h"
#include  "enity_1test.h"
#include "R_linez.h"
#include "Sym_Map.h"
#include "Defined_train_path.h"
#include "Base_TSym_entity.h"

#include <algorithm>
#include <time.h>
#include <list>
//#include "test_entity1.h"
#include <iostream>


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
enity_2test* sherbyz = new enity_2test(main_runtime_o,sf::Vector2f(x,y),total_ent_count);

x=40.f;
y=70.f;
enity_2test* mtl = new enity_2test(main_runtime_o,sf::Vector2f(x,y),total_ent_count);
x=70.f;
y=250.f;
enity_2test* tro = new enity_2test(main_runtime_o,sf::Vector2f(x,y),total_ent_count);

x=300.f;
y=540.f;
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
//printf("toalenitycount %s \n", total_ent_count);

std::cout  << "total count entityz: "<< total_ent_count << "\n";

//inlization regisation.

 std::list<int> enity_1_idlist;
 std::list<int> enity_2_idlist;
 std::list<int> rail_enity_idlist;


sym_manger->Register_entity(sherbyz);
sym_manger->Register_entity(mtl);
sym_manger->Register_entity(tro);
sym_manger->Register_entity(tst_e2_3);
sym_manger->Register_entity(tst_e2_4);


enity_2_idlist.push_front(sherbyz->get_id());
enity_2_idlist.push_front(mtl->get_id());
enity_2_idlist.push_front(tro->get_id());
enity_2_idlist.push_front(tst_e2_3->get_id());
enity_2_idlist.push_front(tst_e2_4->get_id());


///trainz



printf("beforepathgen\n");


Defined_train_path* sher_tro = new Defined_train_path;

printf("postepathge2n\n");
sher_tro->addhubtoPath(mtl);
printf("postepathge3n\n");
sher_tro->addhubtoPath(tro);

//sher_tro->addhubtoPath(tst_e2_3);
Defined_train_path* tor_sher = new Defined_train_path;
tor_sher->addhubtoPath(sherbyz);
tor_sher->addhubtoPath(mtl);
//tor_sher->addhubtoPath(tst_e2_0);
printf("postepathge4.0n\n");
enity_1test* tst_e1_t0 = new enity_1test(main_runtime_o,sherbyz ,tro,total_ent_count);

enity_1test* tst_e1_t1 = new enity_1test(main_runtime_o,tst_e2_4 , mtl, total_ent_count);
printf("postepathge4.1n\n");

sym_manger->Register_entity(tst_e1_t0);
sym_manger->Register_entity(tst_e1_t1);
std::cout  << "total count entityz: "<< total_ent_count << "\n";

printf("post-rgistart trainz.1n\n");
enity_1_idlist.push_front(tst_e1_t0->get_id());
enity_1_idlist.push_front(tst_e1_t1->get_id());

//load data into train



int priority01= 1;
int priorty02 =3;
int priorty03=5;
float speed2 =3;
float speed5=5;
printf("pre-loadtrainz.1n\n");
tst_e1_t0->load_data(priority01,speed2,tor_sher);

tst_e1_t1->load_data(priorty02,speed5,sher_tro);
/*

tst_e1_1->load_data(priorty02,tor_sher);
tst_e1_2->load_data(priorty03,sher_tro);
tst_e1_3->load_data(priorty02,tor_sher);
*/
std::cout  << "total count entityz: "<< total_ent_count << "\n";



//line construction
printf("prelineconstruct \n");
R_linez* R_line_01 = new R_linez(sherbyz,mtl,total_ent_count);
R_linez* R_line_02 = new R_linez(tro,tst_e2_3,total_ent_count);



sym_manger->Register_entity(R_line_01);
sym_manger->Register_entity(R_line_02);

printf("newlineregistard \n");

rail_enity_idlist.push_front(R_line_01->get_id());
rail_enity_idlist.push_front(R_line_02->get_id());

std::cout  << "railine2ID: "<< R_line_02->get_id() << "\n";


//printf("newlineaddedtolist lineid:%g \n",R_line_01->get_id());
//create window and framez

sf::RenderWindow window (sf::VideoMode(700,800), "Test_hub1");
window.setFramerateLimit(60);

//work
std::cout  << "total count entityz: "<< total_ent_count << "\n";

//printf("toalenitycount %s \n", total_ent_count);

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


tst_e1_t0->update();
tst_e1_t1->update();

// clear and draw
        window.clear();

    //draw itorarrs
/*
    for (std::list<int>::iterator it = rail_enity_idlist.begin();
        it != rail_enity_idlist.end(); it++)
    {

        R_linez* tmp_prt_rail;

        // tmp_prt_rail =     dynamic_cast<R_linez*> (sym_manger->get_entity_via_id(*it));
        tmp_prt_rail->draw(window);
    }*/
    R_line_01->draw(window);
    R_line_02->draw(window);
//    printf("railinze comleate \n");

        for (std::list<int>::iterator it = enity_2_idlist.begin();
            it != enity_2_idlist.end(); it++)
        {

            enity_2test* tmp_prt_enity2;

             tmp_prt_enity2 =     dynamic_cast<enity_2test*> (sym_manger->get_entity_via_id(*it));
            tmp_prt_enity2->draw(window);
        }
        //printf("drawenity2 comleate \n");

        for (std::list<int>::iterator it = enity_1_idlist.begin();
            it != enity_1_idlist.end(); it++)
        {

            enity_1test* tmp_prt_enity1;

             tmp_prt_enity1 =     dynamic_cast<enity_1test*> (sym_manger->get_entity_via_id(*it));
            tmp_prt_enity1->draw(window);
        }
        //printf("drawenity1 comleate \n");





    //    tst_e2_2->draw(window);
    window.display();
//    printf("loop\n");


}

// cleanup


sym_manger->removeenity(sherbyz);
sym_manger->removeenity(mtl);
sym_manger->removeenity(tro);
sym_manger->removeenity(tst_e2_3);
sym_manger->removeenity(tst_e2_4);

sym_manger->removeenity(tst_e1_t0);
sym_manger->removeenity(tst_e1_t1);

sym_manger->removeenity(R_line_01);

return 0;

}
