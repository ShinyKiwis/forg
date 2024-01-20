#include "../include/config.h"
namespace fs = std::filesystem;

Config::Config(const std::string& configPath): parser(), configs(YAMLNode::Type::map) {
  this->configFolderPath = configPath.empty() ? std::string(getHomeDir()) + "/.config/forg/" : configPath;
  configFilePath = this->configFolderPath + "config.yml";
  initializeConfigFolder();
  this->configs = parser.parseYAML(configFilePath);
}

Config::~Config() {

}

std::vector<std::string>& Config::getExts() {
  return parser.getExts();
}

std::string Config::getConfig(const std::string& key) {
  return getHomeDir() + configs.getMapValue(key).getScalar().substr(1);
}

std::string Config::getNestedConfig(const std::string& parentKey, const std::string& key) {
  return getHomeDir() + configs.getMapValue(parentKey).getMapValue(key).getScalar().substr(1);
}

void Config::initializeConfigFolder () {
  if(!fs::exists(configFolderPath)) {
    try {
      fs::create_directory(configFolderPath);
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
