#ifndef UTILS_H
#define UTILS_H

#include <algorithm>
#include <string>
#include <vector>
#include <libconfig.h++>

#include <dirent.h>
#include <sys/types.h>
#define CONFIG_FILE "config.txt"


std::vector <std::string> read_directory( const std::string& path = std::string() );
std::string intToString(int nombre);

void        loadConfigFile(const std::string & filename = CONFIG_FILE);

bool                getConfigValueBoolean( const std::string & variable );
float               getConfigValueFloat( const std::string & variable );
int                 getConfigValueInt( const std::string & variable );
std::string         getConfigValueString( const std::string & variable );

bool isConfigValuesContainString( const std::string & variable, const std::string & value  );

template<typename T>
void setConfigValue( const std::string & variable, const T & value );

#endif
