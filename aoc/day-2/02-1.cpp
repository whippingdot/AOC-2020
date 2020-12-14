#include "../aoc.h"
#include <iostream>
#include <string>
#include <algorithm>

#include "02.h"

void Day2Part1() {
  int answer;

  vector<Policy> passwords = Read_Policies("aoc/day-2/input.txt");

  auto start = std::chrono::steady_clock::now();

  int validcount = 0;

  for (Policy psw : passwords) {
	  if (psw.ValidPart1)
	  	validcount++;
  }

  cout << "Valid passwords: " << validcount << "\n";

  auto end = std::chrono::steady_clock::now();
  cout << "Total time taken of part 1: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << "ns" << endl;
}