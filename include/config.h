#pragma once
#include <iostream>
#include <filesystem>
#include <fstream>
#include <map>
#include <vector>
#include <cstdlib>
#include "parser.h"
#include "yaml_node.h"

class Config {
public:
  Config(const std::string&);
  ~Config();

  YAMLNode getConfigs() const;
  std::string getConfig(const std::string&);
  std::string getNestedConfig(const std::string&, const std::string&);

  std::vector<std::string>& getExts();
private:
  Parser parser;
  YAMLNode configs;
  std::string configFolderPath = "";
  std::string configFilePath = "";
  void initializeConfigFolder();
  const char* getHomeDir();
  bool isFolderExist(std::string);
};
