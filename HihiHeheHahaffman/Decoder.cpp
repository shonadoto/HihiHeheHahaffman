#include "Decoder.h"


Decoder::Decoder(std::string encoded_file, std::string decoded_file, std::string tree_file) {
  tr = new Tree(tree_file, true);
  vert = tr->Root();
  inp = std::ifstream(encoded_file);
  out = std::ofstream(decoded_file);
}

void Decoder::Decode() {
  std::getline(inp, encoded);
  for (auto& c : encoded) {
    if (vert->left_ == NULL) {
      decoded += vert->letter_;
      vert = tr->Root();
    }
    if (c == '0') vert = vert->left_;
    else vert = vert->right_;
  }
  out << decoded;
  inp.close();
  out.close();
}
