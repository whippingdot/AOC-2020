#include "../aoc.h"
#include <iostream>
#include <string>
#include <algorithm>

void Day6Part2() {
  vector<string> input = read_file("aoc/day-6/input.txt");
  auto start = std::chrono::steady_clock::now();

  vector<int> groups = vector<int>();

  

  vector<vector<char>> answered = vector<vector<char>>();

  vector<char> person = vector<char>();

  for (int i = 0; i < input.size(); i++) {
	  string str = input[i];

	  for (char c : str) {
	  	if (find(person.begin(), person.end(), c) == person.end())
		  	person.push_back(c);
	  }
	  
	  answered.push_back(person);

	  person = vector<char>();
	  
	  if (input[i + 1] == "") {

		  int amount = 0;

		  vector<char> first = answered[0];

		  for (char c : first) {
			  bool all = true;

			  for (int i = 1; i < answered.size(); i++) {
				  vector<char>& form = answered[i];

				  if (find(form.begin(), form.end(), c) == form.end()) {
					  all = false;
					  break;
				  }
			  }

			  if (all)
			  	amount++;
		  }

		  groups.push_back(amount);

		  answered.clear();
		  person.clear();
		  i++; // Skip the empty line
		  continue;
	  }
  }

  cout << "Total groups: " << groups.size() << "\n";

  int sum = 0;

  for (int group : groups) {
	  sum += group;
  }

  cout << "Sum of group answers: " << sum << "\n";

  auto end = std::chrono::steady_clock::now();
  cout << "Total time taken of part 2: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << "ns" << "\n";
}