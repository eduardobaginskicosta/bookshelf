#include "ansi_manager.hpp"

// @

bool Bookshelf::Color::operator ==(
  const struct Bookshelf::Color other
)
{
  return (
    red == other.red &&
    green == other.green &&
    blue == other.blue
  );
}

// @

bool Bookshelf::Color::operator !=(
  const struct Bookshelf::Color other
  )
{
  return (
    red != other.red ||
    green != other.green ||
    blue != other.blue
  );
}

// @

void Bookshelf::AnsiManager::ApplyColors(
  enum Bookshelf::ForeColors foreground_color,
  enum Bookshelf::BackColors background_color
)
{
  std::string ansi_code = "\x1B[";

  ansi_code += foreground_color < 0 ? "0" : std::to_string(foreground_color);
  ansi_code += ";";
  ansi_code += background_color < 0 ? "0" : std::to_string(background_color);
  ansi_code += "m";

  std::cout << ansi_code;
}

// @

void Bookshelf::AnsiManager::ApplyColors255(
  std::uint8_t foreground_code,
  std::uint8_t background_code
)
{
  if (foreground_code > 0)
  {
    std::cout << "\x1B[38;5;" << std::to_string(foreground_code) << "m";
  }
  
  if (background_code > 0)
  {
    std::cout << "\x1B[48;5;" << std::to_string(background_code) << "m";
  }
}

// @

void Bookshelf::AnsiManager::ApplyColorsRGB(
  struct Color foreground,
  struct Color background
)
{
  std::string ansi_code;;

  if (foreground != Bookshelf::COLOR_TRANSPARENT)
  {
    ansi_code = "\x1B[38;2;";
    ansi_code += std::to_string(foreground.red) + ";";
    ansi_code += std::to_string(foreground.green) + ";";
    ansi_code += std::to_string(foreground.blue) + "m";

    std::cout << ansi_code;
  }

  if (background != Bookshelf::COLOR_TRANSPARENT)
  {
    ansi_code = "\x1B[48;2;";
    ansi_code += std::to_string(background.red) + ";";
    ansi_code += std::to_string(background.green) + ";";
    ansi_code += std::to_string(background.blue) + "m";

    std::cout << ansi_code;
  }
}

// @

void Bookshelf::AnsiManager::ApplyModes(
  const std::vector<enum Modes>& modes
)
{
  std::string ansi_code = "\x1B[";

  for (std::uint32_t index = 0; index < modes.size(); ++index)
  {
    ansi_code += std::to_string(modes[index]);

    if (index < modes.size() - 1)
    {
      ansi_code += ";";
    }
  }

  ansi_code += "m";
  std::cout << ansi_code.c_str();
}

// @

void Bookshelf::AnsiManager::Reset(void)
{
  std::cout << "\x1B[0m";
}

// @

void Bookshelf::AnsiManager::MoveCursor(
  std::uint32_t line,
  std::uint32_t column
)
{
  std::string ansi_code = "\x1B[";
  ansi_code += std::to_string(line);
  ansi_code += ";";
  ansi_code += std::to_string(column);
  ansi_code += "H";

  std::cout << ansi_code;
}

// @

void Bookshelf::AnsiManager::ClearScreen(void)
{
  std::cout << "\x1B[2J";
}
