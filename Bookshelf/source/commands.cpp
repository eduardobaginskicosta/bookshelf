#include "commands.hpp"

// @

void Bookshelf::Commands::Insert(
  BooksManager& books_manager
)
{
  Bookshelf::Console::JumpLine();
  std::vector<std::string> inputs = Bookshelf::Console::MultiPrompt(
    2, { "Book's name :", "Book's author :" },
    Bookshelf::ForeColors::ForeBrightWhite,
    Bookshelf::BackColors::BackDefault,
    Bookshelf::ForeColors::ForeBrightYellow,
    Bookshelf::BackColors::BackDefault
  );

  //

  std::string temp_name = inputs.size() >= 1 ? inputs[0] : "";
  std::string temp_author = inputs.size() >= 2 ? inputs[1] : "";

  //

  if (
    Bookshelf::Utils::IsEmptyOrWhitespace(temp_name) ||
    Bookshelf::Utils::IsEmptyOrWhitespace(temp_author)
  )
  {
    Bookshelf::Console::JumpLine();
    Bookshelf::Console::PrintMessage(
      2, "Operation canceled", Bookshelf::MessageType::MessageAlert
    );
    Bookshelf::Console::JumpLine();

    return;
  }

  //

  Bookshelf::Console::JumpLine();

  if (books_manager.TryAdd(temp_name, temp_author))
  {
    Bookshelf::Console::PrintMessage(
      2, "OK", Bookshelf::MessageType::MessageSuccess
    );
  }
  else
  {
    Bookshelf::Console::PrintMessage(
      2, "The book is already registered",
      Bookshelf::MessageType::MessageAlert
    );
  }

  Bookshelf::Console::JumpLine();
}

// @

void Bookshelf::Commands::Remove(
  BooksManager& books_manager,
  std::string command
)
{
  if (books_manager.Lenght() <= 0)
  {
    Bookshelf::Console::JumpLine();
    Bookshelf::Console::PrintMessage(
      2, "There are no registered books",
      Bookshelf::MessageType::MessageAlert
    );
    Bookshelf::Console::JumpLine();

    return;
  }

  //

  std::string lower_command = command;
  Bookshelf::Utils::ToLowerCase(lower_command);

  std::string name = (
    lower_command.starts_with("remove ") &&
    lower_command.length() > 7
  ) ? command.substr(7) : "";

  //

  if (Bookshelf::Utils::IsEmptyOrWhitespace(name))
  {
    Bookshelf::Console::JumpLine();
    Bookshelf::Console::Prompt(
      name, 2, "Book's name :",
      Bookshelf::ForeColors::ForeBrightWhite,
      Bookshelf::BackColors::BackDefault,
      Bookshelf::ForeColors::ForeBrightYellow,
      Bookshelf::BackColors::BackDefault
    );
  }

  //

  if (Bookshelf::Utils::IsEmptyOrWhitespace(name))
  {
    Bookshelf::Console::JumpLine();
    Bookshelf::Console::PrintMessage(
      2, "Operation canceled", Bookshelf::MessageType::MessageAlert
    );
    Bookshelf::Console::JumpLine();

    return;
  }

  //

  Bookshelf::Console::JumpLine();

  if (books_manager.TryRemove(name))
  {
    Bookshelf::Console::PrintMessage(
      2, "OK", Bookshelf::MessageType::MessageSuccess
    );
  }
  else
  {
    Bookshelf::Console::PrintMessage(
      2, "Failed to remove book", Bookshelf::MessageType::MessageError
    );
  }

  Bookshelf::Console::JumpLine();
}

// @

void Bookshelf::Commands::Update(
  BooksManager& books_manager,
  std::string command
)
{
  if (books_manager.Lenght() <= 0)
  {
    Bookshelf::Console::JumpLine();
    Bookshelf::Console::PrintMessage(
      2, "There are no registered books",
      Bookshelf::MessageType::MessageAlert
    );
    Bookshelf::Console::JumpLine();

    return;
  }

  //

  std::string lower_command = command;
  Bookshelf::Utils::ToLowerCase(lower_command);

  std::string name = lower_command.starts_with("update ") && lower_command.length() > 7
    ? command.substr(7) : "";

  //

  if (Bookshelf::Utils::IsEmptyOrWhitespace(name))
  {
    Bookshelf::Console::JumpLine();
    Bookshelf::Console::Prompt(
      name, 2, "Book's name :",
      Bookshelf::ForeColors::ForeBrightWhite,
      Bookshelf::BackColors::BackDefault,
      Bookshelf::ForeColors::ForeBrightYellow,
      Bookshelf::BackColors::BackDefault
    );
    Bookshelf::Console::JumpLine();
  }

  //

  if (Bookshelf::Utils::IsEmptyOrWhitespace(name))
  {
    Bookshelf::Console::PrintMessage(
      2, "Operation canceled", Bookshelf::MessageType::MessageAlert
    );
    Bookshelf::Console::JumpLine();

    return;
  }

  //

  if (books_manager.Contains(name))
  {
    Bookshelf::Console::JumpLine();
    std::vector<std::string> inputs = Bookshelf::Console::MultiPrompt(
      2, { "New book's name :", "New book's author :" },
      Bookshelf::ForeColors::ForeBrightWhite,
      Bookshelf::BackColors::BackDefault,
      Bookshelf::ForeColors::ForeBrightYellow,
      Bookshelf::BackColors::BackDefault
    );

    //

    std::string temp_title = inputs.size() >= 1 ? inputs[0] : "";
    std::string temp_author = inputs.size() >= 2 ? inputs[1] : "";

    //

    Bookshelf::Console::JumpLine();

    if (books_manager.TrySet(name, temp_title, temp_author))
    {
      Bookshelf::Console::PrintMessage(
        2, "OK", Bookshelf::MessageType::MessageSuccess
      );
    }
    else
    {
      Bookshelf::Console::PrintMessage(
        2, "Failed to update book", Bookshelf::MessageType::MessageError
      );
    }

    Bookshelf::Console::JumpLine();
  }

  //

  else
  {
    Bookshelf::Console::JumpLine();
    Bookshelf::Console::PrintMessage(
      2, "No book matches that name",
      Bookshelf::MessageType::MessageAlert
    );
    Bookshelf::Console::JumpLine();
  }
}

// @

void Bookshelf::Commands::Search(
  BooksManager& books_manager,
  std::string command
)
{
  if (books_manager.Lenght() <= 0)
  {
    Bookshelf::Console::JumpLine();
    Bookshelf::Console::PrintMessage(
      2, "There are no registered books",
      Bookshelf::MessageType::MessageAlert
    );
    Bookshelf::Console::JumpLine();

    return;
  }

  //

  std::string lower_command = command;
  Bookshelf::Utils::ToLowerCase(lower_command);

  std::string search_term = (
    lower_command.starts_with("search ") &&
    lower_command.length() > 7
  ) ? command.substr(7) : "";

  //

  if (Bookshelf::Utils::IsEmptyOrWhitespace(search_term))
  {
    Bookshelf::Console::JumpLine();
    Bookshelf::Console::Prompt(
      search_term, 2, "Search term :",
      Bookshelf::ForeColors::ForeBrightWhite,
      Bookshelf::BackColors::BackDefault,
      Bookshelf::ForeColors::ForeBrightYellow,
      Bookshelf::BackColors::BackDefault
    );
    Bookshelf::Console::JumpLine();
  }

  //

  if (Bookshelf::Utils::IsEmptyOrWhitespace(search_term))
  {
    Bookshelf::Console::PrintMessage(
      2, "Operation canceled", Bookshelf::MessageType::MessageAlert
    );
    Bookshelf::Console::JumpLine();

    return;
  }

  //

  bool case_sensitivity = (
    search_term.starts_with("\"") &&
    search_term.ends_with("\"") &&
    search_term.length() >= 3
  );

  std::string formatted_term = case_sensitivity
    ? search_term.substr(1, search_term.length() - 2)
    : search_term;

  //

  std::vector<struct Bookshelf::Book> books;

  if (books_manager.TrySearch(books, formatted_term, case_sensitivity))
  {
    Bookshelf::Console::JumpLine();
    Bookshelf::Console::PrintLine(
      2,
      "\x1B[2m( \x1B[0;1;3m\"" + std::to_string(books_manager.Lenght()) +
      "\"\x1B[0;2m found books )",
      0, 0, {}
    );
    Bookshelf::Console::JumpLine();

    //

    for (const struct Bookshelf::Book& book : books)
    {
      Bookshelf::Console::PrintLine(
        0,
        "  \x1B[1;3mName        \x1B[0m: " + book.name + "\n" +
        "  \x1B[1;3mAuthor      \x1B[0m: " + book.author + "\n" +
        
        "  \x1B[1;3mInserted At \x1B[0m: " +
        Bookshelf::Utils::ToAsciiTime(book.inserted_at) +

        "  \x1B[1;3mUpdated At  \x1B[0m: " +
        Bookshelf::Utils::ToAsciiTime(book.updated_at),
        0, 0, {}
      );
    }

    //

    Bookshelf::Console::PrintMessage(
      2, "OK", Bookshelf::MessageType::MessageSuccess
    );
    Bookshelf::Console::JumpLine();
  }

  //

  else
  {
    Bookshelf::Console::JumpLine();
    Bookshelf::Console::PrintMessage(
      2, "No books matches that terms",
      Bookshelf::MessageType::MessageAlert
    );
    Bookshelf::Console::JumpLine();
  } 
}

// @

void Bookshelf::Commands::List(
  BooksManager& books_manager
)
{
  if (books_manager.Lenght() <= 0)
  {
    Bookshelf::Console::JumpLine();
    Bookshelf::Console::PrintMessage(
      2, "There are no registered books",
      Bookshelf::MessageType::MessageAlert
    );
    Bookshelf::Console::JumpLine();

    return;
  }

  //
  
  for (const struct Bookshelf::Book& book : books_manager.GetAll())
  {
    Bookshelf::Console::JumpLine();
    Bookshelf::Console::PrintLine(
      0,
      "  \x1B[1;3mName        \x1B[0m: " + book.name + "\n" +
      "  \x1B[1;3mAuthor      \x1B[0m: " + book.author + "\n" +

      "  \x1B[1;3mInserted At \x1B[0m: " +
      Bookshelf::Utils::ToAsciiTime(book.inserted_at)+

      "  \x1B[1;3mUpdated At  \x1B[0m: " +
      Bookshelf::Utils::ToAsciiTime(book.updated_at),
      0, 0, {}
    );
  }

  //

  Bookshelf::Console::PrintMessage(
    2, "OK", Bookshelf::MessageType::MessageSuccess
  );
  Bookshelf::Console::JumpLine();
}

// @

void Bookshelf::Commands::Export(
  BooksManager& books_manager,
  std::string command
)
{
  if (books_manager.Lenght() <= 0)
  {
    Bookshelf::Console::JumpLine();
    Bookshelf::Console::PrintMessage(
      2, "There are no registered books",
      Bookshelf::MessageType::MessageAlert
    );
    Bookshelf::Console::JumpLine();

    return;
  }

  //

  std::string lower_command = command;
  Bookshelf::Utils::ToLowerCase(lower_command);

  std::string output = lower_command.starts_with("export ") && lower_command.length() > 7
    ? command.substr(7) : "";

  //

  if (Bookshelf::Utils::IsEmptyOrWhitespace(output))
  {
    Bookshelf::Console::JumpLine();
    Bookshelf::Console::Prompt(
      output, 2, "Output file name :",
      Bookshelf::ForeColors::ForeBrightWhite,
      Bookshelf::BackColors::BackDefault,
      Bookshelf::ForeColors::ForeBrightYellow,
      Bookshelf::BackColors::BackDefault
    );
  }

  //

  if (Bookshelf::Utils::IsEmptyOrWhitespace(output))
  {
    Bookshelf::Console::JumpLine();
    Bookshelf::Console::PrintMessage(
      2, "Operation canceled", Bookshelf::MessageType::MessageAlert
    );
    Bookshelf::Console::JumpLine();

    return;
  }

  //

  if (books_manager.TryExport(output))
  {
    Bookshelf::Console::JumpLine();
    Bookshelf::Console::PrintMessage(
      2, "OK", Bookshelf::MessageType::MessageSuccess
    );
    Bookshelf::Console::JumpLine();
  }

  //

  else
  {
    Bookshelf::Console::JumpLine();
    Bookshelf::Console::PrintMessage(
      2, "Failed to export books", Bookshelf::MessageType::MessageError
    );
    Bookshelf::Console::JumpLine();
  }
}

// @

void Bookshelf::Commands::Invalid(
  std::string command
)
{
  if (!Bookshelf::Utils::IsEmptyOrWhitespace(command))
  {
    Bookshelf::Console::JumpLine();
    Bookshelf::Console::PrintMessage(
      2, "The \x1B[1;3;93m\"" + command + "\"\x1B[0m command is invalid.",
      Bookshelf::MessageType::MessageError
    );
    Bookshelf::Console::JumpLine();
  }
}
