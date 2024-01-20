#include "../include/yaml_node.h"

YAMLNode::YAMLNode() {

}

YAMLNode::YAMLNode(Type type): type(type) {

}

void YAMLNode::setScalar(const std::string& value) {
  if(type == Type::scalar) {
    scalarValue = value;
  }
}

std::string YAMLNode::getScalar() const {
  return (type == Type::scalar) ? scalarValue : "";
}

void YAMLNode::setMapValue(const std::string& key, const YAMLNode& value) {
  if(type == Type::map) {
    mapValue[key] = value;
  }
}

YAMLNode YAMLNode::getMapValue(const std::string& key) const {
  if(type == Type::map) {
    auto it = mapValue.find(key);
    return (it != mapValue.end()) ? it->second : YAMLNode(Type::scalar);
  }
  return YAMLNode(Type::scalar);
}
