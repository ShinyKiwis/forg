#include "../include/util.h"

std::string strip(const std::string& str) {
  size_t start = str.find_first_not_of(" \t\r\n");
  size_t end = str.find_last_not_of(" \t\r\n");

  if(start == std::string::npos || end == std::string::npos) {
    return str.length() == 0 ? "" : str;
  }

  return str.substr(start, end-start+1);
}

short getSpaceCount(const std::string & str) {
  short spaceCount = 0;
  for(const char c: str) {
    if(c == ' ') {
      spaceCount++;
    }
  }
  return spaceCount;
}

std::string parseQuoteString(const std::string& str) {
  size_t start = str.find_first_of("\"");
  size_t end = str.find_last_of(" \"");

  if(start == std::string::npos || end == std::string::npos) {
    return str;
  }

  return str.substr(start+1,end - (start+1));
}
