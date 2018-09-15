#pragma once
#ifndef chapter5_H
#define chapter5_H
#include <iostream>
#include <string>

using namespace std;
void chapter5_1(void);
void chapter5_2(void);
int getinfo5_3(struct struct5_3 structExample);
struct struct5_3;
/*5_3此处开始* /
/*创建一个类和一个全局friend函数
来处理类的private数据*/

struct struct5_3
{
	long first;
private:
	int age;
	float score;
	char *name;
	friend int getinfo5_3(struct struct5_3 structExample);

};
/*5-4*/
struct struct2;
struct struct1
{
	char *name;
private:
	int age;
	friend void fun1(struct struct2 *example1);

};
struct struct2
{
	float score;
private:
	float wight;
	friend void fun2(struct struct1 *example2);
};
/*5-5*/
struct stru5_5_1;
struct stru5_5_2;
struct stru5_5_3;
struct stru5_5_1
{
public:
	char *name;
private:
	int age;
	float wight;
	friend struct stru5_5_2;
	friend void fun_stru5_5_3(struct stru5_5_3 example, struct stru5_5_1 example1);
};
struct stru5_5_2
{
	int i;
	char m;

};
struct stru5_5_3
{
public:
	char *school;
	void fun_stru5_5_3(struct stru5_5_3 example, struct stru5_5_1 example1);
private:
	int familymember;
	
};
/*5-6*/
class Nest
{
	class Egg 
	{
	private:
		int EggNum;
	public:
		char *EggName;
		void display(void);
	};
private:
	int NestNum;
public:
	char *NestName;
	void display(void);
};
class Hen
{
friend	class Nest;
private:
	int HenNum;
public:
	char *HenNmae;
	void display(void);
};
void chapter5_8(void);
#endif//!chapter5_H
