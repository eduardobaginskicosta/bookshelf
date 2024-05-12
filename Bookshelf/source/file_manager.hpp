#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <string>
#include <ctime>

namespace Bookshelf
{
  struct Book
  {
    std::string name = "";
    std::string author = "";

    std::time_t inserted_at = std::numeric_limits<std::time_t>::min();
    std::time_t updated_at = std::numeric_limits<std::time_t>::min();

    //

    bool operator ==(const struct Bookshelf::Book other);
    bool operator !=(const struct Bookshelf::Book other);
  };

  // @

  const struct Bookshelf::Book BOOK_EMPTY {
      "", "",
      std::numeric_limits<std::time_t>::min(),
      std::numeric_limits<std::time_t>::min(),
  };

  // @

  class FileManager
  {
    public:
      static void LoadBooks(
        std::vector<struct Book>& books,
        std::string file_name
      );

      //

      static bool TryLoadBooks(
        std::vector<struct Book>& books,
        std::string file_name
      );

      //

      static void SaveBooks(
        std::vector<struct Book>& books,
        std::string file_name
      );

      //

      static bool TrySaveBooks(
        std::vector<struct Book>& books,
        std::string file_name
      );

      //

      static bool Exists(std::string path);
  };
}; // namespace Bookshelf
