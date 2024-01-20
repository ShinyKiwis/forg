#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include "util.h"
#include "yaml_node.h"

class Parser {
public:
  Parser();
  ~Parser();
  YAMLNode parseYAML(const std::string&);
};
