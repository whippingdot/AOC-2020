#include "aoc.h"
#include <iostream>
#include <string>

#include "05.h"

using std::stoi;
using std::endl;
using std::cout;

Answer ReadRow(string str) {
	Answer answer;

	Range seat;
  seat.Start = 0;
  seat.End = 127;

	  for (int i = 0; i < 7; i++) {
		  if (str[i] == 'F') {
			  seat.End = (seat.End - seat.Start)/2 + seat.Start;
		  }

		  else if (str[i] == 'B') {
			  seat.Start = (seat.End - seat.Start)/2 + seat.Start + 1;
		  }
	  }

    if (seat.Start == seat.End) {
      answer.Row = seat.Start;
    }

	Range colrow;
	colrow.Start = 0;
	colrow.End = 7;

    for (int i = 6; i < 10; i++) {
		if (str[i] == 'L') {
			colrow.End = (colrow.End - colrow.Start)/2 + colrow.Start;
		}

		else if (str[i] == 'R') {
			colrow.Start = (colrow.End - colrow.Start)/2 + colrow.Start + 1;
		}
	}

	answer.Column = colrow.Start;

	answer.Seat = answer.Row * 8 + answer.Column;

	return answer;
}

void Day5Part1() {
  vector<string> input = read_file("aoc/05.txt");
  auto start = std::chrono::steady_clock::now();
    
  Range seat;
  seat.Start = 0;
  seat.End = 127;

  int highestseat = 0;

  for (string& str : input) {
	  Answer answer = ReadRow(str);

	  if (answer.Seat > highestseat)
	  	highestseat = answer.Seat;
  }

  cout << "Part 1: Highest seat id = " << highestseat << endl;

  auto end = std::chrono::steady_clock::now();
  cout << "Total time taken of part 1: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << "ns" << endl;
}