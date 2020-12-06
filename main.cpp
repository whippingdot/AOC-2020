#include <stdlib.h>
#include "aoc/aoc.h"
#include "aoc/02.h"
#include "aoc/03.h"
#include "aoc/04.h"

string Read_Raw(string name) {
  std::ifstream file(name);

  string out = "";

  // While the file has data to read
  while (file.good()) {
	  out += file.get();
  }

  return out.substr(0, out.length() - 1); // Remove EOF character
}


vector<string> read_file(string name) {
  vector<string> lines = vector<string>();
  string line;

  fstream file(name);

  while (getline(file, line)) {
    lines.push_back(line);
  }

  return lines;
}

vector<Policy> Read_Policies(string name) {
  vector<Policy> passwords = vector<Policy>();
  string line;

  std::ifstream file(name);

  // While the file has data to read
  while (file.good()) {
    Policy policy;
	
	// Read the range beginning
	file >> policy.RangeBegin;
	file.ignore(); // Ignore the -
	file >> policy.RangeEnd; // Read the range ending

	while (file.peek() == ' ')
		file.ignore(); // Ignore whitespace

	file >> policy.Letter; // Read the policy letter

	file.ignore(); // Ignore the :

	while (file.peek() == ' ')
		file.ignore(); // Ignore whitespace

	file >> policy.Password; // Read the password

	int count = 0;

	for (char c : policy.Password) {
		if (c == policy.Letter)
			count++; // If it matches the letter increment the count of how many there are.
	}

	policy.ValidPart1 = policy.RangeBegin <= count && count <= policy.RangeEnd;

	// Check if the positions have the letter
	bool rb = policy.Password[policy.RangeBegin - 1] == policy.Letter;
	bool re = policy.Password[policy.RangeEnd - 1] == policy.Letter;

	policy.ValidPart2 = (rb && ! re) || (! rb && re);

	passwords.push_back(policy);
  }

  return passwords;
}

bool ValidatePassport(Passport p) {
	if (p.Fields.find("byr") == p.Fields.end() || p.Fields["byr"].length() > 4 || stoi(p.Fields["byr"]) < 1920 || stoi(p.Fields["byr"]) > 2002)
		return false;

	if (p.Fields.find("iyr") == p.Fields.end() || p.Fields["iyr"].length() > 4  || stoi(p.Fields["iyr"]) > 2020 || stoi(p.Fields["iyr"]) < 2010)
		return false;

	if (p.Fields.find("eyr") == p.Fields.end() || p.Fields["eyr"].length() > 4  || stoi(p.Fields["eyr"]) < 2020 || stoi(p.Fields["eyr"]) > 2030)
		return false;

	if (p.Fields.find("byr") == p.Fields.end()) {
		return false;
	}
	else {
		string hgt = p.Fields["hgt"];

		if (hgt.length() > 5 || hgt.length() < 4)
			return false;

		int height = stoi(hgt.substr(0, hgt.length() - 2));

		if (hgt.substr(hgt.length() - 2, hgt.length()) == "cm")
			if (height < 150 || height > 193)
				return false;

		if (hgt.substr(hgt.length() - 2, hgt.length()) == "in")
			if (height < 59 || height > 76)
				return false;
	}

	if (p.Fields.find("hcl") == p.Fields.end() || p.Fields["hcl"][0] != '#' || p.Fields["hcl"].length() != 7)
		return false;

	if (p.Fields.find("ecl") == p.Fields.end())
		return false;

	if (p.Fields["ecl"] != "amb" && p.Fields["ecl"] != "blu" && p.Fields["ecl"] != "brn" && p.Fields["ecl"] != "gry" && p.Fields["ecl"] != "grn" && p.Fields["ecl"] != "hzl" && p.Fields["ecl"] != "oth")
		return false;

	if (p.Fields.find("pid") == p.Fields.end() || p.Fields["pid"].length() != 9)
		return false;

	return true;
}

vector<Passport> Read_Passports(string name) {
  vector<Passport> passports = vector<Passport>();
  string line;

  std::ifstream file(name);

  Passport current; // Store the currently being constructed passport

  // While the file has data to read
  while (file.good()) {
	if (file.peek() == '\0')
		break;
	
	while (file.peek() == ' ') // Ignore whitespace
		file.ignore();
		
	if (file.peek() == '\n') {
		file.get();

		while (file.peek() == ' ') // Ignore whitespace
			file.ignore();

		if (file.peek() == '\n') {
			current.ValidPart1 = current.Fields.find("byr") != current.Fields.end() && current.Fields.find("iyr") != current.Fields.end() && current.Fields.find("eyr") != current.Fields.end() && current.Fields.find("hgt") != current.Fields.end() && current.Fields.find("hcl") != current.Fields.end() && current.Fields.find("ecl") != current.Fields.end() && current.Fields.find("pid") != current.Fields.end();

			current.ValidPart2 = ValidatePassport(current);

			passports.push_back(current);
			current = Passport();
		}

		continue;
	}

	string field;
	string value = "";

	getline(file, field, ':');
	
	while(file.peek() != '\n' && file.peek() != ' ' && file.good())
		value += file.get();

	current.Fields[field] = value;
  }

  current.ValidPart1 = current.Fields.find("byr") != current.Fields.end() && current.Fields.find("iyr") != current.Fields.end() && current.Fields.find("eyr") != current.Fields.end() && current.Fields.find("hgt") != current.Fields.end() && current.Fields.find("hcl") != current.Fields.end() && current.Fields.find("ecl") != current.Fields.end() && current.Fields.find("pid") != current.Fields.end();

  current.ValidPart2 = ValidatePassport(current);

  passports.push_back(current);

  file.close();

  return passports;
}

int main() {
  auto start = std::chrono::steady_clock::now();

  //std::cout << "Day 1: \n\n";
  //Day1Part1();
  //Day1Part2();

  //std::cout << "\n\nDay 2: \n\n";
  //Day2Part1();
  //Day2Part2();

  // std::cout << "\n\nDay 3: \n\n";
  // Day3Part1();
  // Day3Part2();

  // std::cout << "\n\nDay 4: \n\n";
  // Day4Part1();
  // Day4Part2();

  std::cout << "\n\nDay 5: \n\n";
  Day5Part1();
  Day5Part2();

  auto end = std::chrono::steady_clock::now();

  std::cout << "Time taken to complete all puzzles: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms\n";

  return 0;
}