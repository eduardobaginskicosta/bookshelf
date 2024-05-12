#include "file_manager.hpp"
#include "utils.hpp"

// @

bool Bookshelf::Book::operator ==(
  const struct Bookshelf::Book other
  )
{
  return (
    name == other.name &&
    author == other.author &&
    inserted_at == other.inserted_at &&
    updated_at == other.updated_at
  );
}

// @

bool Bookshelf::Book::operator !=(
  const struct Bookshelf::Book other
  )
{
  return (
    name != other.name ||
    author != other.author ||
    inserted_at != other.inserted_at ||
    updated_at != other.updated_at
  );
}

// @

void Bookshelf::FileManager::LoadBooks(
  std::vector<struct Book>& books,
  std::string file_name
)
{
  std::ifstream file(file_name, std::ios::binary);
  std::vector<struct Bookshelf::Book> list;

  while (file.peek() != std::iostream::traits_type::eof())
  {
    struct Bookshelf::Book book;
    std::size_t size;

    //

    file.read(reinterpret_cast<char*>(&size), sizeof(std::size_t));
    book.name.resize(size);
    file.read(&book.name[0], size);

    //

    file.read(reinterpret_cast<char*>(&size), sizeof(std::size_t));
    book.author.resize(size);
    file.read(&book.author[0], size);

    //

    file.read(reinterpret_cast<char*>(&book.inserted_at), sizeof(std::time_t));
    file.read(reinterpret_cast<char*>(&book.updated_at), sizeof(std::time_t));

    //

    list.push_back(book);
  }

  books = list;
  file.close();
}

// @

bool Bookshelf::FileManager::TryLoadBooks(
  std::vector<struct Book>& books,
  std::string file_name
)
{
  try
  {
    if (
      Utils::IsEmptyOrWhitespace(file_name) ||
      !Exists(file_name)
    )
    {
      return false;
    }

    Bookshelf::FileManager::LoadBooks(books, file_name);
    return true;
  }
  catch (const std::exception&)
  {
    return false;
  }
}

// @

void Bookshelf::FileManager::SaveBooks(
  std::vector<struct Book>& books,
  std::string file_name
)
{
  std::ofstream file(file_name, std::ios::binary);

  for (const struct Bookshelf::Book& book : books)
  {
    std::size_t size = book.name.size();
    file.write(reinterpret_cast<const char*>(&size), sizeof(std::size_t));
    file.write(book.name.c_str(), size);

    //

    size = book.author.size();
    file.write(reinterpret_cast<const char*>(&size), sizeof(std::size_t));
    file.write(book.author.c_str(), size);

    //

    file.write(reinterpret_cast<const char*>(&book.inserted_at), sizeof(std::time_t));
    file.write(reinterpret_cast<const char*>(&book.updated_at), sizeof(std::time_t));
  }

  file.close();
}

// @

bool Bookshelf::FileManager::TrySaveBooks(
  std::vector<struct Book>& books,
  std::string file_name
)
{
  try
  {
    Bookshelf::FileManager::SaveBooks(books, file_name);
    return true;
  }
  catch (const std::exception&)
  {
    return false;
  }
}

// @

bool Bookshelf::FileManager::Exists(
  std::string path
)
{
  struct stat info;
  return stat(path.c_str(), &info) == 0;
}
