#include <iostream>
#include <stdio.h>
#include <string.h>
#include "chapter3.h"
using namespace std;
void main(void)
{
	string mystr = "myname";
	string *str=&mystr;
	chapter3_7_1(str);
	cout << *str << endl;
	system("pause");
}