#include <iostream>
#include <fstream>
#include <string>
#include "chapter7.h"
using namespace std;
/*7-1*/
struct Text 
{
	string file_content;
	string contents(void);
	Text();
	Text(string file_name);
private:
	string s;
};
Text::Text()
{};
Text::Text(string file_name)
{
	ifstream open_read(file_name);
	string line;
	while (getline(open_read, line))
		s +=line+"\n";
}
string Text::contents(void)
{
	cout << s << endl;
	return s;
}
void chapter7_1(void)
{
	struct Text Tex("chapter6.h");
	Tex.contents();
}
struct Message
{
private:
	string pri_str;
public:
	Message(string str);
	void print(void);
	void print(string str);
};
Message::Message(string str)
{
	pri_str = str;
}
void Message::print(void)
{
	cout << "private	string is" << pri_str << endl;
}
void Message::print(string str)
{
	cout << "������ַ���Ϊ��" <<str<< endl;
	cout << "private	string is" << pri_str << endl;
}
void chapter7_2(void)
{
	struct Message example("ok");
	example.print();
	example.print("wodexuexi");
}
/*7-3*/
struct stru7_4
{
	void fun(void);
	//void fun(int intnum1 );
	//void fun(int intnum1,int intnum2);
	//void fun(int intnum1, int intnum2, int intnum3);
};
void stru7_4::fun(void)
{
	cout <<"û������" << endl;
}
/*
void stru7_4::fun(int intnum1)
{
	cout <<"����Ϊ" << intnum1 << endl;
}
void stru7_4::fun(int intnum1,int intnum2 )
{
	cout << "����Ϊ" << intnum1 << "��"
		<< intnum2 <<endl;
}
void stru7_4::fun(int intnum1, int intnum2, int intnum3)
{
	cout << "����Ϊ" << intnum1 << "��"
		<< intnum2 <<"��"<< intnum3 << endl;
}*/
void chapter7_4(void)
{
	/*��Ҫ�޸�main����*/
	struct stru7_4 stru7_4_examp;
	stru7_4_examp.fun();
	/*
	stru7_4_examp.fun(1);
	stru7_4_examp.fun(1,2);
	stru7_4_examp.fun(1,2,3);*/
}
/*�����������������ĺ�������main()�е�������
Ȼ����һ��������Ϊ��ռλ����
�۲�main()�еĵ����Ƿ�ı�*/
void chapter7_5_1(int num1,int num2)
{
	cout << "�������ĺ�Ϊ��"<< (num1 + num2)<< endl;
}
void chapter7_5_2(int num1, int)
{
	cout << "�������ĺ�Ϊ��" << (num1) << endl;
}
void chapter7_5(void)
{
	/*����û�иı䣬���������һ��
	�����ĵڶ�������ʹ�õĻ��ͻ����*/
	chapter7_5_1(1, 1);
	chapter7_5_2(1, 1);
}
/*�޸�SuperVar�Ա������е�vartype����ǰ��#ifdef
��vartype��Ϊһ�������ö�����ͣ��޸�print(),
ʹ����Ҫ��vartype�����ܸ�������ʲô*/
class SuperVar
{


};
void chapter7_8(void)
{

}