//parser.cpp
#include "parser.hpp"

bool parser::xml_parser::run_parser()
{
  //load the file
  config_file.open("config_trainz.xml");
  config_file.seekg(0, std::ios::end);
  file_in_string.reserve(config_file.tellg());
  config_file.seekg(0, std::ios::beg);

  //putfile in string stream buffer?
  file_in_string.assign((std::istreambuf_iterator<char>(config_file)),
              std::istreambuf_iterator<char>());

  // oh the regex to use to parse, this need to be fixed but ya idk.
  std::regex rexal( R"#(\s*<\s*(\S+)\s*>\s*(\S+)\s*<\s*/\1\s*>\s*)#");

  //round one loop. pushing it all into a big stringvector
  for(std::sregex_token_iterator reg_iter (file_in_string.begin(), file_in_string.end(),
                                           rexal, indexzr); reg_iter!=end; ++reg_iter)
     {
      substingz.push_back(*reg_iter);
     }
     //some temp varz need for next loop
     std::string raw_path;
     std::string temp_xy1;
//super inffective switch that sorts the big parsed vec!
   for(size_t i =0; i<substingz.size(); i++)
     {
       switch(str2int_run(substingz.at(i).c_str()))
       {
         //really unhappy i cant seem to get a string arrya[3] into a vec..
        case h_int_name :
         {
         std::vector<std::string> raw_hub_vec;
         std::cout << "-->rawHUBINFO from config" << '\n';
         raw_hub_vec.push_back(substingz.at(i+1));
         raw_hub_vec.push_back(substingz.at(i+3));
         raw_hub_vec.push_back(substingz.at(i+5));
         hub_collection.push_back(raw_hub_vec);
        break;
         }

        case train_int_path :
         {
         std::cout << "->ADDING TRAINPATH TO RAWVEC from config" << '\n';
         raw_path_vec.push_back(substingz.at(i+1));
        break;
         }
         // the linelocations,pears kinda riskin it here but assume that
         //a line needs to temp the 1st and pair once 2nd found riskyzbiuzz
        case r_l_xy1 :
         {
          temp_xy1 = substingz.at(i+1);
         break;
        }
        case r_l_xy2 :
          {
           std::cout << "->Linepair_added" <<'\n';
           line_pair_vec.push_back(make_pair(temp_xy1,substingz.at(i+1)));
          break;
          }
        }//end switch
      }//endnasty loop
      compleated = true;
 return compleated;
}
 std::vector<std::string>* parser::xml_parser::get_hub_data(size_t& index)
 {
   return &hub_collection.at(index);
 }

 std::pair<std::string,std::string>* parser::xml_parser::get_track_pair(size_t& index)
 {
    return &line_pair_vec.at(index);
 }

  std::string*  parser::xml_parser::raw_path(size_t& index)
  {
    return &raw_path_vec.at(index);
  }
