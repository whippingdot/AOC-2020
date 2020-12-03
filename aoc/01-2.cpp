#include "aoc.h"
#include <iostream>
#include <string>

using std::stoi;
using std::endl;
using std::cout;

void Day1Part2() {
  int answer;
  vector<string> input = read_file("aoc/01.txt");
  auto start = std::chrono::steady_clock::now();

  vector<int> group1 = vector<int>();
  vector<int> group2 = vector<int>();

  // Sort numbers into groups of >1000 and <1000
  for (string& line : input) {
	  int n = stoi(line);

	  if (n > 1000)
	  	group1.push_back(n);
	  else
	  	group2.push_back(n);
  }
  
  for (int num : group1) {
	  for (int addend : group2) {
		  if (num + addend == 2020) {
			  cout << "Part 2:\n" << num << " + " << addend << " = 2020\nThe final answer is: " << num * addend << endl;
		  }
	  }
  }

  auto end = std::chrono::steady_clock::now();
  cout << "Total time taken of part 2: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << "ns" << endl;
}