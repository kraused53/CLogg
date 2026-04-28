#include "utils.h"

#include <chrono>
#include <format>

std::string current_datetime() {
  // Get current time
  auto now = std::chrono::system_clock::now();

  // Convert to local time
  auto zoned = std::chrono::zoned_time{std::chrono::current_zone(), now};

  // Format and return as string
  return std::format( "{:%b %d, %Y %I:%M %p}", zoned );
}