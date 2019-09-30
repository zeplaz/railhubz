//xml_parser.hpp
#pragma once

#include <iostream>
#include <regex>
#include <fstream>
#include <string>

namespace parser
{

  constexpr unsigned int str2int(const char* str, int h = 0)
  {
  return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
  }

  static unsigned int str2int_run(const char* str, int h = 0)
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

class xml_parser
{

  private :
  std::ifstream config_file;
  std::string file_in_string;
  std::vector<std::string> substingz;
  std::vector<int> indexzr{1,2};
  const std::sregex_token_iterator end;
  bool compleated = false;

  public :

  std::vector<std::vector<std::string>> hub_collection;
  std::vector<std::string> raw_path_vec;
  std::vector<std::pair<std::string,std::string>> line_pair_vec;

  bool run_parser();
  inline const size_t number_of_hubz() {return hub_collection.size();}
  std::vector<std::string>* get_hub_data(size_t& index);

  inline const size_t number_of_tracks(){return line_pair_vec.size();}
  std::pair<std::string,std::string>* get_track_pair(size_t& index);

  inline const size_t number_of_pathz(){return raw_path_vec.size();}

  std::string& raw_path(size_t& index);

};

}


/*
enum class xml_node_type
{
null_node,
root_node,
element_node,
plan_text_node,
comment_node,
declaration_node,
};
*/
/*
 //protected :
  public :
   //std::string tag;
   //std::string value;
  // std::string example = "<hubz><name>mtl</name><x>200</x><y>100</y></hubz>";
  // std::regex rexal;
 public :
   xml_parser()
   {
  //  std::regex rexal( R"#(\s*<\s*(\S+)\s*>\s*(\S+)\s*<\s*///\1\s*>\s*)#", std::regex::icase );
  // }


 //std::regex reg_literal(R"#(\s*<\s*(\S+)\s*>\s*#",std::regex::icase);

  //std::regex re (R"#(\s*<\s*(\S+)\s*>\s*(\S+)\s*<\s*/\1\s*>\s*)#"  ) ;
 /*std::copy( std::sregex_token_iterator(tag.begin(), tag.end(), reg_literal, 1),
              std::sregex_token_iterator(),
              std::ostream_iterator<std::string>(std::cout, "\n")); */
