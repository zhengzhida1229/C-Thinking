#include <iostream>
#include <string>
#include "chapter6.h"
using namespace std;

/*6_1*/
struct Simple
{
	int		 i;
	float	 j;
	Simple(void);
	~Simple(void);

};
Simple::Simple(void)
{
	cout << "构造函数已经被调用"  << endl;
	cout <<"int数值为：" <<i << endl;
	cout << "float数值为：" << j << endl;
}
Simple::~Simple(void)
{
	cout <<"析构函数已经被调用" << endl;

}
void chapter6_1(void)
{
	/*写一个简单的类Simple,其构造函数
	打印一些信息告诉我们它被调用*/
	struct Simple example;
	example.i = 1;
	example.j = 1.23;
	cout << "example.i:" << example.i << endl;
	cout << "example.i:" << example.i << endl;


}
void chapter6_2(void)
{
	/*析构函数在超出{}区域后就会执行*/
	{
		struct Simple example;
		example.i = 1;
		example.j = 1.23;
		cout << "example.i:" << example.i << endl;
		cout << "example.i:" << example.i << endl;
		cout << "析构函数是否输出0" << endl;
	}
	cout << "析构函数是否输出1" << endl;
}
void chapter6_4(void)
{
	struct Simple example;
	example.i = 1;
	example.j = 1.23;
	cout << "example.i:" << example.i << endl;
	cout << "example.j:" << example.j << endl;
	for (int i = 0; i < 10; i++)
		if (i == 5)
			goto tag1;
tag1:
	cout << "My" << endl;
}
void chapter6_5(void)
{
	int i = 0;
	for (i = 0; i < 11; i++)
		cout << i << endl;
	for (int j = 0; j < 11; j++)
		cout << j << endl;
	cout <<"第二部分" << endl;
	for (int i = 0; i < 11;i++)
		cout << i << endl;
}
void chapter6_6(void)
{
	cout <<"个人觉得可以不用做" << endl;
}
void chapter6_7(void)
{
	double dou_a[3] = { 1,2,3 };
	int n = sizeof(dou_a) / sizeof(dou_a[0]);
	for (int i = 0; i < n; i++)
		cout << dou_a[i] << endl;
	double dou_b[] = { 1,2,3,4 };
	int m = sizeof(dou_b) / sizeof(dou_b[0]);
	for (int i = 0; i < m; i++)
		cout << dou_b[i] << endl;
}
/*创建一个没有构造函数的类，显示我们可以通过默认的
构造函数创建对象。现在创建一个非默认的构造函数，编译试试看*/
struct struct6_10
{
	int     i;
	float   j;
	struct6_10(int a);
};
struct6_10::struct6_10(int a)
{
	i = a;
}
void chapter6_10(void)
{


	/*第一种情况*/
	//struct struct6_10 example1;
	/*第二种情况*/
	struct struct6_10 example1= struct6_10(1);
	


}