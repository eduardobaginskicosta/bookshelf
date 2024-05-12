cmake_minimum_required (VERSION 3.8)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Bookshelf")
add_executable (Bookshelf  "source/main.cpp" "source/file_manager.cpp" "source/books_manager.cpp" "source/utils.cpp" "source/ansi_manager.cpp" "source/console.cpp" "source/screens.cpp" "source/application.cpp" "source/commands.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Bookshelf PROPERTY CXX_STANDARD 20)
endif()