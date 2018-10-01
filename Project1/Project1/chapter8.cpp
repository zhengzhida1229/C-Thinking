#include "chapter8.h"
#include <iostream>
#include <ctime>
using namespace std;
const int* chapter8_1(const int num1, const int num2, const int num3)
{
	const int sum = num1 + num2 + num3;
	const int* const_int_pointer = new int[sum];
	int* temp= new int[sum];
	for (int i = 0; i < sum; i++)
		temp[i] = i;
	const_int_pointer = temp;
	return const_int_pointer;
}
const int chapter8_2(void)
{
	extern const int chap8_2_1;
	const int chap8_2_2 = 2;
	const int chap8_2_3 = 3;
	const int chap8_2 = chap8_2_1 + chap8_2_2 + chap8_2_3;
	return chap8_2;
}
void chapter8_3(void)
{
	/*不理解题意*/
}
void chapter8_4(void)
{
	/*在头文件中创建const并包含在两个cpp文件中*/
	/*8-2中就包含了该情况*/
}
void chapter8_5(void)
{
	time_t time1;
	time1 = time(NULL);
	const time_t now_time = time1;
	for (int i = 1; i < 10000; i++)
		;
	time1=time(NULL);
	//now_time = time1;//不可以，编译不通过，const在初始化之后不能在改变
	cout <<"程序最后时间为：" << now_time <<endl;
}
void chapter8_6(void)
{
	
	const char con_cha[] = "zhengzhida";
	int size = sizeof(con_cha)/sizeof(con_cha[0]);
	//con_cha[size - 1] = 'c';//试图修改会出错
}
void chapter8_7(void)
{
	extern const int chap8_7;
	cout << "chapter8_7的const值为:"<<chap8_7 << endl;
}
void chapter8_8(int size)
{
	/*使用不同的声明形式创建两个指向const long的指针
	，一个指向long数组，演示能让指针增加、减少，但不能
	改变内容*/
	const long* con_lon_poin;
	long const* con_lon_poin2;
	long *lon_num = new long[size];
	for (int i = 0; i < size; i++)
	{
		lon_num[i] = i;
	}
	for (int i = 0; i < size; i++)
	{
		con_lon_poin = &lon_num[i];
		cout <<"const long 的指针的内容为：" <<*con_lon_poin << endl;
	}
	//con_lon_poin = 24;//编译会出错
}
void chapter8_9(int size)
{
	/*写一个指向double类型的const指针，让它指向double数组
	显示能改变指针的内容，但是不能增加或减小指针*/
	double* dou_num = new double[size];
	for (int i = 0; i < size; i++)
	{
		dou_num[i] = i;
	}
	double * const d_con_dou=&dou_num[0];
	cout << "double * const的数值为："<<*d_con_dou << endl;
	*d_con_dou = 123;
	//d_con_dou= &dou_num[1];//会出错
	cout << "double * const的数值为：" << *d_con_dou << endl;
}
void chapter8_10(int size)
{
	int* int_num = new int[size];
	for (int i = 0; i < size; i++)
	{
		int_num[i] = i;
	}
	const int *const  con_int_con=&int_num[size-1];
	cout <<"const int *const的数值为：" <<*con_int_con <<endl;
	//con_int_con = &int_num[0];//出错
	//*con_int_con = 123;//出错
}
void chapter8_11(void)
{
}
void chapter8_12(void)
{
	/*在这环境下可以改变数组的内容，没有报错*/
	char char_array[] = "zhengzhida";
	char* char_pointer = char_array;
	int size = sizeof(char_array) / sizeof(char_array[0]);
	for (int i = 0; i < size; i++)
	{
		cout << "数组改变之前的内容为：" << char_array[i] << endl;
		* (char_pointer + i) = 'a' + i;
		cout << "指针的内容为：" << *(char_pointer + i) << endl;
		cout << "数组的内容为：" << char_array[i] << endl;
	}
}
void chapter8_13(const int const_int)
{
	/*创建一个函数，它带有一个以const值传递的参数
	然后在函数体内试图改变该参数*/
	int temp = const_int;
	//const_int = (const_int + 1);//出错，在函数体内不可改变该值
}
void chapter8_14(float fnum)
{
	/*创建函数，带有按值传递的float参数，在函数体中
 把const float&绑定到函数的参数上，并且从那时起
 仅仅使用引用，以确保不改变参数*/
	const float& con_flo = fnum;
	//con_flo++;//会出错，不能改变该值
	cout << "输入的数值为："<< con_flo <<endl;
}
void chapter8_15(float fnum)
{
	/*ConstReturnValues.cpp文件，每次删除错误行的注释，
	看看编译器会产生什么错误信息*/
	/*以下为ConstReturnValues.cpp的内容*/
	/*
	class X 
	{
	int i;
	public:
	X(int ii=0);
	void modify();
	};
	X::X(int ii){i=ii;}
	void X::modify{i++;}
	X f5()
	{
	 return X();
	}
	const X f6()
	{
	return X();
	}
	void f7(X& x)
	{
	x.modify();
	}
	int main()
	{
	f5=X(1);
	f5.modify();
	//!f7(f5());
	//f6()=X(1);//f6()返回值为const不能作为左值
	//f6().modify();
	//f7(f6());		//会产生一个临时量
	}	
	*/
}
void chapter8_16(float fnum)
{
	/*ConstPointer.cpp文件，每次删除错误行前的注释，
	看看编译器会产生什么错误信息*/
	/*下面是ConstPointer.cpp文件*/
	/*
	void t(int*){}
	void u(const int* cip)
	{
	//!*cip=2;//Illegal --modify value
	int i=*cip;//ok--copy value
	//int* ip2=cip;//Illegal:non-const
	}
	const char* v()
	{
	 return "result of function v()";
	}
	const int* const w()
	{
	static int i;
	return &i;
	}
	int main()
	{
		int x=0;
		int* ip=&x;
		const int* cip =&x;
		t(ip);
		//t(cip);//const int*不能隐式的转化为int*
		u(ip);
		u(cip);
		// char* cp=v();//v()的返回值为const char*,只能赋值给const char*
		const char* ccp = v();
		//int* ip2=w();//类型不匹配
		const int* const ccip = w();
		const int* cip2 = w();
		//*w()=1;//试图改变const int* const的内容
		}
	*/
}
void chapter8_17(float fnum)
{
	/*制造文件ConstPointer.cpp的新版，名为ConstReference.cpp
	其中把前者使用的指针用引用代替*/
	/*下面是ConstPointer.cpp文件*/
	/*
	void t(int*){}
	void u(const int* cip)
	{
	//!*cip=2;//Illegal --modify value
	int i=*cip;//ok--copy value
	//int* ip2=cip;//Illegal:non-const
	}
	const char* v()
	{
	return "result of function v()";
	}
	const int* const w()
	{
	static int i;
	return &i;
	}
	int main()
	{
	int x=0;
	int* ip=&x;
	const int* cip =&x;
	t(ip);
	//t(cip);//const int*不能隐式的转化为int*
	u(ip);
	u(cip);
	// char* cp=v();//v()的返回值为const char*,只能赋值给const char*
	const char* ccp = v();
	//int* ip2=w();//类型不匹配
	const int* const ccip = w();
	const int* cip2 = w();
	//*w()=1;//试图改变const int* const的内容
	}
	*/
}
void chapter8_18(float fnum)
{
	/*修改ConstTemporary.cpp文件，删除错误行前的注释
	看看编译器会产生什么错误信息*/
	/*
	class X{};
	X f() {return X();}//return by value
	void g1(X&){} //Pass by non-const reference
	void g2(const X&) {} Pass by const reference
	int main()
	{
		//Error:const temporary created by f():
		//!g1(f());
		g2(f());
	}
	*/
}


/*创建一个包含const和非const float成员的类。
用构造函数的初始化列表进行初始化*/
class class_chap8_19
{
public:
	const float a;
	float b;
	class_chap8_19() :a(1), b(2)
	{}
};
void chapter8_19(void )
{
	class class_chap8_19 class_example;
	cout <<"类中的a为：" << class_example.a << endl;
	cout << "类中的b为：" << class_example.b << endl;
}
void chapter8_20(void)
{
}
void chapter8_21(void)
{
	/*创建包含一个const成员和一个枚举成员的类。
	在构造函数的初始化列表中初始化const成员，无标记的
	枚举类型成员来决定数组的大小*/
}
void chapter8_22(void)
{
	/*在ConstMember.cpp文件中，删除成员函
	数定义前的const限定符，但是让const限定符
	出现在声明中，看看编译器会出何种错误
	下面为ConstMember.cpp*/
	/*
	class X
	{
		int i;
	public:
		X(int ii);
		int f() const;
	};
	X::X(int ii) :i(ii) {}
	int X::f()const {return i;}//删除const会出现没有找到重载的成员函数
	int main()
	{
	X x1(10);
	const X x2(20);
	x1.f();
	x2.f();
	}
	*/
}
/*8-23*/
class class_chap8_23
{
public:
	int i;
	int j;
	int fun1(void);
	const int fun2 (void);
	class_chap8_23() :i(1),j(2) {};
};
int class_chap8_23::fun1(void)
{
	cout <<"class_chap8_23的i为：" << i<< endl;
	return i;
}
const int class_chap8_23::fun2(void)
{
	cout << "class_chap8_23的j为：" << j << endl;
	return 2;
}
void chapter8_23(void)
{
/*创建一个类，有一个const和非const成员函数。
在创建该类的const和非const对象，用不同类型
的对象调用不同类型的成员函数*/
	const class class_chap8_23 example1;
	class class_chap8_23 example2;
	//example1.fun2();//const的对象不能调用里面的函数
	example2.fun2();
}
void chapter8_24(void)
{
	/*前面8-23里有*/
}
void chapter8_25(void)
{
	/*Mutable.cpp文件中，删除错误行前的注释，
	看看编译器会产生什么错误信息*/
	/*
	class Z{
	int i;
	mutable int j;
	public:
	Z();
	void f() const;
	};
	Z::Z():i(0),j(0){}
	void Z::f() const
	{
	//i++;//Error -const member function
	j++;
	}
	int main()
	{
	const Z zz;
	zz.f();//Actually changes it!
	}
	*/
}
void chapter8_26(void)
{
	/*修改Quoter.cpp文件的函数quote(),使它变为
	const成员函数和lastquote mutable*/
}
/*8-27*/
class class_8_27
{
public:
	volatile int num1;
	void fun1(void)volatile;
	void fun2(void);
	class_8_27() :num1(0) {};
};
void class_8_27::fun1(void)volatile
{
	num1++;
	cout << num1 << endl;
}
void class_8_27::fun2(void)
{
	num1=num1+10;
	cout << num1 << endl;
}
void chapter8_27(void)
{
	/*创建一个类volatile数据成员，创建一个volatile和
	非volatile成员函数用于修改volatile数据成员。看看
	编译器会出现什么情况，创建该类的volatile和非volatile
	对象，尝试调用volatile和非volatile函数，看看那一个会调用成功*/
	volatile class class_8_27 example;
	class class_8_27 example1;
	example.fun1();
	//example.fun2();//volatile调用非volatile出错
	example1.fun1();
	example1.fun2();
}
/*创建一个*/
class bird
{
public:
	int i;
	void fly(void);
	bird() :i(5) {};
};
void bird::fly(void)
{
	cout << "class bird的i为："<< i<<  endl;
}
class rock
{
public:
	int i;
	rock() :i(50) {};
};
void chapter8_28(void)
{
	class bird bird_example;
	class rock rock_example;
	void* rock_pointer = &rock_example;
	void* bird_pointer=rock_pointer;
	//bird_pointer.fly()
}