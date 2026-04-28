#include "CLogg.h"

#include <iostream>
#include <format>
#include "utils.h"

bool CLogg::color = false;
void CLogg::set_color( LogLevel ll ) {
  switch( ll ) {
    case INFO:    std::cout <<  "\x1b[48;5;21m\x1b[38;5;0m"; break;
    case DEBUG:   std::cout <<  "\x1b[48;5;40m\x1b[38;5;0m"; break;
    case WARNING: std::cout << "\x1b[48;5;214m\x1b[38;5;0m"; break;
    case ERROR:   std::cout << "\x1b[48;5;196m\x1b[38;5;0m"; break;
  }
  
}

void CLogg::clear_color() {  std::cout << "\033[0m"; }

std::string CLogg::get_log_level_name( LogLevel ll ) {
  switch( ll ) {
    case INFO:    return " Info. ";
    case DEBUG:   return " Debug ";
    case WARNING: return "Warning";
    case ERROR:   return " Error ";
    default: return "";
  }
}

void CLogg::log_writter( LogLevel ll, std::string msg ) {
  if( color ) { set_color( ll ); }

  std:: cout << "[ " << get_log_level_name( ll ) << " ]";
  
  if( color ) { clear_color(); }

  std::cout << std::format( 
    " {{ {:s} }} - {:s}",
    current_datetime(),
    msg
  );

  std::cout << std::endl;
}

void CLogg::Log( std::string msg ) { log_writter( INFO, msg ); }
void CLogg::Dbg( std::string msg ) { log_writter( DEBUG, msg ); }
void CLogg::Wrn( std::string msg ) { log_writter( WARNING, msg ); }
void CLogg::Err( std::string msg ) { log_writter( ERROR, msg ); }

void CLogg::enable_color() {
  color = true;
}

void CLogg::disable_color() {
  color = false;
}