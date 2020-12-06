#include "aoc.h"
#include <iostream>
#include <string>
#include <algorithm>

#include "03.h"

using std::stoi;
using std::endl;
using std::cout;
using std::pair;
using std::find;

void Day3Part1() {
  int answer;

  Map map = Map(Read_Raw("aoc/03.txt"));

  auto start = std::chrono::steady_clock::now();

  cout << "Trees in path: " << map.Slope(3, 1) << "\n";

  auto end = std::chrono::steady_clock::now();
  cout << "Total time taken of part 1: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << endl;
}