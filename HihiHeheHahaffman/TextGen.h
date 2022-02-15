#pragma once

#include "includes.h"

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

void TextGen(int text_lenght, std::string out_file) {
  std::ofstream out(out_file);
  std::vector<char> letters;
  int text_left = text_lenght;
  for (int i = 0; i < 26; ++i) {
    int num = rng() % text_left;
    for (int j = 0; j < num; ++j) {
      letters.push_back('a' + i);
    }
    text_left -= num;
  }
  for (int i = 0; i < text_left; ++i) {
    letters.push_back(' ');
  }
  for (int i = 0; i < text_lenght; ++i) {
    out << char(letters[rng() % text_lenght]);
  }
}

