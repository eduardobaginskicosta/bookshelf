#include "ansi_manager.hpp"
#include "console.hpp"

// @

void Bookshelf::Console::JumpLine(
  std::uint32_t count
)
{
  if (count > 0)
  {
    std::cout << std::string(count, '\n');
  }
}

// @

void Bookshelf::Console::JumpLine(void)
{
  Bookshelf::Console::JumpLine(1);
}

// @

void Bookshelf::Console::PrintLine(
  std::uint8_t margin_left,
  std::string text,
  enum ForeColors foreground_color,
  enum BackColors background_color,
  const std::vector<enum Modes>& modes
)
{
  Bookshelf::Console::Print(
    margin_left, text, foreground_color, background_color, modes
  );
  Bookshelf::Console::JumpLine();
}

// @

void Bookshelf::Console::PrintLine(
  std::uint8_t margin_left,
  std::string text,
  std::uint8_t foreground_color,
  std::uint8_t background_color,
  const std::vector<enum Modes>& modes
)
{
  Bookshelf::Console::Print(
    margin_left, text, foreground_color, background_color, modes
  );
  Bookshelf::Console::JumpLine();
}

// @

void Bookshelf::Console::PrintLine(
  std::uint8_t margin_left,
  std::string text,
  struct Color foreground,
  struct Color background,
  const std::vector<enum Modes>& modes
)
{
  Bookshelf::Console::Print(margin_left, text, foreground, background, modes);
  Bookshelf::Console::JumpLine();
}

// @

void Bookshelf::Console::Print(
  std::uint8_t margin_left,
  std::string text,
  enum ForeColors foreground_color,
  enum BackColors background_color,
  const std::vector<enum Modes>& modes
)
{
  Bookshelf::AnsiManager::ApplyColors(foreground_color, background_color);
  Bookshelf::AnsiManager::ApplyModes(modes);
  std::cout << std::string(margin_left, ' ') << text;

  Bookshelf::AnsiManager::Reset();
}

// @

void Bookshelf::Console::Print(
  std::uint8_t margin_left,
  std::string text,
  std::uint8_t foreground_color,
  std::uint8_t background_color,
  const std::vector<enum Modes>& modes
)
{
  Bookshelf::AnsiManager::ApplyColors255(foreground_color, background_color);
  Bookshelf::AnsiManager::ApplyModes(modes);
  std::cout << std::string(margin_left, ' ') << text;

  Bookshelf::AnsiManager::Reset();
}

// @

void Bookshelf::Console::Print(
  std::uint8_t margin_left,
  std::string text,
  struct Color foreground,
  struct Color background,
  const std::vector<enum Modes>& modes
)
{
  Bookshelf::AnsiManager::ApplyColorsRGB(foreground, background);
  Bookshelf::AnsiManager::ApplyModes(modes);
  std::cout << std::string(margin_left, ' ') << text;

  Bookshelf::AnsiManager::Reset();
}

// @

void Bookshelf::Console::PrintMessage(
  std::uint8_t margin_left,
  std::string text,
  enum MessageType message_type
)
{
  std::cout << std::string(margin_left, ' ');

  switch (message_type)
  {
  case Bookshelf::MessageType::MessageInformation:
    Bookshelf::AnsiManager::ApplyColors255(33, 0);
    Bookshelf::AnsiManager::ApplyModes({ Bookshelf::Modes::ModeBold });
    std::cout << "[?]";
    break;

  case Bookshelf::MessageType::MessageSuccess:
    Bookshelf::AnsiManager::ApplyColors255(41, 0);
    Bookshelf::AnsiManager::ApplyModes({ Bookshelf::Modes::ModeBold });
    std::cout << "[+]";
    break;

  case Bookshelf::MessageType::MessageError:
    Bookshelf::AnsiManager::ApplyColors255(196, 0);
    Bookshelf::AnsiManager::ApplyModes({ Bookshelf::Modes::ModeBold });
    std::cout << "[-]";
    break;

  case Bookshelf::MessageType::MessageAlert:
    Bookshelf::AnsiManager::ApplyColors255(208, 0);
    Bookshelf::AnsiManager::ApplyModes({ Bookshelf::Modes::ModeBold });
    std::cout << "[&]";
    break;

  default:
    Bookshelf::AnsiManager::ApplyColors255(33, 0);
    Bookshelf::AnsiManager::ApplyModes({ Bookshelf::Modes::ModeBold });
    std::cout << "[?]";
    break;
  }

  Bookshelf::AnsiManager::Reset();
  std::cout << " " << text;
  Bookshelf::Console::JumpLine();
}

// @

void Bookshelf::Console::Prompt(
  std::string& output,
  std::uint8_t margin_left,
  std::string label,
  enum ForeColors label_foreground_color,
  enum BackColors label_background_color,
  enum ForeColors foreground_color,
  enum BackColors background_color
)
{
  if (label.length() > 0)
  {
    Bookshelf::Console::Print(
      margin_left,
      label + (label.ends_with(" ") ? '\0' : ' '),
      label_foreground_color,
      label_background_color,
      { Bookshelf::Modes::ModeBold }
    );
  }
  else
  {
    std::cout << std::string(margin_left, ' ');
  }

  Bookshelf::AnsiManager::ApplyColors(foreground_color, background_color);
  std::getline(std::cin, output);
  Bookshelf::AnsiManager::Reset();
}

// @

void Bookshelf::Console::Prompt(
  std::string& output,
  std::uint8_t margin_left,
  std::string label,
  std::uint8_t label_foreground_code,
  std::uint8_t label_background_code,
  std::uint8_t foreground_code,
  std::uint8_t background_code
)
{
  if (label.length() > 0)
  {
    Bookshelf::Console::Print(
      margin_left,
      label + (label.ends_with(" ") ? '\0' : ' '),
      label_foreground_code,
      label_background_code,
      { Bookshelf::Modes::ModeBold }
    );
  }
  else
  {
    std::cout << std::string(margin_left, ' ');
  }

  Bookshelf::AnsiManager::ApplyColors255(foreground_code, background_code);
  std::getline(std::cin, output);
  Bookshelf::AnsiManager::Reset();
}

// @

void Bookshelf::Console::Prompt(
  std::string& output,
  std::uint8_t margin_left,
  std::string label,
  struct Color label_foreground,
  struct Color label_background,
  struct Color foreground,
  struct Color background
)
{
  if (label.length() > 0)
  {
    Bookshelf::Console::Print(
      margin_left, label,
      label_foreground,
      label_background,
      { Bookshelf::Modes::ModeBold }
    );
    std::cout << " ";
  }
  else
  {
    std::cout << std::string(margin_left, ' ');
  }

  Bookshelf::AnsiManager::ApplyColorsRGB(foreground, background);
  std::getline(std::cin, output);
  Bookshelf::AnsiManager::Reset();
}

// @

std::vector<std::string> Bookshelf::Console::MultiPrompt(
  std::uint8_t margin_left,
  const std::vector<std::string> labels,
  enum ForeColors label_foreground_color,
  enum BackColors label_background_color,
  enum ForeColors foreground_color,
  enum BackColors background_color
)
{
  if (labels.size() <= 0)
  {
    return {};
  }
  
  //

  std::vector<std::string> inputs;
  std::string temp = "";

  //

  for (std::uint32_t index = 0; index < labels.size(); ++index)
  {
    Bookshelf::Console::Prompt(
      temp, margin_left, labels[index],
      label_foreground_color, label_background_color,
      foreground_color, background_color
    );

    inputs.push_back(temp);
  }

  //

  return inputs;
}

// @

std::vector<std::string> Bookshelf::Console::MultiPrompt(
  std::uint8_t margin_left,
  const std::vector<std::string> labels,
  std::uint8_t label_foreground_code,
  std::uint8_t label_background_code,
  std::uint8_t foreground_code,
  std::uint8_t background_code
)
{
  if (labels.size() <= 0)
  {
    return {};
  }

  //

  std::vector<std::string> inputs;
  std::string temp = "";

  //

  for (std::uint32_t index = 0; index < labels.size(); ++index)
  {
    Bookshelf::Console::Prompt(
      temp, margin_left, labels[index],
      label_foreground_code, label_background_code,
      foreground_code, background_code
    );

    inputs.push_back(temp);
  }

  //

  return inputs;
}

// @

std::vector<std::string> Bookshelf::Console::MultiPrompt(
  std::uint8_t margin_left,
  const std::vector<std::string> labels,
  struct Color label_foreground,
  struct Color label_background,
  struct Color foreground,
  struct Color background
)
{
  if (labels.size() <= 0)
  {
    return {};
  }

  //

  std::vector<std::string> inputs;
  std::string temp = "";

  //

  for (std::uint32_t index = 0; index < labels.size(); ++index)
  {
    Bookshelf::Console::Prompt(
      temp, margin_left, labels[index],
      label_foreground, label_background,
      foreground, background
    );

    inputs.push_back(temp);
  }

  //

  return inputs;
}

// @

void Bookshelf::Console::Clear(void)
{
  Bookshelf::AnsiManager::ClearScreen();
  Bookshelf::AnsiManager::MoveCursor(1, 1);
}
