#include "../aoc.h"
#include <iostream>
#include <string>

void Day1Part1() {
  int answer;
  vector<string> input = read_file("aoc/day-1/input.txt");
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

  bool found = false;
  
  for (int num : group1) {
	  for (int addend : group2) {
		  if (num + addend == 2020) {
			  cout << "Part 1:\n" << num << " + " << addend << " = 2020\nThe final answer is: " << num * addend << endl;

			  found = true;
		  }
	  }
  }

  // If the fast method doesn't find it then just check everything(Some people may get inputs where 1011 + 1009 will add up to 2020, which won't be checked by the above)
  if (! found) {
	  for (string& line : input) {
		int n = stoi(line);

		for (string& line : input) {
			int n2 = stoi(line);

			if (n + n2 == 2020) {
				cout << "Part 1:\n" << n << " + " << n2 << " = 2020\nThe final answer is: " << n * n2 << endl;
			}
		}
	}
  }

  auto end = std::chrono::steady_clock::now();
  cout << "Total time taken of part 1: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << "ns" << endl;
}