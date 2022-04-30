#include<vector>
#include<string>

using namespace std;

class game
{
public:
	void get_map1();
	void get_map2();
	void get_map3();
	void print_map();
	void get_control(); //control the player and object in the game
	friend int win_jedge(game&);  //judge if the map be cleared or not

protected:
	char control;
	int count=0;
	bool win = false;
	struct
	{
		int row;
		int col;
	}player;//get position of player
	vector<int> object_row, object_col; //get position of object
	vector<string> map;
	string input;
};