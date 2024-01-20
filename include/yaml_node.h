#pragma once
#include <iostream>
#include <map>

// This YAML Node supports two following syntaxs:
// key: value
// key:
//  key1: value1
//  key2: value2

class YAMLNode {
public:
  enum class Type {
    scalar,
    map
  };

  YAMLNode();
  YAMLNode(Type);

  void setScalar(const std::string&);
  std::string getScalar() const;

  void setMapValue(const std::string&, const YAMLNode&);
  YAMLNode getMapValue(const std::string&) const;

private:
  Type type;
  std::string scalarValue;
  std::map<std::string, YAMLNode> mapValue;
};
