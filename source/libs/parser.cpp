//parser.cpp
#include "parser.hpp"

#include <iostream>


using namespace parser; 


bool xml_parser::load_config_trains()
{
  try {

 
  config_file.open("config_trainz.xml");
  config_file.seekg(0, std::ios::end);
  file_in_string.reserve(config_file.tellg());
  config_file.seekg(0, std::ios::beg);

  //putfile in string stream buffer?
  file_in_string.assign((std::istreambuf_iterator<char>(config_file)),
              std::istreambuf_iterator<char>());

 }

 catch( int e)
 {
   std::cout << "**\n"
             <<   "|*********---_>>ERROORR IN LOAD trainz CONFIG AT XML PARSER"
             << "\n  ERRORCODE::CATCH:" << e << '\n'; 
 }
return true; 

}


void  xml_parser::regex_scan()
{ // oh the regex to use to parse, this need to be fixed but ya idk.
  std::regex rexal( R"#(\s*<\s*(\S+)\s*>\s*(\S+)\s*<\s*/\1\s*>\s*)#");

  //round one loop. pushing it all into a big stringvector
  for(std::sregex_token_iterator reg_iter (file_in_string.begin(), file_in_string.end(),
                                           rexal, indexzr); reg_iter!=end; ++reg_iter)
     {
      substingz.push_back(*reg_iter);
     }
}

void xml_parser::hub_case(parse_packet& pp, int i)
{
  std::vector<std::string> raw_hub_vec;
  std::cout << "-->rawHUBINFO from config" << '\n';
  raw_hub_vec.push_back(substingz.at(i+1));
  raw_hub_vec.push_back(substingz.at(i+3));
  raw_hub_vec.push_back(substingz.at(i+5));

  pp.hub_collection.push_back(raw_hub_vec);
}

void xml_parser::trainpath_case(parse_packet& pp, int i)
{
  std::cout << "->ADDING TRAINPATH TO RAWVEC from config" << '\n';

  pp.raw_trainpath_vec.push_back(substingz.at(i+1));
}


void xml_parser::line_pair_case(parse_packet& pp,std::string xy1, int i)
{
  std::cout << "->Linepair_added" <<'\n';
  pp.line_pair_vec.push_back(make_pair(xy1,substingz.at(i+1)));
}


parse_packet parser::xml_parser::run_parser()
{
  //load the file
  load_config_trains();
  regex_scan();

  parse_packet pp;


  //some temp varz need for next loop
  std::string temp_xy1 = " ";

  //super inffective switch that sorts the big parsed vec!

  for(size_t i =0; i<substingz.size(); i++)
   {

     switch(str2int_run(substingz.at(i).c_str()))
     {
        case h_int_name :
        {
           hub_case(pp,i);           //really unhappy i cant seem to get a string arrya[3] into a vec..
           break;
        }

        case train_int_path :
        {
           trainpath_case(pp,i);
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
          line_pair_case(pp, temp_xy1,i);
          break;
          }
        }//end switch
      }//endnasty loop
 compleated = true;
 return pp;
}


 String_Vec* parse_packet::get_hub_data(size_t& index)
 {
   return &hub_collection.at(index);
 }

 String_Pair* parse_packet::get_track_pair(size_t& index)
 {
    return &line_pair_vec.at(index);
 }

  std::string&  parse_packet::raw_path(size_t& index)
  {
    return raw_trainpath_vec.at(index);
  }
