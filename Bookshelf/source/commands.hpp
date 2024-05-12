#pragma once
#include <iostream>
#include <string>

#include "books_manager.hpp"
#include "file_manager.hpp"
#include "console.hpp"

namespace Bookshelf
{
  class Commands
  {
    public:
      static void Insert(BooksManager& books_manager);

      //

      static void Remove(
        BooksManager& books_manager,
        std::string command
      );

      //

      static void Update(
        BooksManager& books_manager,
        std::string command
      );

      //

      static void Search(
        BooksManager& books_manager,
        std::string command
      );

      //

      static void List(BooksManager& books_manager);

      //

      static void Export(
        BooksManager& books_manager,
        std::string command
      );

      //

      static void Invalid(std::string command);
  };
}; // namespace Bookshelf