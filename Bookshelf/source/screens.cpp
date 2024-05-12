#include "screens.hpp"

// @

void Bookshelf::Screens::Information(void)
{
  Bookshelf::Console::JumpLine();
  Bookshelf::Console::PrintLine(
    0,
    "  888 88b,                     888          888             888  dP,e,\n"
    "  888 88P'  e88 88e   e88 88e  888 ee  dP\"Y 888 ee   ,e e,  888  8b \"\n"
    "  888 8K   d888 888b d888 888b 888 P  C88b  888 88b d88 88b 888 888888\n"
    "  888 88b, Y888 888P Y888 888P 888 b   Y88D 888 888 888   , 888  888\n"
    "  888 88P'  \"88 88\"   \"88 88\"  888 8b d,dP  888 888  \"YeeP\" 888  888\n",
    155, 0, { Bookshelf::Modes::ModeBold }
  );

  //

  Bookshelf::Console::PrintLine(
    2, "(c) 2024 Eduardo Baginski Costa | MIT License",
    231, 0, {}
  );

  Bookshelf::Console::PrintLine(
    2, "https://github.com/eduardobaginskicosta/bookshelf",
    231, 0, {}
  );

  //

  Bookshelf::Console::JumpLine();
  Bookshelf::Console::PrintLine(
    2,
    "\x1B[2m( Type "
    "\x1B[22;1;3m\"help\""
    "\x1B[0;2m or "
    "\x1B[22;1;3m\"?\""
    "\x1B[0;2m to get the commands )",
    0, 0, {}
  );

  Bookshelf::Console::JumpLine();
}

// @

void Bookshelf::Screens::Help(void)
{
  Bookshelf::Console::JumpLine();
  Bookshelf::Console::PrintMessage(
    2,
    "The commands follow the following syntax: "
    "\x1B[2m<command> <optional_term>\x1B[22m",
    Bookshelf::MessageType::MessageInformation
  );

  Bookshelf::Console::JumpLine();
  Bookshelf::Console::PrintLine(
    0,
    "  \x1B[1;3m* \"insert\" \x1B[0m: "
    "Register a new book.\n"

    //

    "  \x1B[1;3m* \"remove\" \x1B[0m: "
    "Remove a book.\n"

    //

    "  \x1B[1;3m* \"export\" \x1B[0m: "
    "Export data to a INI file.\n\n"

    //

    "  \x1B[1;3m* \"search\" \x1B[0m: "
    "List books based on a term.\n"

    //

    "  \x1B[2m    <term> \x1B[0m: "
    "The search term (non-sensitive case).\n"

    //

    "  \x1B[93m     [TIP] \x1B[0m: "
    "Just type \x1B[1;3m\".\"\x1B[0m or \x1B[1;3m\"--all\"\x1B[0m to list all books.\n"

    //

    "  \x1B[93m     [TIP] \x1B[0m: "
    "Type \x1B[1;3m\"<term>\"\x1B[0m for a case-sensitive search.\n\n"

    //

    "  \x1B[1;3m* \"list\"   \x1B[0m: "
    "List all books.\n"

    //

    "  \x1B[1;3m* \"clear\"  \x1B[0m: "
    "Clear the display screen.\n"

    //

    "  \x1B[1;3m* \"exit\"   \x1B[0m: "
    "Close the program.\n",

    0, 0, {}
  );
}
