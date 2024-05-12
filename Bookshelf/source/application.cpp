#include "application.hpp"

// @

Bookshelf::Application::Application(
  std::string file_name
)
{
  _books_manager.Initialize(file_name);
  _file_name = file_name;
}

// @

std::uint32_t Bookshelf::Application::Initialize(void)
{
  Bookshelf::Screens::Information();
  std::string command;

  while (command != "exit")
  {
    Bookshelf::Console::Prompt(
      command, 0, "::",
      Bookshelf::ForeColors::ForeBrightWhite,
      Bookshelf::BackColors::BackDefault,
      Bookshelf::ForeColors::ForeBrightYellow,
      Bookshelf::BackColors::BackDefault
    );

    _ProcessCommand(command);
    _books_manager.Save(_file_name);
  }

  return 0;
}

// @

void Bookshelf::Application::_ProcessCommand(
  std::string command
)
{
  std::string lower_command = command;
  Bookshelf::Utils::ToLowerCase(lower_command);

  //

  if (lower_command == "exit")
  {
    return;
  }

  //

  else if (
    lower_command == "clear" ||
    lower_command == "cls"
  )
  {
    Bookshelf::Console::Clear();
  }

  //

  else if (
    lower_command == "help" ||
    lower_command == "?"
  )
  {
    Bookshelf::Screens::Help();
  }

  //

  else if (lower_command == "insert")
  {
    Bookshelf::Commands::Insert(_books_manager);
  }

  //

  else if (lower_command.starts_with("remove"))
  {
    Bookshelf::Commands::Remove(_books_manager, command);
  }

  //

  else if (lower_command.starts_with("update"))
  {
    Bookshelf::Commands::Update(_books_manager, command);
  }

  //

  else if (lower_command.starts_with("search"))
  {
    Bookshelf::Commands::Search(_books_manager, command);
  }

  //

  else if (lower_command == "list")
  {
    Bookshelf::Commands::List(_books_manager);
  }

  //

  else if (lower_command.starts_with("export"))
  {
    Bookshelf::Commands::Export(_books_manager, command);
  }

  //

  else
  {
    Bookshelf::Commands::Invalid(command);
  }
}
