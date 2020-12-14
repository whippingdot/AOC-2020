#include <vector>
#include <string>

using std::string;
using std::vector;

class Map {
	public:

	vector<vector<char>> Original = vector<vector<char>>();
	vector<vector<char>> Data = vector<vector<char>>();

	int Width;
	int Height;

	int X = 0;
	int Y = 0;

	int Slope(int right, int down) {
		X = 0;
		Y = 0;
		
		int trees = 0;

		while (Y < Height) {
			if (Move(right, down))
				trees++;
		}

		return trees;
	}

	bool Move(int right, int down) {
		X += right;
		Y += down;

		if (X >= Width) {
			// std::cout << "EXPAND: \n";

			// std::cout << "Size: " << Data.size() << "\n";

			for (int y = 0; y < Data.size(); y++) {
				for (int i = 0; i < Original[y].size(); i++) {
					//std::cout << Original[y][i];
					Data[y].push_back(Original[y][i]); // Duplicate rows to repeat the pattern
				}

				//std::cout << "\n";
			}

			Width += Original[Y].size();
		}

		return Data[Y][X] == '#';
	}

	Map(string text) {
		Original.push_back(vector<char>());
		Data.push_back(vector<char>());

		for (char c : text) {
			if (c == '\n') {
				X = 0;
				Y++;

				Original.push_back(vector<char>());
				Data.push_back(vector<char>());
				
				continue;
			}
			
			Original[Y].push_back(c);
			Data[Y].push_back(c);

			X++;
		}

		Width = X;
		Height = Y;

		X = 0;
		Y = 0;
	}
};