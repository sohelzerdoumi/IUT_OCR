#include "utils.h"

#include <sstream>

using namespace std;


string intToString(int nombre){
    ostringstream flux;
    flux << nombre ;
    return flux.str();
}

std::vector <std::string> read_directory( const std::string& path )
  {
  std::vector <std::string> result;
  dirent* de;
  DIR* dp;
  dp = opendir( path.empty() ? "." : path.c_str() );
  if (dp)
    {
    while (true)
      {
      de = readdir( dp );
      if (de == NULL) break;
      if( string(de->d_name)  != "." and  string(de->d_name)  != ".." )
      result.push_back( std::string( de->d_name ) );
      }
    closedir( dp );
    std::sort( result.begin(), result.end() );
    }
  return result;
  }
