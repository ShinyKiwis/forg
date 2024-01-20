#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include "util.h"
#include "yaml_node.h"

class Parser {
public:
  Parser();
  ~Parser();
  YAMLNode parseYAML(const std::string&);
  std::vector<std::string>& getExts();
private:
  std::vector<std::string> exts;
};
