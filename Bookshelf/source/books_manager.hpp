#pragma once
#include <string>
#include <vector>

#include "file_manager.hpp"
#include "utils.hpp"

namespace Bookshelf
{
  class BooksManager
  {
    private:
      std::vector<struct Book> _books;
      std::string _file_name;

      //

      bool _OutOfRange(std::uint32_t index);

    public:
      void Initialize(std::string file_name);

      //

      void Load(std::string file_name);

      //

      void Save(std::string file_name);
      void Save(void);

      //

      bool Contains(std::uint32_t index);
      bool Contains(std::string name);

      //

      std::vector<struct Book> GetAll(void);

      //

      bool TryGetAt(
        std::uint32_t index,
        struct Bookshelf::Book& out
      );

      struct Book GetAt(std::uint32_t index);

      //

      bool TryGet(
        std::string name,
        struct Bookshelf::Book& out
      );

      struct Book Get(std::string name);

      //

      bool TrySetAt(
        std::uint32_t index,
        std::string new_name,
        std::string new_author
      );

      void SetAt(
        std::uint32_t index,
        std::string new_name,
        std::string new_author
      );

      //

      bool TrySet(
        std::string name,
        std::string new_name,
        std::string new_author
      );

      void Set(
        std::string name,
        std::string new_name,
        std::string new_author
      );

      //

      bool TryRemoveAt(std::uint32_t index);
      void RemoveAt(std::uint32_t index);

      //

      bool TryRemove(std::string name);
      void Remove(std::string name);

      //

      bool TryAdd(
        std::string name,
        std::string author
      );

      void Add(
        std::string name,
        std::string author
      );

      //

      bool TrySearch(
        std::vector<struct Book>& output,
        std::string term,
        bool case_sensitivity
      );

      std::vector<struct Book> Search(
        std::string term,
        bool case_sensitivity
      );

      //

      std::uint32_t Lenght(void);

      //

      bool TryExport(std::string file_name);
      void Export(std::string file_name);

      //

      void Clear(void);
  };
}; // namespace Bookshelf
