#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "ansi_manager.hpp"

namespace Bookshelf
{
  enum MessageType
  {
    MessageInformation,
    MessageSuccess,
    MessageError,
    MessageAlert,
  };

  // @

  class Console
  {
    public:
      static void JumpLine(std::uint32_t count);
      static void JumpLine(void);

      //

      static void PrintLine(
        std::uint8_t margin_left,
        std::string text,
        enum ForeColors foreground_color,
        enum BackColors background_color,
        const std::vector<enum Modes>& modes
      );

      //

      static void PrintLine(
        std::uint8_t margin_left,
        std::string text,
        std::uint8_t foreground_color,
        std::uint8_t background_color,
        const std::vector<enum Modes>& modes
      );

      //

      static void PrintLine(
        std::uint8_t margin_left,
        std::string text,
        struct Color foreground,
        struct Color background,
        const std::vector<enum Modes>& modes
      );

      //

      static void Print(
        std::uint8_t margin_left,
        std::string text,
        enum ForeColors foreground_color,
        enum BackColors background_color,
        const std::vector<enum Modes>& modes
      );

      //

      static void Print(
        std::uint8_t margin_left,
        std::string text,
        std::uint8_t foreground_color,
        std::uint8_t background_color,
        const std::vector<enum Modes>& modes
      );

      //

      static void Print(
        std::uint8_t margin_left,
        std::string text,
        struct Color foreground,
        struct Color background,
        const std::vector<enum Modes>& modes
      );

      //

      static void PrintMessage(
        std::uint8_t margin_left,
        std::string text,
        enum MessageType message_type
      );

      //

      static void Prompt(
        std::string& output,
        std::uint8_t margin_left,
        std::string label,
        enum ForeColors label_foreground_color,
        enum BackColors label_background_color,
        enum ForeColors foreground_color,
        enum BackColors background_color
      );

      //

      static void Prompt(
        std::string& output,
        std::uint8_t margin_left,
        std::string label,
        std::uint8_t label_foreground_code,
        std::uint8_t label_background_code,
        std::uint8_t foreground_code,
        std::uint8_t background_code
      );

      //

      static void Prompt(
        std::string& output,
        std::uint8_t margin_left,
        std::string label,
        struct Color label_foreground,
        struct Color label_background,
        struct Color foreground,
        struct Color background
      );

      //

      static std::vector<std::string> MultiPrompt(
        std::uint8_t margin_left,
        const std::vector<std::string> labels,
        enum ForeColors label_foreground_color,
        enum BackColors label_background_color,
        enum ForeColors foreground_color,
        enum BackColors background_color
      );

      //

      static std::vector<std::string> MultiPrompt(
        std::uint8_t margin_left,
        const std::vector<std::string> labels,
        std::uint8_t label_foreground_code,
        std::uint8_t label_background_code,
        std::uint8_t foreground_code,
        std::uint8_t background_code
      );

      //

      static std::vector<std::string> MultiPrompt(
        std::uint8_t margin_left,
        const std::vector<std::string> labels,
        struct Color label_foreground,
        struct Color label_background,
        struct Color foreground,
        struct Color background
      );

      //

      static void Clear(void);
  };
}; // namespace Bookshelf