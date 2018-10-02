#include "chapter9.h"
#include "require.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <string.h>
using namespace std;

void chapter9_1(float num)
{
	/*写一个使用本章开头出现的F()宏的程序，证明它就像在
	本章中所说的那样不能正确的扩展，修改并使其正确运行*/
	
	float i = F(num);
	cout << "F(x)的值为：" << i << endl;
}
void chapter9_2(int num)
{
	/*写一个使用本章开头出现的FLOOR()宏的程序，说明它在什么情况下不能正常运行*/
	int i = FLOOR(num & 0x0f, 0x07);
	if(i)
		cout <<"FLOOR(num & 0x0f, 0x07)" <<i <<endl;
}
void chapter9_3(void)
{
	/*修改MacroSideEffects.cpp，使得BAND()能够正常运行*/
	ofstream out("macro.out");
	for (int i = 4; i < 11; i++)
	{
		int a = i;
		out <<"a=" <<a << endl<< '\t';
		cout << "a=" << a << endl << '\t';
		out << "BAND(a)=" << BAND(a) << endl;
		cout << "BAND(a)=" << BAND(a) << endl;
		out << "\t a=" << a << endl;
		cout << "\t a=" << a << endl;
	}
}
inline clock_t chapter9_4_1(void)
{
	clock_t time_diff;
	clock_t time1;
	time1 = clock();
	for (int i = 1; i < 1000; i++)
		for (int j = 1; j < 1000; j++)
		;
	clock_t time2= clock();
	time_diff = time2 - time1;
	return time_diff;
}
clock_t chapter9_4_2(void)
{
	clock_t time_diff;
	clock_t time1;
	time1 = clock();
	for (int i = 1; i < 1000; i++)
		for (int j = 1; j < 1000; j++)
		;
	clock_t time2= clock();
	time_diff = time2 - time1;
	return time_diff;
}
void chapter9_4(void)
{
	/*创建两个功能相同的函数f1()和f2(),其中f1()是内敛函数
	f2()是非内联函数，使用<ctime>中的标准C库函数clock()标记
	函数的开始点和结束点，哪一个快*/
	clock_t time1 = chapter9_4_1();
	clock_t time2 = chapter9_4_2();
	cout << "函数1花费的时间为：" << time1 << endl;
	cout << "函数2花费的时间为：" << time2 << endl;
}
void chapter9_5(void)
{
	/*对练习4中的代码的复杂性和大小做测试，
	在内敛和非内敛的做一个平衡*/
	/*实验的结果为inline花费的时间比较高，与理论相反*/
}
void chapter9_6(void)
{

}

/*chapter9_7*/
/*创建一个类，包含一个整型数组。增加一个内联构造函数
和一个内联成员函数print().内联构造函数使用标准的C库函数
memset()初始化对应于构造函数的参数（默认时为零）的数组
内联函数print()打印数组的所有元素值*/
class class_chap9_7
{
public:
	inline class_chap9_7( int num=0);

	int size=10;
	int *int_num = new int[size];
	inline void print(void);
};
inline class_chap9_7::class_chap9_7(int num)
{
	
	memset(int_num, num, sizeof(int)*size);
}
inline void class_chap9_7::print(void)
{
	for (int i = 0; i < size; i++)
		cout << int_num[i] << endl;
}

void chapter9_7(void)
{
	 class_chap9_7 class_example(0);	 
	 class_example.print();
	 /*memse()对于多字节的类型只能初始化为0，
	 因为是按照自节的顺序来初始化的*/
}
/*9-7*/
/*第五章的例子NestFriend.cpp中的所有成员函数改成内联函数，
并使他们为非in situ（在类的外面定义，加上inline标志）内联函数，也对于构造函数改造initalize()函数*/
void chapter9_8(void)
{

}
void chapter9_9(void)
{

}
/*9_10*/
/*创建一个称为Hue的enum，它包含red、blue和yellow。创建一个color类
，该类包含一个Hue类型的数据成员，其构造函数用参数设置这个数据成员
的值。增加访问函数用来获取和设置Hue这个数据成员的值，所有函数
使用内联函数*/
enum Hue
{
	red=0,
    blue,
    yellow,	
};
class color
{
public:
	enum Hue example;
	int i;
	inline int getHue(void);
	inline int setHue(enum Hue HueEnum);
	inline int getcolor(void);
	inline color(int num=0, enum Hue HueEnum=red);
};
inline int color::getHue(void)
{
	return example;
}
inline int color::setHue(enum Hue HueEnum)
{
	if (HueEnum > 0 && HueEnum < 3)
		example = HueEnum;
	else
	{
		cout << "枚举值超出范围" << endl;
		return 0;
	}
}
inline int color::getcolor(void)
{
	return i;
}
inline color::color(int num , enum Hue HueEnum )
{
	i = num;
	example = HueEnum;
}
void chapter9_10(void)
{
	enum Hue Hue_example = yellow;
	class color color_example(50, Hue_example);
	
	int m=color_example.getHue();
	cout <<"color_example.getHue()" <<m<< endl;
	cout << "color_example.getcolor()" << color_example.getcolor() << endl;
	
	Hue_example = blue;
	color_example.setHue(Hue_example);
	m = color_example.getHue();
	cout << "color_example.getHue()" << m << endl;
	color_example.i = 20;
	cout << "color_example.getcolor()" << color_example.getcolor() << endl;
}
void chapter9_11(void)
{
	/*使用访问器和修改器的方法修改练习10中的程序*/
	/*练习10中就是这样的形式*/
}
/*9_12*/
/*修改程序Cpptime.cpp，使它从程序的开始运行时开始计时，直到用户
按确认(Enter)或回车(Return)*/
void chapter9_12(void)
{
	clock_t start = clock();
	clock_t end;
	cout <<"如果想要停止计时就按下enter键" << endl;
	char c = cin.get();
	if (c == 10 || c == 13)
		end= clock();
	cout <<"花费的时间为：" << end- start << endl;
}
/*创建一个类包含两个成员函数，在第一个成员函数
调用第二个成员函数，不需要提前声明*/
class class_chap9_13
{
public:
	int i;
	inline void fun1(int m);
	inline int fun2(void);
};
inline void class_chap9_13:: fun1(int m)
{
	i = m;
	cout <<"class_chap9_13的i为：" << fun2()<<endl;
	i = m+1;
	cout << "class_chap9_13的i为：" << fun2() << endl;
}
inline int class_chap9_13::fun2(void)
{
	return i;
}



void chapter9_13(void)
{
	class class_chap9_13 example;
	example.fun1(10);
}
/*9_14*/
/*创建一个类A，能声明自己的内联的默认的构造函数，
再创建一个类B，将A类的一个对象作为B的成员，B的
构造函数也是内联的，创建一个B类的对象数组*/
class class_chap9_13_A
{
public:
	int int_num;
	class_chap9_13_A(int num=0);
};
inline class_chap9_13_A::class_chap9_13_A(int num)
{
	int_num = num;
}
class class_chap9_13_B
{
public:
	class class_chap9_13_A example_A;
	int j;
	class_chap9_13_B(int num1=1);
};
inline class_chap9_13_B::class_chap9_13_B(int num1)
{
	j = num1;
}
void chapter9_14(void)
{
	class class_chap9_13_B class_B_example[10];
	for (int i = 0; i < 10; i++)
		cout << class_B_example[i].example_A.int_num 
		<< '\t' << class_B_example[i].j << endl;
}
void chapter9_15(void)
{
	/*从以前的练习的类中创建大量的对象并使用Time
	类来计算计算非内联构造函数和内联构造函数之间的
	时间差别*/
}
/*chapter9_16*/
/*写一个带有一个string命令行参数的程序，写一个for循环
，循环每执行一步就去掉string的一个字母并使用每章的DEBUG()
宏打印string*/
void chapter9_16(string str)
{
	string str1;
	int sz = str.size();
	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz - i;j++)
		DEBUG(str[j]);
	}
}
/*正确的修改TRACR()宏，使它成为本章指定的特定的宏，
并使它能够正确的运行*/
void chapter9_17(string str)
{
	int sz = str.size();
	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz - i; j++)
			TRACE(str[j]);
	}		
}
/*修改FIELD()宏，使它含有一个索引(index)号，创建一个类，它的成员有一些
对FIELD()宏的调用组成，增加一个成员函数，它允许使用索引号查看域，写一个
主函数main()测试这个类*/
void chapter9_18(string str)
{
}
void chapter9_19(string str)
{
}
/*9-20*/
/*写一个程序，它带有两个参数，一个整数，一个文件名
使用require.h以确保参数数目正确，并且整数在5到10之间
文件能够成功地打开*/
int chapter9_20(int num,const string & string_p)
{
	if (num > 5 && num < 10)
		;
	else
	{ 
		cout << "整数的参数不在5到10之间" << endl;
		return 0;
	}	
	ifstream open_read(string_p);
	assure(open_read,string_p);
	return 1;
}
/*9_21*/
/*写一个IFOPEN()宏的程序，用它来打开一个文件并作为一个
输入流，注意ifstream对象的创建以及它的作用域*/
void chapter9_21(const string string_p)
{
	//IFOPEN(string_p);
}
void chapter9_22(const string string_p)
{

}