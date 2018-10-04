#pragma once
#include <iostream>
#include <string.h>
#include <ctime>
#include <stdio.h>
using namespace std;
# ifndef chapter10_H
# define chapter10_H

int chapter10_1_1(int int_num = 0);
void chapter10_1_2(void);
int chapter10_2_1(bool true_false);
void chapter10_2_2(int times);
//void chapter10_3(void);
void chapter10_4(void);
void chapter10_5(void);//
void chapter10_6(void);//
void chapter10_7(void);
void chapter10_8(void);//
void chapter10_9(void);//
void chapter10_10(void);
void chapter10_11(void);
void chapter10_12(void);//
void chapter10_13(void);//
void chapter10_14(void);//不太好做
void chapter10_15(void);
void chapter10_16_1(void);
void chapter10_16_2(void);
void chapter10_17_1(int int_num, float flo_num);
void chapter10_17_2(int int_num, float flo_num);
void chapter10_19(void);
void chapter10_20_1(void);
void chapter10_20_2(void);
void chapter10_21(void);


/*相关类的定义*/
/*chapter10_4*/
class Monitor;
class class_chapter10_7
{
public:
	int i;
	inline class_chapter10_7(void);
};
/*10_10中使用的static的数据*/
static int  global_static;
/*10_11的类*/
//class class_chapter10_11;
class class_chapter10_11
{
public:
	int int_num;
	void set_value(int num1);
	void print(void);
	class_chapter10_11(int num2);
};
/*chapter10_14*/
class Volatile {
	volatile int x;
public:
	void mod1(int x) {
		this->x = x;
	}
	void mod2(int x) volatile {
		this->x = x;
	}
	volatile int isr(void) {
		return this->x;
	}
};
#endif//!chapter10_H

