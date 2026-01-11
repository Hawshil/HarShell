#include <iostream>
#include <string>
#include <filesystem>
#include <cstdlib>

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

    size_t start = 0, i = 0;
    while (i < input.size() && input[i] == ' ')
    {
      i++;
    }
    start = i;
    while (i < input.size() && input[i] != ' ')
    {
      i++;
    }
    size_t len = i - start;

    std::string command = input.substr(start, len);

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
      std::string target = input.substr(5);

      if (target == "exit" || target == "echo" || target == "type")
      {
        std::cout << target << " is a shell builtin" << std::endl;
      }
      else
      {
        namespace fs = std::filesystem;
        const char *path_cstr = std::getenv("PATH");

        if (!path_cstr)
        {
          std::cout << target << ": not found" << std::endl;
        }
        else
        {
          std::string path(path_cstr);
          std::string dir;
          bool found = false;

          for (size_t i = 0; i <= path.length(); i++)
          {
            if (i == path.length() || path[i] == ':')
            {
              if (!dir.empty())
              {
                fs::path full_path = fs::path(dir) / target;
                if (fs::exists(full_path) &&
                    fs::is_regular_file(full_path) &&
                    (fs::status(full_path).permissions() & fs::perms::owner_exec) != fs::perms::none)
                {
                  std::cout << target << " is " << dir << "/" << target << std::endl;
                  found = true;
                  break;
                }
              }
              dir.clear();
            }
            else
            {
              dir.push_back(path[i]);
            }
          }

          if (!found)
          {
            std::cout << target << ": not found" << std::endl;
          }
        }
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
