#pragma once
#include <iostream>
#include <fstream>
#include <map>

class Parser {
public:
  Parser();
  ~Parser();
  std::map<std::string, std::string>parseYAML(const std::string&);
};
