#pragma once
#include <iostream>
#include <filesystem>
#include <fstream>
#include <map>
#include <cstdlib>
#include "parser.h"


class Config {
public:
  Config(std::string);
  ~Config();
private:
  Parser parser;
  std::map<std::string, std::string> config;
  std::string configPath = "";
  std::string configFilePath = "";
  void initializeConfigFolder();
  const char* getHomeDir();
  bool isFolderExist(std::string);
};
