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

void Day3Part2() {
  int answer;

  auto start = std::chrono::steady_clock::now();

  Map map = Map(Read_Raw("aoc/03.txt"));
  
  vector<pair<int, int>> slopes = vector<pair<int, int>>();

  slopes.push_back(pair(1, 1));
  slopes.push_back(pair(3, 1));
  slopes.push_back(pair(5, 1));
  slopes.push_back(pair(7, 1));
  slopes.push_back(pair(1, 2));

  vector<int> trees = vector<int>();

  for (pair<int, int> slope : slopes) {
	  trees.push_back(map.Slope(slope.first, slope.second));
  }

  // Can be larger than the integer overflow limit
  long product = trees[0];

  for (int i = 1; i < trees.size(); i++) {
	product = product * trees[i];
  }

  cout << "Product of supplied slopes: " << product << "\n";

  auto end = std::chrono::steady_clock::now();
  cout << "Total time taken of part 2: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << endl;
}