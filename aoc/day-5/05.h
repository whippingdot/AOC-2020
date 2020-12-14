typedef struct {
	int Start;
	int End;
} Range;

typedef struct {
	int Row;
	int Column;
	int Seat;
} Answer;

Answer ReadRow(string str);