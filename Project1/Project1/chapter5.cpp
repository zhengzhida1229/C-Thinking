#include <iostream>
#include <string>
#include "chapter5.h"
using namespace std;
/*chapter5_1 ��ʼ��*/
typedef struct 
{
public:
	float score;
private:
	char *name;
protected:
	int age;
}chapter5_1_struct;
void chapter5_1(void)
{
	chapter5_1_struct struct_example;
	struct_example.score = 0;
	/*��ʾ�޷�����private��Ա*/
	//struct_example.name="My name is";
}
/*chapter5_2��ʼ*/
typedef struct 
{	
	/*��һ�����*/
	string a;
	string b;
	string c;
		
}Lib;
/*  //���������
typedef struct
{
	

private:
	string a;
	string b;
	string c;
public:
	void seta(string a);
	string geta(void);
	void setb(string b);
	string getb(void);
	void setc(string c);
	string getc(void);

}Libc;
string Libc::geta(void)
{
	return a;

}
string Libc::getb(void)
{
	return b;

}
string Libc::getc(void)
{
	return c;

}
void Libc::seta(string a_str)
{
	a = a_str;
}
void Libc::setb(string b_str)
{
	b = b_str;

}
void Libc::setc(string c_str)
{
	c = c_str;

}
*/


  //���������
typedef struct
{


private:
string s[3];

public:
void seta(string a);
string geta(void);
void setb(string b);
string getb(void);
void setc(string c);
string getc(void);

}Libc;
string Libc::geta(void)
{
return s[0];

}
string Libc::getb(void)
{
return s[1];

}
string Libc::getc(void)
{
return s[2];

}
void Libc::seta(string a_str)
{
s[0] = a_str;
}
void Libc::setb(string b_str)
{
s[1] = b_str;

}
void Libc::setc(string c_str)
{
s[2] = c_str;

}

void chapter5_2(void)
{
	/*��һ�����*/
	/*
	Lib x;
	x.a = "My name is ";
	x.b= "zheng";
	x.c = "zhida";
	cout << x.a << x.b << x.c << endl;
	*/
	/*���������*//*���������*/
	Libc xc;
	xc.seta("my name is");
	xc.setb("zheng");
	xc.setc("zhida");
	string str1 = xc.geta();
	string str2 = xc.getb();
	string str3 = xc.getc();
	cout << str1 << str2 << str3 << endl;
}

int getinfo5_3(struct struct5_3 structExample)
{
	structExample.age= 25;
	structExample.name = "zhengzhida";
	structExample.score = 100.0;
	cout << "zhengzhida's score is " << structExample.score <<endl;
	return structExample.score;
}
/*5-4�Ӵ˴���ʼ*/
void fun2(struct struct1 *example2)
{
	
	cout << example2->name<< endl;

}
void fun1(struct struct2 *example1)
{
	cout << example1->score << endl;
}
/*5-5*/
/*����3���࣬��һ�������private���ݣ�
�����ڶ�����͵�������ĳ�Ա��Ա������������Ա*/
void stru5_5_3::fun_stru5_5_3(struct stru5_5_3 example, struct stru5_5_1 example1)
{
	example.familymember = 4;
	example.school = "������ѧ";
	cout << "ѧУ��" << example.school << "����:" << example1.name << endl;
	cout<<"��ͥ��Ա��" << example.familymember << endl;

};
void fun_stru5_5_3(struct stru5_5_3 example, struct stru5_5_1 example1)
{
	example1.age = 25;
	example1.wight = 66;
	cout << "ѧУ��" << example.school << "����:" << example1.name << endl;
	cout << "���䣺" << example1.age <<"����:"<< example1.wight << endl;

}
/*main�������*/
/*struct stru5_5_1 example1;
struct stru5_5_2 example2;
struct stru5_5_3 example3;
example1.name = "zhengzhida";
example2.i = 1;
example3.school = "������ѧ";
example3.fun_stru5_5_3(example3, example1);
fun_stru5_5_3(example3, example1);*/ 

/*5-6*/
/*����һ��Hen�࣬������Ƕ��Nest�࣬��Nest����
  ��һ��Egg���Ա��ÿһ���඼��һ����Ա����display()
  �ں���main()�д���ÿһ�����ʵ��������ÿһ�����display����*/
void Hen::display(void)
{
	cout << "HenNum" << HenNum << endl;
	cout << "HenNmae" << HenNmae << endl;
	//cout << "class Nest" << Nest << endl;
}
void  Nest::display(void)
{
	cout << "NestNum" << NestNum << endl;
	cout << "NestName" << NestName << endl;
}
void  Nest::Egg::display(void)
{
	cout <<"EggName" << EggName <<endl;
	cout << "EggNum" << EggName << endl;
}
/*5_8*/
struct struct5_8
{
private:
	int age;
public:
	char *name;
	void showMap(void);
protected:
	float wight;
};
void struct5_8::showMap(void)
{
	age = 25;
	wight = 66;
	cout << age<<" " << &age << endl;
	cout << name<<" " << &name << endl;
	cout << wight<<" " << &wight << endl;
}

void chapter5_8(void)
{
	struct struct5_8 example;
	example.name = "zhengzhida";
	example.showMap();
}

