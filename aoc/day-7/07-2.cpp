#include "../aoc.h"
#include <iostream>
#include <string>

#include "07.h"

using std::cout;

/* Really inefficient algorithm(I think) */
/* 40 seconds to run */
void Day7Part2() {
  auto start = std::chrono::steady_clock::now();

  BagReader reader = BagReader("aoc/day-7/input.txt");

  BagData data = reader.GetData();

  cout << "Total bags that a shiny gold bag must contain = " << data.All["shiny gold"]->Required(data.All) << " bags.\n";

  auto end = std::chrono::steady_clock::now();
  cout << "Total time taken of part 1: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << "\n";
}