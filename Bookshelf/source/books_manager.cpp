#include "books_manager.hpp"
#include "utils.hpp"

// @

bool Bookshelf::BooksManager::_OutOfRange(
  std::uint32_t index
)
{
  return _books.size() <= 0 || index < 0 || index > _books.size();
}

// @

void Bookshelf::BooksManager::Initialize(
  std::string file_name
)
{
  if (!Utils::IsEmptyOrWhitespace(file_name))
  {
    this->Load(file_name);
    _file_name = _file_name;
  }
}

// @

void Bookshelf::BooksManager::Load(
  std::string file_name
)
{
  if (
    !Utils::IsEmptyOrWhitespace(file_name) &&
    FileManager::Exists(file_name)
  )
  {
    if (FileManager::TryLoadBooks(_books, file_name))
    {
      _file_name = _file_name;
    }
  }
}

// @

void Bookshelf::BooksManager::Save(
  std::string file_name
)
{
  if (!Utils::IsEmptyOrWhitespace(file_name))
  {
    FileManager::TrySaveBooks(_books, file_name);
  }
}

// @

void Bookshelf::BooksManager::Save(void)
{
  if (!Utils::IsEmptyOrWhitespace(_file_name))
  {
    FileManager::TrySaveBooks(_books, _file_name);
  }
}

// @

bool Bookshelf::BooksManager::Contains(
  std::uint32_t index
)
{
  return !_OutOfRange(index);
}

// @

bool Bookshelf::BooksManager::Contains(
  std::string name
)
{
  if (Utils::IsEmptyOrWhitespace(name))
  {
    return false;
  }

  for (const struct Bookshelf::Book& book : _books)
  {
    if (book.name == name)
    {
      return true;
    }
  }

  return false;
}

// @

std::vector<struct Bookshelf::Book> Bookshelf::BooksManager::GetAll()
{
  return _books;
}

// @

bool Bookshelf::BooksManager::TryGetAt(
  std::uint32_t index,
  struct Bookshelf::Book& out
)
{
  try
  {
    struct Bookshelf::Book book = GetAt(index);
    out = book;

    return book != BOOK_EMPTY;
  }
  catch (const std::exception& ex)
  {
    out = BOOK_EMPTY;
    return false;
  }
}

// @

struct Bookshelf::Book Bookshelf::BooksManager::GetAt(
  std::uint32_t index
)
{
  if (!Contains(index))
  {
    return Bookshelf::BOOK_EMPTY;
  }

  for (std::uint32_t book_index = 0; book_index < _books.size(); ++book_index)
  {
    if (book_index == index)
    {
      return _books[index];
    }
  }

  return Bookshelf::BOOK_EMPTY;
}

// @

bool Bookshelf::BooksManager::TryGet(
  std::string name,
  struct Bookshelf::Book& out
)
{
  try
  {
    struct Bookshelf::Book book = Get(name);
    out = book;

    return book != BOOK_EMPTY;
  }
  catch (const std::exception& ex)
  {
    out = BOOK_EMPTY;
    return false;
  }
}

// @

struct Bookshelf::Book Bookshelf::BooksManager::Get(
  std::string name
)
{
  if (
    Utils::IsEmptyOrWhitespace(name) ||
    !Contains(name)
  )
  {
    return Bookshelf::BOOK_EMPTY;
  }

  for (const struct Bookshelf::Book& book : _books)
  {
    if (book.name == name)
    {
      return book;
    }
  }

  return Bookshelf::BOOK_EMPTY;
}

// @

bool Bookshelf::BooksManager::TrySetAt(
  std::uint32_t index,
  std::string new_name,
  std::string new_author
)
{
  try
  {
    SetAt(index, new_name, new_author);
    return true;
  }
  catch (const std::exception& ex)
  {
    return false;
  }
}

// @

void Bookshelf::BooksManager::SetAt(
  std::uint32_t index,
  std::string new_name,
  std::string new_author
)
{
  if (
    !Contains(index) ||
    _books.size() <= 0
  )
  {
    return;
  }

  _books[index].name = new_name;
  _books[index].author = new_author;
  _books[index].updated_at = std::time(0);
}

// @

bool Bookshelf::BooksManager::TrySet(
  std::string name,
  std::string new_name,
  std::string new_author
)
{
  try
  {
    Set(name, new_name, new_author);
    return true;
  }
  catch (const std::exception& ex)
  {
    return false;
  }
}

// @

void Bookshelf::BooksManager::Set(
  std::string name,
  std::string new_name,
  std::string new_author
)
{
  if (!Contains(name))
  {
    return;
  }

  for (struct Bookshelf::Book& book : _books)
  {
    if (book.name == name)
    {
      book.name = new_name;
      book.author = new_author;
      book.updated_at = std::time(0);
    }
  }
}

// @

bool Bookshelf::BooksManager::TryRemoveAt(
  std::uint32_t index
)
{
  try
  {
    RemoveAt(index);
    return true;
  }
  catch (const std::exception& ex)
  {
    return false;
  }
}

// @

void Bookshelf::BooksManager::RemoveAt(
  std::uint32_t index
)
{
  if (
    !Contains(index) ||
    _books.size() <= 0
  )
  {
    return;
  }

  _books.erase(_books.begin() + index);
}

// @

bool Bookshelf::BooksManager::TryRemove(
  std::string name
)
{
  try
  {
    Remove(name);
    return true;
  }
  catch (const std::exception& ex)
  {
    return false;
  }
}

// @

void Bookshelf::BooksManager::Remove(
  std::string name
)
{
  if (_books.size() <= 0)
  {
    return;
  }

  for (std::uint32_t index = 0; index < _books.size(); ++index)
  {
    if (_books[index].name == name)
    {
      _books.erase(_books.begin() + index);
      return;
    }
  }
}

// @

bool Bookshelf::BooksManager::TryAdd(
  std::string name,
  std::string author
)
{
  try
  {
    if (Contains(name))
    {
      return false;
    }

    Add(name, author);
    return true;
  }
  catch (const std::exception& ex)
  {
    return false;
  }
}

// @

void Bookshelf::BooksManager::Add(
  std::string name,
  std::string author
)
{
  if (Contains(name))
  {
    return;
  }

  struct Bookshelf::Book book {
    name, author, std::time(0), std::time(0)
  };

  _books.push_back(book);
}

// @

bool Bookshelf::BooksManager::TrySearch(
  std::vector<struct Book>& output,
  std::string term,
  bool case_sensitivity
)
{
  try
  {
    std::vector<struct Book> books = Search(term, case_sensitivity);
    output = books;

    return books.size() > 0;
  }
  catch (const std::exception&)
  {
    output = {};
    return false;
  }
}

// @

std::vector<struct Bookshelf::Book> Bookshelf::BooksManager::Search(
  std::string term,
  bool case_sensitivity
)
{
  if (_books.size() <= 0)
  {
    return {};
  }

  //

  std::vector<struct Bookshelf::Book> books;

  std::string lower_term = term;
  Bookshelf::Utils::ToLowerCase(lower_term);

  //

  for (const struct Bookshelf::Book& book : _books)
  {
    if (lower_term == "." || lower_term == "--all")
    {
      books.push_back(book);
    }
    else
    {
      std::string name = book.name;
      std::string author = book.author;

      if (!case_sensitivity)
      {
        Bookshelf::Utils::ToLowerCase(name);
        Bookshelf::Utils::ToLowerCase(author);
      }

      if (
        name.find(lower_term) != std::string::npos ||
        author.find(lower_term) != std::string::npos
      )
      {
        books.push_back(book);
      }
    }
  }

  //

  return books;
}

// @

std::uint32_t Bookshelf::BooksManager::Lenght(void)
{
  return _books.size();
}

// @

bool Bookshelf::BooksManager::TryExport(
  std::string file_name
)
{
  if (_books.size() <= 0)
  {
    return {};
  }

  //

  try
  {
    Export(file_name);
    return true;
  }
  catch (const std::exception&)
  {
    return false;
  }
}

// @

void Bookshelf::BooksManager::Export(
  std::string file_name
)
{
  if (_books.size() > 0)
  {
    std::ofstream export_file(
      file_name.ends_with(".ini")
        ? file_name
        : file_name + ".ini"
    );

    //

    for (struct Book& book : _books)
    {
      export_file << "[book]\n"
      "name = " + book.name + "\n"
      "author = " + book.author + "\n"
      "inserted_at = " + Bookshelf::Utils::ToAsciiTime(book.inserted_at) +
      "updated_at = " + Bookshelf::Utils::ToAsciiTime(book.updated_at) +
      std::string((book != _books[_books.size() - 1]) ? 1 : 0, '\n');
    }
  }
}

// @

void Bookshelf::BooksManager::Clear(void)
{
  if (_books.size() <= 0)
  {
    return;
  }

  _books.clear();
}
