#include "../include/parser.h"

Parser::Parser() {

}

Parser::~Parser() {

}

std::map<std::string, std::string> Parser::parseYAML(const std::string& filepath) {
  std::map<std::string, std::string> parsedData;
  std::ifstream configFile(filepath);

  if(!configFile.is_open()) {
    std::cerr << "Error opening file: " << filepath << "\n";
    return parsedData;
  }

  std::string line;
  while(std::getline(configFile, line)) {
    size_t colonIndex = line.find(':');
    const std::string key = line.substr(0, colonIndex);
    const std::string value = line.substr(colonIndex+1);
    std::cout << key << ":" << value <<"\n";
  }
  return parsedData;
}
