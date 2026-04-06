#include <fstream>
#include <iostream>

std::string replaceAll(const std::string &str, const std::string &s1,
                       const std::string &s2) {
  std::string result;
  size_t pos = 0;
  size_t prev = 0;

  while ((pos = str.find(s1, prev)) != std::string::npos) {
    result += str.substr(prev, pos - prev);
    result += s2;
    prev = pos + s1.size();
  }
  result += str.substr(prev);
  return result;
}

int main(int argc, char **argv) {
  std::ifstream infile;
  std::ofstream outfile;
  std::string str, line;

  if (argc != 4) {
    std::cout << "usage: ./replace <file> old_word new_word" << std::endl;
    return (1);
  }
  if (std::string(argv[2]).empty()) {
    std::cout << "Error: old_word cannot be empty." << std::endl;
    return (1);
  }
  infile.open(argv[1]);
  if (infile.fail()) {
    std::cout << "Error: " << argv[1] << ": no such file or directory"
              << std::endl;
    return (1);
  }
  while (std::getline(infile, line)) {
    str += line;
    if (!infile.eof())
      str += "\n";
  }
  infile.close();
  outfile.open((std::string(argv[1]) + ".replace").c_str());
  if (outfile.fail()) {
    std::cout << "Error: " << argv[1] << ": cannot create outfile" << std::endl;
    return (1);
  }
  outfile << replaceAll(str, argv[2], argv[3]);
  outfile.close();
  return (0);
}
