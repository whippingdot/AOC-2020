#include <string>
#include <map>

using std::string;
using std::map;

class Bag {
	public:

	string Color;

	bool Contains(map<string, Bag*> allbags, string color, vector<string> visited);

	int Required(map<string, Bag*> allbags);

	vector<string> CanContain = vector<string>();
	map<string, int> Amount = map<string, int>();
};

typedef struct {
	map<string, Bag*> All = map<string, Bag*>();
	vector<Bag*> Rules = vector<Bag*>();
} BagData;

class BagReader {
	fstream File;

	public:

	void SkipSpace();

	void SkipWord();

	string GetWord();

	string GetColor();

	Bag* GetBag();

	BagData GetData();

	BagReader(string file);
};