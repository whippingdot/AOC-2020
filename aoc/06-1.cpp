#include "aoc.h"
#include <iostream>
#include <string>

#include "06.h"

using std::cout;

void Day6Part1() {
  vector<string> input = read_file("aoc/05.txt");
  auto start = std::chrono::steady_clock::now();
    
  

  auto end = std::chrono::steady_clock::now();
  cout << "Total time taken of part 1: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << "ns" << endl;
}