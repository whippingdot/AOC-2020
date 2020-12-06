#include <string>
#include <map>

using std::map;

typedef struct {
	map<string, string> Fields = map<string, string>();
	bool ValidPart1;
	bool ValidPart2;
} Passport;

vector<Passport> Read_Passports(string name);