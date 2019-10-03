
#include "drivers.hpp"
#include <random>
/*
*##driver inliazers!
*parsed data can thus be used in HERE!!!!!!---> to setup the whole systemz

TODO: allow for options at startup. defult xml, custom, and binary loader-creater
*/
void driver::drive_loop()
{
  m_cmd_agent_op.scan_hubs_for_dispatch_cadiates();
  sym_manger.update_rail_entityz();
  m_cmd_agent_op.dispatchtrain();
}

  void driver::initializer()
  {
    std::string rail_type1 = "rail01";
    std::string train_type1 = "train01";
    parser::xml_parser inilz_parser;

    system_org::hub_factory inlized_hub_factory;

    sym_manger.add_factory(rail_type1,std::make_shared<system_org::R_line_factory>());
    sym_manger.add_factory(rail_type1,std::make_shared<system_org::R_line_factory>());

    std::vector<std::shared_ptr<system_org::entity_factory>> train_factoryz;

    train_factoryz.push_back(std::make_shared<system_org::trainz_factory>());
    train_factoryz.push_back(std::make_shared<system_org::trainz_factory>());

    sym_manger.insert_facgroup_ctrl(train_type1,std::move(train_factoryz));

//being defult parsing of defualt configfile
    inilz_parser.run_parser();

    const size_t hubz_tomake  = inilz_parser.number_of_hubz();
    const size_t pathz_tomale = inilz_parser.number_of_pathz();
    const size_t r_lienz_tomake = inilz_parser.number_of_tracks();

    //Iniliaze HUBZ!
    for(size_t i = 0; i<hubz_tomake;i++)
    {
      std::vector<std::string>* temp_hubdata =  inilz_parser.get_hub_data(i);
      std::string temp_name = temp_hubdata->at(0);
      float tempx = atof(temp_hubdata->at(1).c_str());
      float tempy =  atof(temp_hubdata->at(2).c_str());
      sym_manger.Register_hubz(inlized_hub_factory.request_entity(temp_name,tempx,tempy));
    }
    std::cout <<"##COMPLEATED HUB CREATIONZ" << '\n';

    //R_linez Iniliazationz!
    for(size_t i=0; i<r_lienz_tomake;i++)
    {
      sym_manger.activate_factory(rail_type1);
    }

    std::unique_ptr<std::vector<R_linez*>> r_line_collection = sym_manger.retrieve_R_linez();
    R_linez* temp_linez;
    std::pair<std::string,std::string>* prt_line_pair;
    railhubz* temp_hub1;
    railhubz* temp_hub2;

    for(size_t i=0; i<r_lienz_tomake;i++)
    {
      prt_line_pair = inilz_parser.get_track_pair(i);
      std::cout << "\n pairfistname::" <<prt_line_pair->first.c_str()
                << "vialookiptable::"<<sym_manger.find_lookuptable(prt_line_pair->first) <<'\n';

      temp_hub1 = sym_manger.get_hub(sym_manger.find_lookuptable(prt_line_pair->first));
      temp_hub2 = sym_manger.get_hub(sym_manger.find_lookuptable(prt_line_pair->second));
      temp_linez = r_line_collection->at(i);
      temp_linez->set_pos(temp_hub1->get_location(),temp_hub2->get_location());
      temp_hub1->add_R_line(temp_linez);
      temp_hub2->add_R_line(temp_linez);
    }

    std::cout <<"##COMPLEATED R_linez CREATIONZ" << '\n'<<'\n';

    //Path setup
    std::cout <<"->DEBUG+size of pathsnum" << pathz_tomale <<'\n';
    std::vector<std::vector<std::string>> pathz_vec;
    for(size_t i = 0; i<pathz_tomale;i++)
     {
        std::cout <<"\n #->NEWpathconsturcion BEGING\n";
        std::string& temp_string = inilz_parser.raw_path(i);
        pathz_vec.push_back(sym_manger.construct_pathz(temp_string));
     }

     for(size_t i =0; i<pathz_vec.size();i++)
     {
       sym_manger.registar_pathz(pathz_vec.at(i));
     }


     //TRAIN SETUPZ/
     const size_t trainz_tomake = 5;
     //radom path sets
     std::default_random_engine generator;
     std::uniform_int_distribution<int> distribution(0,sym_manger.num_of_paths()-1);
     int path_roll = distribution(generator);
     auto rad_path_str = std::bind (distribution, generator);


     for(size_t i =0; i< trainz_tomake;i++)
     {
       sym_manger.activate_factory(train_type1);
     }


     for(size_t i =0; i< sym_manger.train_id_list.size();i++)
     {
       std::cout<<"BEGIN SETTRAIN::" << i <<'\n';
       trainz* temp_train = dynamic_cast<trainz*>(sym_manger.get_rail_entity(
                                                 sym_manger.train_id_list.at(i)));
        //  int temp_rad = ;
        std::cout<<"cast compleatefor::"<< sym_manger.train_id_list.at(i) <<'\n';
        int temp_rad = rad_path_str();
        std::cout<<"rad compleate::" <<temp_rad  <<'\n';
        const Defined_train_path<railhubz>& ref_t_path = sym_manger.rtn_train_path(temp_rad);
        temp_train->set_path(ref_t_path);
        temp_train->Path_Next_hub();
        temp_train->Init();
        Defined_train_path<railhubz>& cnstles_path  = const_cast<Defined_train_path<railhubz>&> (ref_t_path);
        railhubz* temp_hub = cnstles_path.peak_top();

        temp_hub->add_train_toque(temp_train);
     }



  }
  //R_linez* templine = dynamic_cast<R_linez*>(sym_manger.get_rail_entity(sym_manger.r_line_id_list[0]));
