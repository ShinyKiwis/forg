#pragma once
#include <iostream>
#include <filesystem>
#include <fstream>
#include <map>
#include <cstdlib>
#include "parser.h"
#include "yaml_node.h"

class Config {
public:
  Config(std::string);
  ~Config();

  YAMLNode getConfigs() const;
private:
  Parser parser;
  YAMLNode configs;
  std::string configPath = "";
  std::string configFilePath = "";
  void initializeConfigFolder();
  const char* getHomeDir();
  bool isFolderExist(std::string);
};
