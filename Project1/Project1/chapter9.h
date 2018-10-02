#pragma once
#include <iostream>
#include <string.h>
#include <ctime>
using namespace std;
# ifndef chapter9_H
# define chapter9_H

#define F(x)  (x*(x+1))
void chapter9_1(float num);
#define FLOOR(x,y)  x>=y?0:1
void chapter9_2(int num);
#define BAND(x) (((x)>5&&(x)<10) ? (x):0)
void chapter9_3(void);
inline clock_t chapter9_4_1(void);
clock_t chapter9_4_2(void);
void chapter9_4(void);
void chapter9_5(void);
void chapter9_6(void);//
void chapter9_7(void);
void chapter9_8(void);//
void chapter9_9(void);//
void chapter9_10(void);
void chapter9_11(void);
void chapter9_12(void);
void chapter9_13(void);
void chapter9_14(void);
void chapter9_15(void);//
#define DEBUG(x) cout<<#x"="<<x<<endl;
void chapter9_16(string str);
#define TRACE(s)  cout<<#s"="<<s<<endl;
void chapter9_17(string str);
void chapter9_18(string str);//
void chapter9_19(string str);//
int chapter9_20(int num, const string & string_p);
#define IFOPEN(s) ifstream(s);
void chapter9_21(const string string_p);//Î´³É¹¦
void chapter9_22(const string string_p);//
#endif//!chapter9_H
