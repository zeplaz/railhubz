
#include "drivers.hpp"

/*
*##driver inliazers!
*parsed data can thus be used in HERE!!!!!!---> to setup the whole systemz

TODO: allow for options at startup. defult xml, custom, and binary loader-creater
*/
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
    for(size_t i = 0; i<pathz_tomale;i++)
    {
        std::cout <<"\n #->NEWpathconsturcion BEGING\n";
        sym_manger.construct_pathz(inilz_parser.raw_path(i));
    }
  }
  //R_linez* templine = dynamic_cast<R_linez*>(sym_manger.get_rail_entity(sym_manger.r_line_id_list[0]));
