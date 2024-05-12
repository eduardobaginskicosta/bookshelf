#pragma once
#include "books_manager.hpp"
#include "file_manager.hpp"
#include "commands.hpp"
#include "screens.hpp"
#include "console.hpp"
#include "utils.hpp"

namespace Bookshelf
{
  class Application
  {
    private:
      BooksManager _books_manager;
      std::string _file_name = "";

      //

      void _ProcessCommand(std::string command);

    public:
      Application(std::string file_name);
      std::uint32_t Initialize();
  };
}; // namespace Bookshelf