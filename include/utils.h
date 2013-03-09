#ifndef UTILS_H
#define UTILS_H

#include <algorithm>
#include <string>
#include <vector>

#include <dirent.h>
#include <sys/types.h>

std::vector <std::string> read_directory( const std::string& path = std::string() );
std::string intToString(int nombre);
void        loadConfigFile();

bool                getConfigValueBoolean( const std::string & variable );
float               getConfigValueFloat( const std::string & variable );
int                 getConfigValueInt( const std::string & variable );
std::string         getConfigValueString( const std::string & variable );

#endif
