//#include "parser.hpp"

#include <iostream>
#include <string>
#include <regex>
#include <utility>
#include <fstream>
#include <algorithm>
#include <iterator>




constexpr unsigned int str2int(const char* str, int h = 0)
{
return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
}

 unsigned int str2int_run(const char* str, int h = 0)
{
return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
}

const int h_int_name =  str2int("name");
const int train_int_path =  str2int("trainz_path");
const int h_mtl =  str2int("mtl");
const int h_shrbyz =  str2int("shrbyz");
const int h_qcity =  str2int("qcity");
const int r_l_xy1 =  str2int("xy1");
const int r_l_xy2 =  str2int("xy2");
int main(int argc, char** argv)
  {
    //parser::xml_parser xml_prz;


    std::ifstream config_file("config_trainz.xml");
    std::string file_in_string;
    config_file.seekg(0, std::ios::end);
    file_in_string.reserve(config_file.tellg());
    config_file.seekg(0, std::ios::beg);

    file_in_string.assign((std::istreambuf_iterator<char>(config_file)),
                std::istreambuf_iterator<char>());

    std::regex rexal( R"#(\s*<\s*(\S+)\s*>\s*(\S+)\s*<\s*/\1\s*>\s*)#");
    std::vector<std::string> substingz;
    std::vector<int> indexzr{1,2};
    const std::sregex_token_iterator end;

    for(std::sregex_token_iterator reg_iter (file_in_string.begin(), file_in_string.end(), rexal, indexzr);
        reg_iter!=end; ++reg_iter)
        {
          substingz.push_back(*reg_iter);
        }

        for(std::sregex_token_iterator reg_iter (substingz.at(1).begin(), substingz.at(1).end(), rexal, indexzr);
            reg_iter!=end; ++reg_iter)
            {
              substingz.push_back(*reg_iter);
            }
          std::string raw_hub[3];

          std::vector<std::vector<std::string>> hub_collection;
          std::string raw_path;
          std::string temp_xy1;
          std::vector<std::pair<std::string,std::string>> line_pair;
          std::vector<std::string> raw_path_vec;
          std::vector<std::string> line_hubz;

        for(size_t i =0; i<substingz.size(); i++)
        {

          switch(str2int_run(substingz.at(i).c_str()))
          {
            case h_int_name :
            {
              std::vector<std::string> raw_hub_vec;
              std::cout << "-->rawHUBINFO from config" << '\n';
              raw_hub[0] = substingz.at(i+1);
              raw_hub[1] = substingz.at(i+3);
              raw_hub[2] = substingz.at(i+5);
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
              case r_l_xy1 :
              {
                temp_xy1 = substingz.at(i+1);
                break;
              }

              case r_l_xy2 :
              {
                line_pair.push_back(make_pair(temp_xy1,substingz.at(i+1)));
                break;
              }
          }
          std::cout <<"substingz::" << substingz.at(i) <<'\n';
        }
          std::cout<<"intval::" << h_int_name <<"  |intval::"<< train_int_path
          <<"  |intval::" << h_qcity<<"  |intval::" <<'\n';

          for(size_t i=0; i<hub_collection.size();i++ )
          {
            std::vector<std::string> tempvec = hub_collection.at(i);

            std::cout << "rawhubzdata::" << tempvec.at(0) << "  data2::" << tempvec.at(1) <<"  data3::" << tempvec.at(2) <<'\n';

          }

          for(size_t i=0; i<raw_path_vec.size();i++ )
          {
            std::cout << "PATHRAWZ::" << raw_path_vec.at(i) << '\n';
          }

          for(size_t i=0; i<line_pair.size();i++)
          {
            std::pair<std::string,std::string> temp_pair;
            temp_pair = line_pair.at(i);
            std::cout << "Pair_city1::" << temp_pair.first  << " paircity2::" <<  temp_pair.second <<  '\n';
          }


    return 0;
  }
