#include <iostream>
#include <string>
#include <sstream>

int main()
{
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  std::cout << "$ ";
  std::string input;

  while (true)
  {
    std::getline(std::cin, input);

    std::string command;
    std::stringstream ss(input);
    ss >> command;

    if (command == "exit")
    {
      break;
    }
    else if (command == "echo")
    {
      std::cout << input.substr(5) << std::endl;
    }
    else if (command == "type")
    {
      std::string builtin = input.substr(5, 4);
      if (builtin == "exit" || builtin == "echo" || builtin == "type")
      {
        std::cout << builtin << " is a shell builtin" << std::endl;
      }
    }
    else
    {
      std::cout << input << ": command not found" << std::endl;
    }

    std::cout << "$ ";
  }

  return 0;
}
