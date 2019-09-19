//xml_parser.hpp


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

namespace parser
{
class xml_parser
{
 //protected :
  public :
   std::string tag;
   std::string value;
   std::string example = "<hubz><name>mtl</name><x>200</x><y>100</y></hubz>";
   std::regex rexal;
 public :
   xml_parser()
   {
    std::regex rexal( R"#(\s*<\s*(\S+)\s*>\s*(\S+)\s*<\s*/\1\s*>\s*)#", std::regex::icase );
   }


 //std::regex reg_literal(R"#(\s*<\s*(\S+)\s*>\s*#",std::regex::icase);

  //std::regex re (R"#(\s*<\s*(\S+)\s*>\s*(\S+)\s*<\s*/\1\s*>\s*)#"  ) ;
 /*std::copy( std::sregex_token_iterator(tag.begin(), tag.end(), reg_literal, 1),
              std::sregex_token_iterator(),
              std::ostream_iterator<std::string>(std::cout, "\n")); */


};

}
