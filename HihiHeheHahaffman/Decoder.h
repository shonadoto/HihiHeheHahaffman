#pragma once
#include "Encoder.h"
class Decoder
{
public:
  Decoder(std::string encoded_file,std::string decoded_file, std::string tree_file);
  void Decode();
private:
  Tree* tr;
  Node* vert;
  std::string encoded, decoded;
  std::ifstream inp;
  std::ofstream out;
};

