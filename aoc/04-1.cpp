#include "aoc.h"
#include <iostream>
#include <string>

#include "04.h"

using std::stoi;
using std::endl;
using std::cout;

void Day4Part1() {
  auto start = std::chrono::steady_clock::now();

  vector<Passport> input = Read_Passports("aoc/04.txt");
  int valid = 0;

  for (Passport passport : input) {
	  if (passport.ValidPart1)
	  	valid++;
  }

  std::cout << "Part 1 finished.\nTotal [" << input.size() << "] Valid [" << valid << "]\n\n";

  auto end = std::chrono::steady_clock::now();
  cout << "Total time taken of part 1: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << endl;
}