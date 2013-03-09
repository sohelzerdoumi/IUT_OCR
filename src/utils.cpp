#include "utils.h"
#include <libconfig.h++>

#include <iostream>
#include <sstream>
#define CONFIG_FILE "config.txt"
using namespace libconfig;
using namespace std;

Config cfg;
void loadConfigFile(){
  cfg.readFile(CONFIG_FILE);
}

bool getConfigValueBoolean( const string & variable ){
    bool out = false;
    cfg.lookupValue(variable, out);
    return out;
}
float getConfigValueFloat( const string & variable ){
    float out = 0;
    cfg.lookupValue(variable, out);
    return out;
}
int getConfigValueInt( const string & variable ){
    int out = 0;
    cfg.lookupValue(variable, out);
    return out;
}
string getConfigValueString( const string & variable ){
    string out;
    cfg.lookupValue(variable, out);
    return out;
}


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
