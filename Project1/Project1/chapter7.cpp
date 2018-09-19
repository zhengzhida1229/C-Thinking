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
	cout << "输入的字符串为：" <<str<< endl;
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
	cout <<"没有数据" << endl;
}
/*
void stru7_4::fun(int intnum1)
{
	cout <<"参数为" << intnum1 << endl;
}
void stru7_4::fun(int intnum1,int intnum2 )
{
	cout << "参数为" << intnum1 << "和"
		<< intnum2 <<endl;
}
void stru7_4::fun(int intnum1, int intnum2, int intnum3)
{
	cout << "参数为" << intnum1 << "和"
		<< intnum2 <<"和"<< intnum3 << endl;
}*/
void chapter7_4(void)
{
	/*需要修改main函数*/
	struct stru7_4 stru7_4_examp;
	stru7_4_examp.fun();
	/*
	stru7_4_examp.fun(1);
	stru7_4_examp.fun(1,2);
	stru7_4_examp.fun(1,2,3);*/
}
/*创建带有两个参数的函数，在main()中调用它。
然后让一个参数作为”占位符“
观测main()中的调用是否改变*/
void chapter7_5_1(int num1,int num2)
{
	cout << "两个数的和为："<< (num1 + num2)<< endl;
}
void chapter7_5_2(int num1, int)
{
	cout << "两个数的和为：" << (num1) << endl;
}
void chapter7_5(void)
{
	/*调用没有改变，但是如果第一个
	函数的第二个参数使用的话就会出错。*/
	chapter7_5_1(1, 1);
	chapter7_5_2(1, 1);
}
/*修改SuperVar以便在所有的vartype代码前有#ifdef
让vartype成为一个常规的枚举类型，修改print(),
使得他要求vartype参数能告诉它做什么*/
class SuperVar
{


};
void chapter7_8(void)
{

}