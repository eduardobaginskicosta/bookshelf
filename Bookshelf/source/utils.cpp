#include "utils.hpp"

// @

bool Bookshelf::Utils::IsEmptyOrWhitespace(
  std::string str
)
{
  return (
    str.length() <= 0 ||
    (
      str.length() > 0 &&
      (
        str == "" ||
        str == " " ||
        str == "\n" ||
        str == "\r" ||
        str == "\r\n"
      )
    )
  );
}

// @

void Bookshelf::Utils::ToLowerCase(std::string& str)
{
  std::transform(str.begin(), str.end(), str.begin(), std::tolower);
}

// @

void Bookshelf::Utils::ToUpperCase(std::string& str)
{
  std::transform(str.begin(), str.end(), str.begin(), std::toupper);
}

// @

std::string Bookshelf::Utils::ToAsciiTime(
  const std::time_t time
)
{
  return std::asctime(std::gmtime(&time));
}
