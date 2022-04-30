#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"game.h"

using namespace std;

int main()
{
	game play1, play2, play3;
	play1.get_map1();
	while (win_jedge(play1) == false)
	{
		play1.print_map();
		play1.get_control();
		system("CLS");
	}
	system("CLS");
	play2.get_map2();
	while (win_jedge(play2) == false)
	{
		play2.print_map();
		play2.get_control();
		system("CLS");
	}
	system("CLS");
	play3.get_map3();
	while (win_jedge(play3) == false)
	{
		play3.print_map();
		play3.get_control();
		system("CLS");
	}
	system("CLS");
	cout << endl << endl << endl;
	cout << "*     *                                              ***" << endl;
	cout << "  * *                                                ***" << endl;
	cout << "   *     ***   *   *      *   *   *    *   * **       *" << endl;
	cout << "   *    *   *  *   *       * * * *     *   **  *    " << endl;
	cout << "   *     ***    *** *       *   *      *   *   **     *" << endl;
	
	
	while (1);
}