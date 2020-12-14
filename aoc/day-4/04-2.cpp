#include "../aoc.h"
#include <iostream>
#include <string>

#include "04.h"

void Day4Part2() {
  auto start = std::chrono::steady_clock::now();

  vector<Passport> input = Read_Passports("aoc/day-4/input.txt");
  int valid = 0;

  for (Passport passport : input) {
	  if (passport.ValidPart2)
	  	valid++;
  }

  cout << "Part 2 finished.\nTotal [" << input.size() << "] Valid [" << valid << "]\n\n";

  auto end = std::chrono::steady_clock::now();
  cout << "Total time taken of part 2: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << endl;
}