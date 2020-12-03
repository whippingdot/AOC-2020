#ifndef AOC
#define AOC

// DO NOT TOUCH
// anyways I have included some sensible things most sensible users would use.
#include <fstream>
#include <iostream>
#include <string>
#include <chrono>
#include <vector>

using std::vector;
using std::string;
using std::fstream;
using std::getline;


// read file (silently fail)
vector<string> read_file(string name);

void Day1Part1();
void Day1Part2();
#endif