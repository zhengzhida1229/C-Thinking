#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include "chapter2.h"
using namespace std;
void chapter2_1(void)
{
	cout << "�ҵ����֣�֣־��\n"
		<< "���䣺25\n" << endl;
}
float chapter2_2(void)
{
	float PI = 3.141592, area_circle, r;
	cout << "������Բ�İ뾶:" << endl;
	cin >> r;
	area_circle = PI*r*r;
	cout << "��Բ�����Ϊ��" << area_circle << endl;
	return area_circle;

}
int chapter2_3(string filename)
{
	vector<string> words;
		ifstream in (filename);
	string word;
	while(in >> word)
		words.push_back(word);
	cout << "�ļ��еĵ���Ϊ��" << endl;
	for (int i = 0; i < words.size(); i++)
		cout << words[i]<<endl;
	cout << "���ʵ�����Ϊ��" << words.size() << endl;
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
	cout << "�ļ���" << search_word
		<< "������Ϊ��" << count << endl;
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
		cout << "����鿴��һ����س�" << endl;
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
				cout << "�ļ���ȡ����" << endl;
				break;
			}
		} while (next_line == '\n');
	}
	else
	{
		cout << "�ļ���ȡʧ��" << endl;
	}
}
void chapter2_8(void)
{
	vector<float> all_read_number;
	int N = 5;
	float read_number;
	for (int i = 0; i < N; i++)
	{
		cout << "������1�����ݲ��Իس�����" << endl;
		cin >> read_number;
		all_read_number.push_back(read_number);
	}
	cout << "�����������Ϊ" << endl;
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
		cout << "�������һ��1�����ݲ��Իس�����" << endl;
		cin >> read_number;
		all_read_number1.push_back(read_number);
	}
	for (int i = 0; i < N; i++)
	{
		cout << "�������2��1�����ݲ��Իس�����" << endl;
		cin >> read_number;
		all_read_number2.push_back(read_number);
		all_read_number3.push_back(all_read_number1[i] + all_read_number2[i]);
	}
	cout << "ǰ����vector��Ӧ��Ԫ����ӵĽ��Ϊ��" << endl;
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
		cout << "������1�����ݲ��Իس�����" << endl;
		cin >> read_number;
		all_read_number.push_back(read_number);
	}
	cout << "�����������Ϊ" << endl;
	for (int i = 0; i < all_read_number.size(); i++)
		cout << all_read_number[i] << endl;
	cout << "ƽ���������Ϊ" << endl;
	for (int i = 0; i < all_read_number.size(); i++)
	{
		all_read_number[i] = all_read_number[i]*all_read_number[i];
		cout << all_read_number[i] << endl;
	}
}