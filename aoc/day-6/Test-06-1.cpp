#include "../aoc.h"
#include <iostream>
#include <string>

void TestDay6Part1() {
  vector<string> input = read_file("aoc/day-6/input.txt");
  auto start = std::chrono::steady_clock::now();

  vector<char> charUsed = vector<char>();
  vector<int> numbers = vector<int>();

  int answer = 0;

  for (string& line : input) {
    for (char& i : line) {
      if (find(charUsed.begin(), charUsed.end(), i) == charUsed.end()) {
        charUsed.push_back(i);
      }
    }
	
    if (line == "") {
      numbers.push_back(charUsed.size());
      charUsed.clear();
    }
  }
  numbers.push_back(charUsed.size());

  for (int smallNum = 0; smallNum < numbers.size(); smallNum++) {
    answer += numbers[smallNum];
  }

  cout << "The sum of the counts is: " << answer << endl;

  auto end = std::chrono::steady_clock::now();
  cout << "Total time taken of part 1: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << "ns" << "\n";
}