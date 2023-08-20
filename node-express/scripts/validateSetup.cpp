#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

std::unordered_map<std::string, std::regex> mp = {{"PORT", std::regex("^\\d+$")}, {"BASE_URL", std::regex("^\\w+$")}};

bool isValid(std::string& s) {
  std::stringstream ss(s);
  std::string s1;

  std::vector<std::string> kv;

  while(getline(ss, s1, '=')) {
    kv.push_back(s1);
  }

  if(!std::regex_match(kv[1], mp[kv[0]])) {
    return false;
  }
  return true;
}

int read_file(const std::string& file) {
  std::ifstream in(file);
  std::string s;

  std::regex line_regex("\\w+=\\w+");

  int error = 0;

  while(std::getline(in, s)) {
    if(!std::regex_match(s, line_regex)) {
      error = 1;
    }

    if(!isValid(s)) {
      std::cout << "\x1b[41m%s\x1b[0m" << file << "is not valid" << "\n";
      error = 1;
    }
  }
  std::cout << "\x1b[42m" << file << "\x1b[0m" <<  "is valid" << "\n";

  return error ? 2 : 0;
}

int main() {
  std::vector<std::string> env_files;
  std::regex env_file_regex ("\\.env(?!\\.example)(\\.\\w+)?");
  char key[200], value[200];

  auto current_path = fs::current_path();

  for(const auto& file : fs::directory_iterator(current_path)) {
    if(std::regex_search(file.path().string(), env_file_regex)) {
      env_files.push_back(file.path().string());
    }
  }

  for(const auto& env_file : env_files) {
    if(read_file(env_file) == 2) {
      exit(2);
    };
  }

  if(env_files.size() == 0) {
    std::cout << "\x1b[31m" << "ENV files not found" << "\x1b[0m\n" << "\n";
    exit(2);
  }

  exit(0);
}
