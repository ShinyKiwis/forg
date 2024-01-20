#include "../include/config.h"
namespace fs = std::filesystem;

Config::Config(std::string configPath): parser(), configs(YAMLNode::Type::map) {
  this->configPath = configPath.empty() ? std::string(getHomeDir()) + "/.config/forg/" : configPath;
  configFilePath = this->configPath + "config.yml";
  initializeConfigFolder();
  this->configs = parser.parseYAML(configFilePath);
}

Config::~Config() {

}

YAMLNode Config::getConfigs() const {
  return configs;
}

void Config::initializeConfigFolder () {
  if(!fs::exists(configPath)) {
    try {
      fs::create_directory(configPath);
      std::ofstream configFile(configFilePath);
      if(configFile.is_open()) {
        configFile.close();
      }
    } catch (const std::exception& e) {
      std::cerr << "Error creating config folder: " << e.what() << "\n";
    }
  }
}

const char* Config::getHomeDir() {
  const char* homeVar = "HOME";
  const char* homeDir = getenv(homeVar);
  if(homeDir == nullptr) {
    std::cerr << "Unable to determine the home directory with: " << homeVar << "\n";
  }
  return homeDir;
}


bool Config::isFolderExist(std::string folderPath) {
  return false;
}
