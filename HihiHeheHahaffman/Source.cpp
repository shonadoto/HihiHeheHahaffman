#include "Decoder.h"


int main() {
  Tree tree("text.txt");
  tree.OutTree("tree.txt");
  tree.OutTable("table.txt");

  Encoder encoder("text.txt", "encoded.txt", "tree.txt");
  encoder.Encode();

  Decoder decoder("encoded.txt", "decoded.txt", "tree.txt");
  decoder.Decode();
}