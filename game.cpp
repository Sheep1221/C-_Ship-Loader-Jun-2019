#include"game.h"
#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>

ifstream fin1("map1.txt", ios::in);
ifstream fin2("map2.txt", ios::in);
ifstream fin3("map3.txt", ios::in);

void game::get_map1()
{
	int r = 0;
	while (fin1 >> input)
	{
		map.push_back(input);
		for (int i = 0; i < input.size(); i++)
		{
			if (input[i] == 'A') //get player position
			{
				player.row = r;
				player.col = i;
			}
			else if (input[i] == 'B') //get object position
			{
				object_row.push_back(r);
				object_col.push_back(i);
			}
		}
		r++;
	}
}

void game::get_map2()
{
	int r = 0;
	while (fin2 >> input)
	{
		map.push_back(input);
		for (int i = 0; i < input.size(); i++)
		{
			if (input[i] == 'A') //get player position
			{
				player.row = r;
				player.col = i;
			}
			else if (input[i] == 'B') //get object position
			{
				object_row.push_back(r);
				object_col.push_back(i);
			}
		}
		r++;
	}
}

void game::get_map3()
{
	int r = 0;
	while (fin3 >> input)
	{
		map.push_back(input);
		for (int i = 0; i < input.size(); i++)
		{
			if (input[i] == 'A') //get player position
			{
				player.row = r;
				player.col = i;
			}
			else if (input[i] == 'B') //get object position
			{
				object_row.push_back(r);
				object_col.push_back(i);
			}
		}
		r++;
	}
}

void game::print_map()
{
	for (int i = 0; i < map.size(); i++)
	{
		cout << map[i] << endl;
	}
}

void game::get_control()
{
	//Use arraw key to control the moving direction of the character
	control = _getch();
	switch (control)
	{
#pragma region left
	case 75://left
		if (map[player.row][player.col - 1] == 'B')
		{
			if (map[player.row][player.col - 2] == 'E')
			{
				map[player.row][player.col--] = '*';
				map[player.row][player.col] = 'A';
				map[player.row][player.col-1] = '*';
				count++;
			}
			else if (map[player.row][player.col - 2] != '/' && map[player.row][player.col - 2] != 'B')
			{
				for (int i = 0; i < object_row.size(); i++)
				{
					if (object_row[i] == player.row && object_col[i] == player.col - 1)
					{
						map[object_row[i]][--object_col[i]] = 'B';
						map[player.row][player.col--] = '*';
						map[player.row][player.col] = 'A';
					}
				}
			}
		}
		else if (map[player.row][player.col - 1] != '/')
		{
			map[player.row][player.col--] = '*';
			map[player.row][player.col] = 'A';
		}
		break;
#pragma endregion

#pragma region up
	case 72://up
		if (map[player.row - 1][player.col] == 'B')
		{
			if (map[player.row - 2][player.col] == 'E')
			{
				map[player.row--][player.col] = '*';
				map[player.row][player.col] = 'A';
				map[player.row-1][player.col] = '*';
				count++;
			}
			else if (map[player.row - 2][player.col] != '/')
			{
				for (int i = 0; i < object_row.size(); i++)
				{
					if (object_row[i] == player.row - 1 && object_col[i] == player.col)
					{
						map[--object_row[i]][object_col[i]] = 'B';
						map[player.row--][player.col] = '*';
						map[player.row][player.col] = 'A';
					}
				}
			}
		}
		else if (map[player.row - 1][player.col] != '/')
		{
			map[player.row--][player.col] = '*';
			map[player.row][player.col] = 'A';
		}
		break;
#pragma endregion

#pragma region right
	case 77://right
		if (map[player.row][player.col + 1] == 'B')
		{
			if (map[player.row][player.col + 2] == 'E')
			{
				map[player.row][player.col++] = '*';
				map[player.row][player.col] = 'A';
				map[player.row][player.col+1] = '*';
				count++;
			}
			else if (map[player.row][player.col + 2] != '/')
			{
				for (int i = 0; i < object_row.size(); i++)
				{
					if (object_row[i] == player.row && object_col[i] == player.col + 1)
					{
						map[object_row[i]][++object_col[i]] = 'B';
						map[player.row][player.col++] = '*';
						map[player.row][player.col] = 'A';
					}
				}
			}
		}
		else if (map[player.row][player.col + 1] != '/')
		{
			map[player.row][player.col++] = '*';
			map[player.row][player.col] = 'A';
		}
		break;
#pragma endregion

#pragma region down
	case 80://down
		if (map[player.row + 1][player.col] == 'B')
		{
			if (map[player.row + 2][player.col] == 'E')
			{
				map[player.row++][player.col] = '*';
				map[player.row][player.col] = 'A';
				map[player.row+1][player.col] = '*';
				count++;
			}
			if (map[player.row + 2][player.col] != '/')
			{
				for (int i = 0; i < object_row.size(); i++)
				{
					if (object_row[i] == player.row + 1 && object_col[i] == player.col)
					{
						map[++object_row[i]][object_col[i]] = 'B';
						map[player.row++][player.col] = '*';
						map[player.row][player.col] = 'A';
					}
				}
			}
		}
		else if (map[player.row + 1][player.col] != '/')
		{
			map[player.row++][player.col] = '*';
			map[player.row][player.col] = 'A';
		}
		break;
#pragma endregion 

	}
}

int win_jedge(game& player)
{
	if (player.count == player.object_row.size())
		player.win = true;
	cout << "Number of objects need to put: " << player.object_row.size() << "         Finished: " << player.count << endl;
	return player.win;
}