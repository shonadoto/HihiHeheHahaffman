#pragma once

#include "includes.h"

struct  Node
{
  Node(char letter, int number, Node* left = NULL, Node* right = NULL) : letter_(letter), left_(left), right_(right), number_(number) {}

  unsigned char letter_;
  Node* left_, * right_;
  int number_;
};


class Tree {
public:
  Tree(std::string input_file, bool intput_tree = false);

  std::vector<std::string> GetTable() {
    return table;
  }

  void OutTree(std::string outfile);
  void OutTable(std::string outfile);
  void OutTree(Node* vert);
  void InTree(Node*& vert);
  Node* Root() { return root; }
  void CloseFiles();
private:

  Node* root;
  std::vector<std::string> table;
  std::ifstream trin;
  std::ofstream trout;

  void GenTable(Node* vert, std::string code);
};

