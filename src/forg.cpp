#include "../include/forg.h"

namespace fs = std::filesystem;

FOrg::FOrg(): config("") {

}

FOrg::~FOrg() {

}

void FOrg::run() {
  const std::string sourcePath = config.getConfig("source_path");
  const std::vector<std::string> exts = config.getExts();
  try {
    if(fs::exists(sourcePath) && fs::is_directory(sourcePath)) {
      for(const auto& entry: fs::directory_iterator(sourcePath)) {
        const std::string fileExt =  std::string(entry.path().extension()).substr(1);
        if(std::find(exts.begin(), exts.end(), fileExt) != exts.end()) {
          const std::string fileDestinationPath = config.getNestedConfig("destination_paths", fileExt);
          if(!fs::exists(fileDestinationPath)) {
            try {
              fs::create_directory(fileDestinationPath);
            } catch (const std::exception& e) {
              std::cerr << "Error creating config folder: " << e.what() << "\n";
            }
          }
          moveFile(entry.path(), fileDestinationPath + "/" + std::string(entry.path().filename()));
        }
      }
    }
  } catch (const std::filesystem::filesystem_error& e) {
    std::cerr << "Error accessing folder: " << e.what() << "\n";
  }
}

void FOrg::moveFile(const std::string& source, const std::string& destination) {
  fs::rename(source, destination);
}
