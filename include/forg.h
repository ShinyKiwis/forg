#pragma once
#include "config.h"
#include "algorithm"

class FOrg {
public:
  FOrg();
  ~FOrg();
  void run();
private:
  Config config;
  void moveFile(const std::string&, const std::string&);

};
