#pragma once
#include <iostream>
#include <vector>
#include <string>

namespace Bookshelf
{
  struct Color
  {
    std::int8_t red;
    std::int8_t green;
    std::int8_t blue;

    //

    bool operator ==(const Color other);
    bool operator !=(const Color other);
  };

  // @

  const struct Bookshelf::Color COLOR_TRANSPARENT = { -1, -1, -1 };
  
  // @

  enum ForeColors
  {
    ForeDefault = 39,

    ForeMagenta = 35,
    ForeYellow = 33,
    ForeBlack = 30,
    ForeGreen = 32,
    ForeWhite = 37,
    ForeBlue = 34,
    ForeCyan = 36,
    ForeRed = 31,

    ForeBrightMagenta = 95,
    ForeBrightYellow = 93,
    ForeBrightBlack = 90,
    ForeBrightGreen = 91,
    ForeBrightWhite = 97,
    ForeBrightBlue = 94,
    ForeBrightCyan = 96,
    ForeBrightRed = 91,
  };

  // @

  enum BackColors
  {
    BackDefault = 49,

    BackMagenta = 45,
    BackYellow = 43,
    BackBlack = 40,
    BackGreen = 42,
    BackWhite = 47,
    BackBlue = 44,
    BackCyan = 46,
    BackRed = 41,

    BackBrightMagenta = 105,
    BackBrightYellow = 103,
    BackBrightBlack = 100,
    BackBrightGreen = 101,
    BackBrightWhite = 107,
    BackBrightBlue = 104,
    BackBrightCyan = 106,
    BackBrightRed = 101,
  };

  // @

  enum Modes
  {
    ModeStrikethough = 0x0009,
    ModeUnderline = 0x0004,
    ModeBlinking = 0x0005,
    ModeInverse = 0x0007,
    ModeItalic = 0x0003,
    ModeHidden = 0x0008,
    ModeBold = 0x0001,
    ModeDim = 0x0002,
  };

  // @

  class AnsiManager
  {
    public:
      static void ApplyColors(
        enum ForeColors foreground_color,
        enum BackColors background_color
      );

      //

      static void ApplyColors255(
        std::uint8_t foreground_code,
        std::uint8_t background_code
      );

      //

      static void ApplyColorsRGB(
        struct Color foreground,
        struct Color background
      );

      //

      static void ApplyModes(const std::vector<enum Modes>& modes);
      static void Reset(void);

      //

      static void MoveCursor(
        std::uint32_t line,
        std::uint32_t column
      );

      //

      static void ClearScreen(void);
  };
}; // namespace Bookshelf