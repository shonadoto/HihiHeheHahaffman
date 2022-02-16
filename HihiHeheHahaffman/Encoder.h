#pragma once

#include "Tree.h"

class Encoder {
public:
  Encoder(std::string input_file, std::string output_file, std::string tree_file);
  void Encode();
  void OutputTree(std::string out_file);
  void OutputTable(std::string out_file);
  void CloseFiles();
private:
  std::string text;
  std::ifstream inp;
  std::ofstream out;
  Tree* tr;
};