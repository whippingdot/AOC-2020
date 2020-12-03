#include <stdlib.h>
#include "aoc/aoc.h"

vector<string> read_file(string name) {
  vector<string> lines = vector<string>();
  string line;

  fstream file(name);

  while (getline(file, line)) {
    lines.push_back(line);
  }

  return lines;
}

int main() {
  Day1Part1();
  Day1Part2();

  return 0;
}