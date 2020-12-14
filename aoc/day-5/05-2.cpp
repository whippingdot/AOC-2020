#include "../aoc.h"
#include <iostream>
#include <string>
#include <algorithm>

#include "05.h"

bool Contains(vector<int> vect, int number) {
	return find(vect.begin(), vect.end(), number) != vect.end();
}

void Day5Part2() {
  vector<string> input = read_file("aoc/day-5/input.txt");
  auto start = std::chrono::steady_clock::now();
    
  Range seat;
  seat.Start = 0;
  seat.End = 127;

  int highestseat = 0;

  vector<int> seats = vector<int>();

  for (string& str : input) {
	  Answer answer = ReadRow(str);

	  seats.push_back(answer.Seat);
  }

  int i = 1;

  while (i++) {
	  if (! Contains(seats, i) && Contains(seats, i - 1) && Contains(seats, i + 1)) {
		  cout << "Your seat: " << i << "\n";
		  break;
	  }
  }

  auto end = std::chrono::steady_clock::now();
  cout << "Total time taken of part 2: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << endl;
}