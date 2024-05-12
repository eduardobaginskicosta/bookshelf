#pragma once
#include <iostream>
#include "application.hpp"

std::uint32_t main(void)
{
  Bookshelf::Application application("books.bin");
  return application.Initialize();
}