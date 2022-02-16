#include "Encoder.h"


Encoder::Encoder(std::string input_file, std::string output_file, std::string tree_file) {
  inp.open(input_file);
  out.open(output_file);
  text = "";
  std::string cur = "";
  while (getline(inp, cur)) {
    text += cur + "\n";
  }
  tr = new Tree(tree_file, 1);
}

void Encoder::Encode() {
  std::vector <std::string> table = tr->GetTable();
  std::string coded = "";
  for (auto& c : text) {
    coded += table[c];
  }
  out << coded;
  CloseFiles();
}

void Encoder::OutputTree(std::string out_file) {
  tr->OutTree(out_file);
}

void Encoder::OutputTable(std::string out_file) {
  tr->OutTable(out_file);
}

void Encoder::CloseFiles() {
  inp.close();
  out.close();
  tr->CloseFiles();
  return;
}