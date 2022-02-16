#include "Tree.h"


Tree::Tree(std::string input_file, bool input_tree) {
  table.resize(256);

  if (input_tree) {
    trin.open(input_file);
    InTree(root);
  }
  else {
    trin.open(input_file);
    std::string text = "", cur = "";
    while (std::getline(trin, cur)) text += cur + "\n";
    std::vector<int> letters(256, 0);
    for (auto& c : text) {
      letters[unsigned char(c)]++;
    }
    auto cmp = [](std::pair<int, Node*> a, std::pair<int, Node*> b) {
      if (a.first == b.first) {
        return a.second->number_ > b.second->number_;
      }
      return a.first < b.first;
    };
    std::set<std::pair<int, Node*>, decltype(cmp)> st;
    int cnt = 0;
    //st.insert({ 0, new Node(0, cnt++) });
    for (int i = 1; i < 256; ++i) {
      if (letters[i] > 0)
        st.insert({ letters[i], new Node(i, cnt++) });
    }
    while (st.size() != 1) {
      std::pair<int, Node*> n1, n2;
      n1 = *st.begin();
      st.erase(n1);
      n2 = *st.begin();
      st.erase(n2);
      Node* n3 = new Node(0, cnt++, n1.second, n2.second);
      st.insert({ n1.first + n2.first, n3 });
    }
    root = st.begin()->second;
  }
  GenTable(root, "");
  return;
}

void Tree::GenTable(Node* vert, std::string code) {
  if (!vert) {
    return;
  }
  if (vert->left_ == NULL) {
    table[unsigned char(vert->letter_)] = code;
    return;
  }
  GenTable(vert->left_, code + "0");
  GenTable(vert->right_, code + "1");
  return;
}

void Tree::OutTree(std::string outfile) {
  trout.close();
  trout.open(outfile);
  OutTree(root);
  trout.close();
  return;
}

void Tree::OutTree(Node* vert) {
  std::string ret = "";
  if (vert->left_ == NULL) {
    trout << int(unsigned char(vert->letter_)) << "\n";
    return;
  }
  trout << "l\n"; OutTree(vert->left_);
  trout << "r\n"; OutTree(vert->right_);
}

void Tree::InTree(Node*& vert) {
  vert = new Node(0, NULL, NULL);
  std::string tmp;
  trin >> tmp;
  if (tmp == "l") {
    InTree(vert->left_);
    trin >> tmp;
    InTree(vert->right_);
  }
  else if (tmp.size() != 0) {
    vert->letter_ = unsigned char(stoi(tmp));
  }
  return;
}

void Tree::OutTable(std::string out_file) {
  trout.close();
  trout.open(out_file);
  for (int i = 0; i < 256; ++i) {
    if (table[i].size()) {
      if (i == '\n') {
        trout << "\\n" << ' ' << table[i] << std::endl;
      }
      else if (i == '\t') {
        trout << "\\t" << ' ' << table[i] << std::endl;
      }
      else if (i == ' ') {
        trout << "space" << ' ' << table[i] << std::endl;
      }
      else {
        trout << char(i) << ' ' << table[i] << std::endl;
      }
    }
  }
  trout.close();
}

void Tree::CloseFiles() {
  trin.close();
  trout.close();
}
