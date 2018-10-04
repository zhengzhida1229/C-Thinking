#include <iostream>
#include <cstdio>
#include <string>
#include <cstdio>
#include "chapter10.h"
#include "require.h"
#include "mynamespace1.h"
#include "unnamespace.h"

namespace MNS = MyNamespace;
using namespace std;
/*10_1*/
/*创建一个函数(带一个默认值为零)，函数内有一个静态变量的
这个静态变量是一个指针。当调用者为这个参数提供值时，他就指向
一个整形数组的起始地址。如果用默认的参数值调用该函数，那么
这个函数就返回数组的下一个值，直到它访问到数组中的“-1”
（在数组中，-1作为结束标志），在函数main()中调用这个函数*/
int chapter10_1_1(int int_num)
{
	static int i = 0;
	int int_num_array[100] = { 1,2,3,3,2,2,2 };
	static int* int_pointer = int_num_array;
	if (int_num == 0)
		return *int_pointer;
	else if (*(int_pointer + i) != '-1')
	{
		i++;
		return *(int_pointer + i);
	}
}
void chapter10_1_2(void)
{
	int int_num;
	for (int i = 0; i < 10; i++)
		cout << "返回值为：" << chapter10_1_1(i) << endl;
}
/*chapter10_2*/
/*创建函数，使得每调用一次，就返回Fibonacci序列的下一个值。
增加一个bool类型的参数，其默认值为false，当传递给参数的值为
true时指向序列的开头*/
int chapter10_2_1(bool true_false)
{
	static int count = 1;
	int F_n3 = 0;
	static int F_n1 = 1, F_n2 = 1;
	if (true_false)
	{
		F_n1 = 1;
		F_n2 = 1;
		count = 1;
	}
	if (count == 1 || count == 2)
		F_n3 = 1;
	else
	{
		F_n3 = F_n1 + F_n2;
		F_n1 = F_n2;
		F_n2 = F_n3;
	}
	cout << "count" << count << endl;
	count = count + 1;
	return F_n3;
}
void chapter10_2_2(int times)
{
	bool true_false = 0;
	int Fibonacci_i;

	for (int i = 1; i < times; i++)
	{	/*每10个回到初始位置*/
		if (i % 10 == 0)
			true_false = true;
		else
			true_false = false;
		Fibonacci_i = chapter10_2_1(true_false);
		cout << "Fibonacci_i:\t" << Fibonacci_i << endl;
	}
}
/*chapter10_3*/
/*
class class_chap10_3
{
public:
	inline class_chap10_3(int num1 = 0);
	int size;
	const int const_int = 6;
	int* int_pointer = new int[size];
	inline void print(void);
	static int sta_int;
};

//int class_chap10_3::sta_int = 1;

inline class_chap10_3::class_chap10_3(int sz)
{
	sta_int = 1;
	size = sz;
	for (int i = 0; i < size; i++)
		* (int_pointer + i) = sta_int;
}
inline void class_chap10_3::print(void)
{
	for (int i = 0; i < size; i++)
		cout << *(int_pointer + i) << endl;
}
*/
/*有问题*/
/*
void chapter10_3(void)
{
	class class_chap10_3 example(10);
	example.print();
}
*/
/*chapter10_4*/

class Monitor
{
static int counter;
public:
int incident(void);
void print(void);
};
int Monitor::counter = 0;
int Monitor::incident(void)
{
counter = counter + 1;
return counter;
}
void Monitor::print(void)
{
cout << "incident() 被调用的次数为：" << counter << endl;
}

void chapter10_4(void)
{
	class Monitor example;
	int max_counter = 10;
	for (int i = 0; i <max_counter; i++)
		example.incident();
	example.print();
}

/*chapter10_5*/
void chapter10_5(void) {}
void chapter10_6(void) {}
/*chapter10_7*/
inline  class_chapter10_7::class_chapter10_7(void)
{
	cout <<"class_chapter10_7的成员i的数值为：" <<i << endl;
	exit(0);
}
void chapter10_7(void) 
{
	class class_chapter10_7 example;
	example.i = 10;
}
/*chapter10_8*/
/*在StaticDestructors.cpp中，在main()内用不同的顺序调用f()
g()来检验构造函数与析构函数的调用顺序*/
void chapter10_8(void)
{
}
void chapter10_9(void)
{
}
void chapter10_10(void)
{
	global_static=1;
	cout <<"global_static" << global_static << endl;
	//在main()中
	/*
	global_static = 2;
	cout << "global_static" << global_static << endl;
	*/	
}
/*chapter10_11*/
/*
class class_chapter10_11
{
public:
	int int_num;
	void set_value(int num1);
	void print(void);
	class_chapter10_11(int num2);
};*/

class_chapter10_11::class_chapter10_11(int num2)
{
	int_num = num2;
}
void class_chapter10_11::print(void)
{
	cout << "class_chapter10_11的数字为：" << int_num << endl;
}
static class class_chapter10_11 class_chapter10_11_example(10);
void chapter10_11(void)
{
	/*在main()中部分*/
	/*
	extern class class_chapter10_11 class_chapter10_11_example(10);
	class_chapter10_11_example.print();
	*/
}
void chapter10_12(void);
void chapter10_13(void);
/*chapter10_14*/
void chapter10_14(void);
void chapter10_15(void)
{
	auto auto_int=1;
	register int regi_int = 10;
	cout <<"auto_int:" << auto_int << "\t auto auto_int的大小为："<<sizeof(auto_int) << endl;
	cout << "regi_int:" << regi_int << endl;
}
void chapter10_16_1(void)
{
	MNS::f();
}

void chapter10_16_2(void)
{
	using namespace MNS;
	g();
}
void chapter10_17_1(int int_num, float flo_num)
{
	i_num = int_num;
	f_num = flo_num;
	cout <<"i_num " << i_num << endl;
	cout << "f_num" << f_num << endl;
}
/*chapter10_17_2放在main()里*/
/*
void chapter10_17_2(int int_num, float flo_num)
{
	i_num = int_num;
	f_num = flo_num;
	cout << "i_num " << i_num << endl;
	cout << "f_num" << f_num << endl;
}
*/
void chapter10_18(void);
/*修改FriendInjection.cpp文件中，增加友元函数的定义，在main()中调用它*/
namespace Me {
	class Us {
		//...
		friend void you();
		friend void you1();
	};
	void you() {
	}
	void you1() {
		cout <<"I am you friend" << endl;
	}
}
void chapter10_19(void)
{
	Me::you1();
}
/*在Arithmetic.cpp说明在一个函数中的using指令
不能扩展到这个函数的范围内*/
void chapter10_20_1(void)
{
	using namespace MyNamespace;
	f();
}
void chapter10_20_2(void)
{
	//g();
}
/*修改OverridingAmbiguity.cpp，先使用作用域运算符，然后用
using声明代替作用域运算符来强迫编译器选择其中某个同名的函数名*/
/*
#include "NamespaceMath.h"
#include "NamespaceOverriding2.h"
*/
void chapter10_21(void)
{
	/*在OverridingAmbiguity.cpp的文件里的main()函数进行的实验*/
	/*
	using namespace Calculation;
	divide(1, 2);
	using Math::divide;
	// Everything's ok until:
	divide(1, 2); // Ambiguity
	*/
}
void chapter10_22(void)
{
	/*与chapter10_21的情况相同*/
}
void chapter10_23(void)
{
	/*与chapter10_21的情况相同*/
}
