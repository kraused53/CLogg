#include <CLogg.h>

int main() {
  CLogg::Log( "This is a log!" );
  CLogg::Dbg( "This is a debug!" );
  CLogg::Wrn( "This is a warning!" );
  CLogg::Err( "This is an error!" );

  CLogg::enable_color();
  CLogg::Log( "This is a log!" );
  CLogg::Dbg( "This is a debug!" );
  CLogg::Wrn( "This is a warning!" );
  CLogg::Err( "This is an error!" );
  
  CLogg::disable_color();
  CLogg::Log( "This is a log!" );
  CLogg::Dbg( "This is a debug!" );
  CLogg::Wrn( "This is a warning!" );
  CLogg::Err( "This is an error!" );

  return 0;
}