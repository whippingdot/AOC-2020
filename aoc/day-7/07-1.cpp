#include "../aoc.h"
#include <iostream>
#include <string>

#include "07.h"

using std::cout;

void BagReader::SkipSpace() {
	while (File.peek() == ' ' || File.peek() == '\n')
		File.ignore();
}

void BagReader::SkipWord() {
	while (File.good() && File.peek() != ' ' && File.peek() != ',' && File.peek() != '.')
		File.ignore();
}

string BagReader::GetWord() {
	string word = "";

	while (File.good() && File.peek() != ' ' && File.peek() != ',' && File.peek() != '.')
		word += File.get();

	return word;
}

string BagReader::GetColor() {
	string color = GetWord();

	SkipSpace();
	color += ' ';

	color += GetWord();

	SkipSpace();

	return color;
}

Bag* BagReader::GetBag() {
	Bag* bag = new Bag();

	bag->Color = GetColor();

	SkipSpace();
	SkipWord(); // bags
	SkipSpace();
	SkipWord(); // contain
	SkipSpace();

	string amount = GetWord();

	SkipSpace();

	if (amount == "no") {
		while (File.good() && File.peek() != '\n')
			File.ignore();

		File.ignore();

		return bag;
	}

	string color = GetColor();

	bag->CanContain.push_back(color);
	bag->Amount[color] = stoi(amount);

	SkipWord();

	while (File.peek() == ',') {
		File.ignore();

		SkipSpace();

		amount = GetWord();

		SkipSpace();

		color = GetColor();

		bag->CanContain.push_back(color);
		bag->Amount[color] = stoi(amount);

		SkipWord();
	}

	File.get();

	SkipSpace();

	return bag;
}

BagData BagReader::GetData() {
	BagData data;

	data.All = map<string, Bag*>();
	data.Rules = vector<Bag*>();

	while (File.good()) {
		Bag* bag = GetBag();

		data.All[bag->Color] = bag;
		data.Rules.push_back(bag);
	}

	return data;
}

BagReader::BagReader(string file) {
	File = fstream(file);
}

bool Bag::Contains(map<string, Bag*> allbags, string color, vector<string> visited) {
	visited.push_back(Color);

	if (find(CanContain.begin(), CanContain.end(), color) != CanContain.end())
		return true;

	for (string& c : CanContain) {
		if (find(visited.begin(), visited.end(), c) == visited.end() && allbags[c]->Contains(allbags, color, visited))
			return true;
	}

	return false;
}

int Bag::Required(map<string, Bag*> allbags) {
	if (CanContain.size() == 0)
		return 0;

	int total = CanContain.size();

	for (string color : CanContain) {
		total += allbags[color]->Required(allbags) * Amount[color] + 1;
	}

	return total;
}

/* Really inefficient algorithm(I think) */
/* 40 seconds to run */
/* Lol */
void Day7Part1() {
  auto start = std::chrono::steady_clock::now();

  BagReader reader = BagReader("aoc/day-7/input.txt");

  BagData data = reader.GetData();

  int total = 0;

  for (Bag* bag : data.Rules) {
	  if (bag->Contains(data.All, "shiny gold", vector<string>()))
	  	 total++;
  }

  cout << "Total bags that can hold a shiny gold bag: " << total << "\n";

  auto end = std::chrono::steady_clock::now();
  cout << "Total time taken of part 2: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << "\n";
}