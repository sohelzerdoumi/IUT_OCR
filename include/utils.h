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


void        loadConfigFile(const std::string & filename = CONFIG_FILE);

bool                getConfigValueBoolean( const std::string & variable );
float               getConfigValueFloat( const std::string & variable );
int                 getConfigValueInt( const std::string & variable );
std::string         getConfigValueString( const std::string & variable );

bool isConfigValuesContainString( const std::string & variable, const std::string & value  );

template<typename T>
void setConfigValue( const std::string & variable, const T & value );


/**
 *  IO Colors
 */
#define IO_RESET        "\033[0m"
#define IO_BLACK        "\033[30m"      		/* Black */
#define IO_RED          "\033[31m"      		/* Red */
#define IO_GREEN        "\033[32m"      		/* Green */
#define IO_YELLOW       "\033[33m"      		/* Yellow */
#define IO_BLUE         "\033[34m"      		/* Blue */
#define IO_MAGENTA      "\033[35m"      		/* Magenta */
#define IO_CYAN         "\033[36m"             	/* Cyan */
#define IO_WHITE        "\033[37m"             	/* White */
#define IO_BOLDBLACK    "\033[1m\033[30m"      	/* Bold Black */
#define IO_BOLDRED      "\033[1m\033[31m"      	/* Bold Red */
#define IO_BOLDGREEN    "\033[1m\033[32m"       /* Bold Green */
#define IO_BOLDYELLOW   "\033[1m\033[33m"       /* Bold Yellow */
#define IO_BOLDBLUE     "\033[1m\033[34m"       /* Bold Blue */
#define IO_BOLDMAGENTA  "\033[1m\033[35m"       /* Bold Magenta */
#define IO_BOLDCYAN     "\033[1m\033[36m"       /* Bold Cyan */
#define IO_BOLDWHITE    "\033[1m\033[37m"       /* Bold White */

#define IO_BG_GREY      "\033[40m"              /* Grey */
#define IO_BG_RED       "\033[41m"              /* Red */
#define IO_BG_BLUE      "\033[44m"              /* Blue */



#endif
