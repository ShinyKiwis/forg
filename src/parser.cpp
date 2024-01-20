#include "../include/parser.h"

Parser::Parser() {

}

Parser::~Parser() {

}

YAMLNode Parser::parseYAML(const std::string& filepath) {
  YAMLNode fileContent(YAMLNode::Type::map);
  std::ifstream configFile(filepath);

  if(!configFile.is_open()) {
    std::cerr << "Error opening file: " << filepath << "\n";
    return fileContent;
  }

  std::string line;
  std::string prevKey = "";
  YAMLNode nestedNodes(YAMLNode::Type::map);
  while(std::getline(configFile, line)) {
    size_t colonPos = line.find(':');
    if(colonPos != std::string::npos) {
      const std::string key = line.substr(0, colonPos);
      const std::string value = parseQuoteString(strip(line.substr(colonPos+1)));
      const bool isNestedKey = getSpaceCount(key) == 2;

      if(isNestedKey && !prevKey.empty()) {
        YAMLNode scalarNode(YAMLNode::Type::scalar);
        scalarNode.setScalar(value);
        nestedNodes.setMapValue(strip(key), scalarNode);
      }else if(value.empty()) {
        prevKey = key;
      }else {
        if(!prevKey.empty()) {
          fileContent.setMapValue(prevKey, nestedNodes);
        }
        prevKey = "";
        YAMLNode scalarNode(YAMLNode::Type::scalar);
        scalarNode.setScalar(value);
        fileContent.setMapValue(key, scalarNode);
      }
      std::cout << key << ":" << value <<"\n";
    }
  }

  // If last key contains nested keys
  if(!prevKey.empty()) {
    fileContent.setMapValue(prevKey, nestedNodes);
  }
  return fileContent;
}
