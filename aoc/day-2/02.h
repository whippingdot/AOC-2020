#include <string>

using std::string;

typedef struct {
	int RangeBegin;
	int RangeEnd;
	char Letter;
	string Password;
	bool ValidPart1;
	bool ValidPart2;
} Policy;

vector<Policy> Read_Policies(string name);