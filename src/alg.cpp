// Copyright 2022 NNTU-CS
#include <iostream>
#include <fstream>
#include <locale>
#include <cstdlib>
#include "tree.h"
#include <vector>
std::vector<char> getPerm(const Tree& tree, int n) {
  // напишите реализацию
    std::vector<char> result;
    result = tree.permutations[n - 1];
    reverse(result.begin(), result.end());
    result.pop_back();
    reverse(result.begin(), result.end());
    return result;
}
