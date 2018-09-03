#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
void chapter3_4(void)
{
	char c='c';
	while (c!='q')
	{
		cout << "MAIN MENU:" << endl;
		cout << "l:left,r:right,q:quit ->";
		cin >> c;
		switch (c)
		{
			case 'q': {break; }
			case 'l':
				{
					cout << "LEFT MENU:" << endl;
					cout << "select a or b:";
					cin >> c;
					switch (c)
					{
					case 'a': {cout << "you chose 'a'" << endl; continue; }
					case 'b': {cout << "you chose 'b'" << endl; continue; }
					default: {cout << "you didn't chose a or b" << endl; continue; }
					}
					break;
				}
			case 'r':
			{
				cout << "RIGHT MENU:" << endl;
				cout << "select c or d:";
				cin >> c;
				switch (c)
				{
				case 'c': {cout << "you chose 'c'" << endl; continue; }
				case 'd': {cout << "you chose 'd'" << endl; continue; }
				default: {cout << "you didn't chose c or d" << endl; continue; }
				}
				break;
			}
			default: {cout << "you must type l,r or q" << endl; break; }
		}

	}
	cout << "quit menu ..." << endl;
}
float* chapter3_5(float x, float y, float z)
{
	float result[2];
	result[0] = x + y - 2 / 2 + z;
	result[1]= x +( y - 2) / (2 + z);
	cout << "first result is " << result[0] << " second result is " << result[1] << endl;
	return result;
}
void chapter3_6(void)
{
	cout << "没有多大的意思，所以没有做" << endl;
}
void chapter3_7_1(string *str)
{
	string mstr = "my name";
	cout << str << endl;
	str = &mstr;
	cout << str << endl;
		
}