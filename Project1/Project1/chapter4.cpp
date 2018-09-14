#include <stdio.h>
#include <iostream>
#include <cassert>
#include "chapter4.h"
using namespace std;
void chapter4_1(void)
{
	/*本人目前没有感受到差异*/
	puts("hello");
}
typedef struct
{
	int chapter4_2_1(int num);
}my_struct;
int my_struct::chapter4_2_1(int num)
{
	cout << "输入的数字为：" << num << endl;
	return num - 1;
}
void chapter4_2(void)
{
	/*结构体的定义，结构体成员中包含的函数的定义
	也应该与结构体的定义的范围为同级；均在调用函数的外部*/
	my_struct struct_example1;
   int x= struct_example1.chapter4_2_1(3);
   cout << "返回的结果为：" << x << endl;
}

// chapter4_3部分
 struct struct1
{
	int chapter4_3_1(int num);
};

 int struct1::chapter4_3_1(int num)
 {
	 cout << "输入的数字为：" << num << endl;
	 return num - 1;
 }

void chapter4_3(void)
{
	struct struct1 struct1_example;
	int x = struct1_example.chapter4_3_1(5);
	cout << "返回的结果为：" << x << endl;
}
/*创建一个struct，含有一个int数据成员和两个全局函数，
每个函数接受一个指向该函数的指针，第一个函数的第2个参数为int型
并将其赋值给结构体的int变量，第二个函数则打印结构体的int变量值*/
struct struct4_5
{
	int int_num;
	void chapter4_5_1(struct4_5 *struct4_5example, int num);
	void chapter4_5_2(struct4_5 *struct4_5example);
};
void struct4_5::chapter4_5_1(struct4_5 *struct4_5example, int num)
{
	struct4_5example->int_num = num;
	cout <<"结构体的int型参数为："<< struct4_5example->int_num << endl;
}
void struct4_5::chapter4_5_2(struct4_5 *struct4_5example)
{
	cout << "结构体的int型参数为：" << struct4_5example->int_num << endl;
}
void chapter4_5(void)
{
	struct struct4_5 struct_example;
	struct_example.int_num = 10;
	struct_example.chapter4_5_1(&struct_example, 9);
	struct_example.chapter4_5_2(&struct_example);
}
/*创建一个类，使用关键字this执行数据成员选择和成员函数的调用 
this 一般是用在类的内部函数中，尤其是在类的成员函数中
有与结构体相同的变量*/
class class4_6
{
public:
	int age;
	int chapter4_6_1(class4_6 class4_6_example);
};

int class4_6::chapter4_6_1(class4_6 class4_6_example)
{
	cout << "输入的结构体里的int型的参数值为:" << this->age << endl;
	cout << "输入的结构体里的函数的参数里的int型的参数值为:"
		<< class4_6_example.age << endl;
	return class4_6_example.age;
}
void chapter4_6(void)
{
	class class4_6 class4_6_example, class4_6_example1;
	class4_6_example.age = 10;
	class4_6_example1.age = 5;
	class4_6_example.chapter4_6_1(class4_6_example1);	
}
/*chapter4_7部分*/
const int increment = 100;
struct Stash
{
	int size;//每个空间的大小
	int quantity;//存储空间的数量
	int next;//下一个空空间
	//动态分配数组字节
	unsigned char *storage;
	//函数
	void initialize(int size);
	void cleanup();
	int add(const void *element);
	void *fetch(int index);
	int count();
	void inflate(int increase);
};
void Stash::initialize(int sz)
{
	size = sz;
	quantity = 0;
	storage = 0;
	next = 0;
}
int Stash::add(const void *element)
{
	if (next >= quantity)//是否有足够的空间,如果没有则增加increment个
		inflate(increment);
	//将元素拷贝到storage
	//起始在下一个空的空间，在此基础上增加一个元素的大小size，然后将next指针
	int startBytes = next*size;
	unsigned char *e = (unsigned char *)element;
	for (int i = 0; i < size; i++)
		storage[startBytes + i] = e[i];
	next++;
	return (next - 1);//返回新增添元素的索引号
}
void *Stash::fetch(int index)//查找
{
	//检查是否出界
	assert(0 <= index);
	if (index >= next)
		return 0;
	return &(storage[index*size]);
}
int Stash::count()
{
	return next;
}
void Stash::inflate(int increase)
{
	assert(increase > 0);
	int newQuantity = quantity + increase;
	int newBytes = newQuantity*size;
	int oldBytes = quantity*size;
	unsigned char *b = new unsigned char[newBytes];
	for (int i = 0; i < oldBytes; i++)//老数据转移到b
		b[i] = storage[i];
	delete []storage;//删除移动之后老数据
	storage = b;//新数据（扩展之后）赋值给storage
	quantity = newQuantity;//扩展之后的数量赋值给quantity
}
void Stash::cleanup()
{
	if (storage != 0)
	{
		cout << "freeing storage" << endl;
		delete []storage; 
	}
}
void chapter4_7(void)
{
	/*Stash存放double，存入25个double值，然后把它们显示到控制台*/
	int N = 25;
	double *p = new double[N];
	struct Stash struct4_6_example;
	struct4_6_example.initialize(sizeof(double));
	for (int i = 0; i < N; i++)
	{
		p[i] = i;
		struct4_6_example.add(&p[i]);
	}
	for (int i = 0; i < N; i++)
	{
		double * dp = (double *)(struct4_6_example.fetch(i));
	    cout << *dp << endl;
	}
}
/*用Stack重写练习7*/
struct Stack
{
	struct Link
	{
		void* data;
		Link* next;
		void initialize(void* dat, Link* nxt);
	}*head;
	void initialize();
	void push(void *dat);
	void* peek();
	void* pop();
	void cleanup();
};
void Stack::Link::initialize(void* dat, Link* nxt)
{
	data = dat;
	next = nxt;
}
void Stack::initialize() { head = 0; }
void Stack::push(void* dat)
{
	Link* newLink = new Link;
	newLink->initialize(dat, head);
	head = newLink;
}
void* Stack::peek()
{
	if (head == 0)
	{
		cout << "Stack empty" << endl;
		return 0;
	}
	else
		return head->data;
}
void* Stack::pop()
{
	if (head == 0) return 0;
	void* result = head->data;
	Link* oldHead = head;
	head = head->next;
	delete oldHead;
	return result;
}
void Stack::cleanup()
{
	if (head != 0)
	{
		cout << "Stack not empty" << endl;
	}
}
void chapter4_8(void)
{
	int N = 25;
	double *data = new double[N];
	struct Stack Stack4_8;
	Stack4_8.initialize();
	for (int i = 0; i < N; i++)
	{
		data[i] = i;
		Stack4_8.push((double *)&data[i]);
	}
	double* int_num;
	while ((int_num = (double*)Stack4_8.pop()) != 0)
		cout << *int_num << endl;
	delete int_num;
	Stack4_8.cleanup();

}
void chapter4_9(void)
{
/*没意思，会出错*/
}
void chapter4_11(void)
{
	/*测试一下预编译,将下面的内容复制到main函数下，才可以*/
#ifdef counter
	cout << "已经定义counter" << endl;
#endif
#ifndef counter
	cout << "没有定义counter" << endl;
#endif // !counter
}
/*chapter4_13从此处开始*/
struct Video
{
	struct video
	{
		bool state;//0代表该磁带已损坏，1表示完好
		char *name;//表示该磁带的名字
		int song_num;//该磁带的大小，存储多少个歌
		int index;
		video *NextVideo;
		video *PreviouVideo;
		int initialize(bool state, char *name, int song_num);
	}*head;

	int initialize(void);
	int add(struct video addvideo);
	int sub(char *name);
	int search(char *name,int index);
	int delete_all(void);
	int print(void);

};
int Video::initialize(void)
{
	head=0;
	return 0;
}
int Video::add(struct video addvideo)
{
	return 0;
}

void chapter4_13(void)
{
	/*创建抽象数据类型表示租赁店中的录像带
	尽可能多的包含录像带类型运作良好的所有
	数据和运算，包含录像带Video信息的printf()成员函数*/
	/*12-16有难度，未成功*/
}
void chapter4_17(void)
{
	int *p_int=new int;
	long *p_long = new long;
	char *p_char = new char [100];
	float *p_float = new float[100];
	cout << "p_int的地址为："<< (long)p_int << endl;
	cout << "p_long的地址为：" << (long)p_long << endl;
	cout << "p_char的地址为：" << (long)p_char << endl;
	cout << "p_float的地址为：" << (long)p_float << endl;
	delete [] p_int;
	delete [] p_long;
	delete [] p_char;
	delete [] p_float;
	cout << "p_int的地址为：" << (long)p_int << endl;
}
char * chapter4_18(char *p_char)
{
	//被注释的地方可以使用在main函数里
	/*
	static char *char_pointer = "my name is zhengzhida";
	static char *c_pointer, *c_pointer1;
	c_pointer = chapter4_18(char_pointer);
	c_pointer1 = chapter4_18(char_pointer);
	cout << c_pointer << "地址" << &c_pointer << endl;
	cout << c_pointer1 << "地址" << &c_pointer1 << endl;
	*/
	int char_num=strlen(p_char);
	char *pointer = new char[char_num];
	int i = 0;
	while (p_char[i] != '\0')
	{ 
		pointer[i] = p_char[i];
		i++;
	}		
	return pointer;
}
/*4_19*/
struct struct_4_19 
{
	struct struct_4_19_1 
	{
		float f_num;
		void printf_num(void);
	};
	int int_num;
	char char_num;
	void my_print(void);
};
void struct_4_19::my_print(void)
{
	cout << "整数为："<< int_num << endl;
}
void struct_4_19::struct_4_19_1::printf_num(void)
{
	cout << "整数为：" << f_num << endl;
}
void chapter4_19(void)
{
	struct struct_4_19 struct_example;
	
	struct_example.char_num = 'A';
	struct_example.int_num = 12;
	struct_example.my_print();
	struct_4_19::struct_4_19_1 struct_example1;
	struct_example1.f_num = 1.23;
	struct_example1.printf_num();
}
struct chapter4_20_1
{
	int  int_num;
	char *char_pointer;
	float f_data;

}chapter4_20_1_example;
struct chapter4_20_2
{
	int  int_num;
	char *char_pointer;
	float f_data;
	void MyFunction(void);

}chapter4_20_2_example;
void chapter4_20_2::MyFunction(void)
{
	cout << "chapter4_20_2的int为："<< int_num << endl;

}
struct chapter4_20_3 {}chapter4_20_3_example;
void chapter4_20(void)
{
	/*打印结构体的长度，包含数据成员的结构、
	包含数据成员函数成员、没有成员的结构*/
	int size1=sizeof(chapter4_20_1_example);
	int size2 = sizeof(chapter4_20_2_example);
	int size3 = sizeof(chapter4_20_3_example);
	cout << "数据成员的结构长度为："<< size1 << endl;
	cout << "包含数据成员函数成员的结构体长度：" << size2 << endl;
	cout << "无数据成员的结构体长度：" << size3 << endl;
}
/*21到25未做*/
void chapter4_24(void)
{

}

