#include "../aoc.h"
#include <iostream>
#include <string>

void Day8Part1() {
  int answer;
  vector<string> input = read_file("aoc/day-8/input.txt");
  auto start = std::chrono::steady_clock::now();

  vector<int> usedLine = vector<int>();

  string firstThree;
  string num = "";
  int acc = 0;
  int i = 0;

  while (true) {
    if (find(usedLine.begin(), usedLine.end(), i) == usedLine.end()) {
      usedLine.push_back(i);
    }
    else {
      break;
    }

    // firstThree = input[i][0] + input[i][1] + input[i][2];
	firstThree = input[i].substr(0, 3);
	
    if (firstThree == "nop") {
      i++;
    }
    else if (firstThree == "acc") {
      if (input[i][4] == '+') {
        for (int x = 5; x != '\n'; x++) {
          num += input[i][x];
        }
        acc += stoi(num);
      }
      else if (input[i][4] == '-') {
        for (int x = 5; x != '\n'; x++) {
          num += input[i][x];
        }
        acc -= stoi(num);
      }
      i++;
    }
    else if (firstThree == "jmp") {
      if (input[i][4] == '+') {
        for (int x = 5; x != '\n'; x++) {
          num += input[i][x];
        }
        i += stoi(num);
      }
      else if (input[i][4] == '-') {
        for (int x = 5; x != '\n'; x++) {
          num += input[i][x];
        }
        i -= stoi(num);
      }
    }
    num = "";
  }

  cout << "The value in the accumulator is: " << acc << endl;

  auto end = std::chrono::steady_clock::now();
  cout << "Total time taken of part 1: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << "ns" << endl;
}