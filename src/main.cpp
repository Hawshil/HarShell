#include <iostream>
#include <string>

int main()
{
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  std::cout << "$ ";
  std::string command;
  while (true)
  {
    std::getline(std::cin, command);
    std::cout << command << ": command not found" << std::endl;
    std::cout << "$ ";
  }

  return 0;
}
