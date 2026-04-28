#pragma once

#include <string>

class CLogg {
  private:
    enum LogLevel{ INFO, DEBUG, WARNING, ERROR };
    static std::string get_log_level_name( LogLevel ll );
    static void log_writter( LogLevel ll, std::string msg );
    static bool color;
    static void set_color( LogLevel ll );
    static void clear_color();
  
  public:
    static void Log( std::string msg );
    static void Dbg( std::string msg );
    static void Wrn( std::string msg );
    static void Err( std::string msg );
    static void enable_color();
    static void disable_color();
};