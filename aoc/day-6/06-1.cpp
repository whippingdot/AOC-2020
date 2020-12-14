#include "../aoc.h"
#include <iostream>
#include <string>
#include <algorithm>

void Day6Part1() {
  vector<string> input = read_file("aoc/day-6/input.txt");
  auto start = std::chrono::steady_clock::now();

  vector<int> groups = vector<int>();

  vector<char> answered = vector<char>();

  for (int i = 0; i < input.size(); i++) {
	  string str = input[i];

	  for (char c : str) {
	  	if (find(answered.begin(), answered.end(), c) == answered.end())
		  	answered.push_back(c);
	  }
	  
	  if (input[i + 1] == "") {
		  groups.push_back(answered.size());
		  answered.clear();
		  i++; // Skip the empty line
		  continue;
	  }
  }

  cout << answered.size() << "\n";
  // groups.push_back(answered.size());

  cout << "Total groups: " << groups.size() << "\n";

  int sum = 0;

  for (int group : groups) {
	  sum += group;
  }

  cout << "Sum of group answers: " << sum << "\n";

  auto end = std::chrono::steady_clock::now();
  cout << "Total time taken of part 1: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << "ns" << "\n";
}