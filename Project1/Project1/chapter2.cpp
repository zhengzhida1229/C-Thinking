#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include "chapter2.h"
using namespace std;
void chapter2_1(void)
{
	cout << "我的名字：郑志达\n"
		<< "年龄：25\n" << endl;
}
float chapter2_2(void)
{
	float PI = 3.141592, area_circle, r;
	cout << "请输入圆的半径:" << endl;
	cin >> r;
	area_circle = PI*r*r;
	cout << "此圆的面积为：" << area_circle << endl;
	return area_circle;

}
int chapter2_3(string filename)
{
	vector<string> words;
		ifstream in (filename);
	string word;
	while(in >> word)
		words.push_back(word);
	cout << "文件中的单词为：" << endl;
	for (int i = 0; i < words.size(); i++)
		cout << words[i]<<endl;
	cout << "单词的数量为：" << words.size() << endl;
	return words.size();
}
int chapter2_4(string filename,string search_word)
{
	int count = 0;
	string word;
	vector<string> words;
	ifstream in(filename);
	while (in >> word)
		words.push_back(word);
	for (int i = 0; i < words.size(); i++)
	{
		if (words[i] == search_word)
			count++;
	}
	cout << "文件中" << search_word
		<< "的数量为：" << count << endl;
	return count;
}
void chapter2_5(string filename)
{
	string line_word;
	vector<string> lines;
	ifstream in(filename);
	while (getline(in,line_word))
	{
		lines.push_back(line_word);
	}
	for (int i = lines.size()-1; i >-1; i--)
		cout <<lines[i]<< endl;
}
string chapter2_6(string filename)
{
	string word ,all_word;
	vector<string> words;
	ifstream in(filename);
	while (in >> word)
		all_word += word;
	cout << all_word << endl;
	return all_word;
}
void chapter2_7(string filename)
{
	vector<string> lines;
	string line;
	char next_line;
	ifstream in(filename);
	if(in)
	{
		cout << "如果查看下一行请回车" << endl;
		do
		{
			if (getline(in, line))
			{
				cout << line << endl;
				//cin>>next_line;
				next_line = cin.get();
			}
			else
			{
				cout << "文件读取结束" << endl;
				break;
			}
		} while (next_line == '\n');
	}
	else
	{
		cout << "文件读取失败" << endl;
	}
}
void chapter2_8(void)
{
	vector<float> all_read_number;
	int N = 5;
	float read_number;
	for (int i = 0; i < N; i++)
	{
		cout << "请输入1个数据并以回车结束" << endl;
		cin >> read_number;
		all_read_number.push_back(read_number);
	}
	cout << "所输入的数据为" << endl;
	for (int i = 0; i < all_read_number.size(); i++)
	cout <<all_read_number[i] << endl;
}
void chapter2_9(void)
{
	vector<float> all_read_number1, all_read_number2, all_read_number3;
	int N = 5;
	float read_number;
	for (int i = 0; i < N; i++)
	{
		cout << "请输入第一组1个数据并以回车结束" << endl;
		cin >> read_number;
		all_read_number1.push_back(read_number);
	}
	for (int i = 0; i < N; i++)
	{
		cout << "请输入第2组1个数据并以回车结束" << endl;
		cin >> read_number;
		all_read_number2.push_back(read_number);
		all_read_number3.push_back(all_read_number1[i] + all_read_number2[i]);
	}
	cout << "前两个vector对应的元素相加的结果为：" << endl;
	for (int i = 0; i < all_read_number2.size(); i++)
	{
		cout << all_read_number3[i] << endl;
	}
}
void chapter2_10(void)
{
	vector<float> all_read_number;
	int N = 5;
	float read_number;
	for (int i = 0; i < N; i++)
	{
		cout << "请输入1个数据并以回车结束" << endl;
		cin >> read_number;
		all_read_number.push_back(read_number);
	}
	cout << "所输入的数据为" << endl;
	for (int i = 0; i < all_read_number.size(); i++)
		cout << all_read_number[i] << endl;
	cout << "平方后的数据为" << endl;
	for (int i = 0; i < all_read_number.size(); i++)
	{
		all_read_number[i] = all_read_number[i]*all_read_number[i];
		cout << all_read_number[i] << endl;
	}
}