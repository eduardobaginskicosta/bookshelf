#pragma once
#include <algorithm>
#include <string>
#include <ctime>

namespace Bookshelf
{
  class Utils
  {
    public:
      static bool IsEmptyOrWhitespace(const std::string str);

      //

      static void ToLowerCase(std::string& str);
      static void ToUpperCase(std::string& str);
      
      //

      static std::string ToAsciiTime(const std::time_t time);
  };
}; // namespace Bookshelf