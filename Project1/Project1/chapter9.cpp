#include "chapter9.h"
#include "require.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <string.h>
using namespace std;

void chapter9_1(float num)
{
	/*дһ��ʹ�ñ��¿�ͷ���ֵ�F()��ĳ���֤����������
	��������˵������������ȷ����չ���޸Ĳ�ʹ����ȷ����*/
	
	float i = F(num);
	cout << "F(x)��ֵΪ��" << i << endl;
}
void chapter9_2(int num)
{
	/*дһ��ʹ�ñ��¿�ͷ���ֵ�FLOOR()��ĳ���˵������ʲô����²�����������*/
	int i = FLOOR(num & 0x0f, 0x07);
	if(i)
		cout <<"FLOOR(num & 0x0f, 0x07)" <<i <<endl;
}
void chapter9_3(void)
{
	/*�޸�MacroSideEffects.cpp��ʹ��BAND()�ܹ���������*/
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
	/*��������������ͬ�ĺ���f1()��f2(),����f1()����������
	f2()�Ƿ�����������ʹ��<ctime>�еı�׼C�⺯��clock()���
	�����Ŀ�ʼ��ͽ����㣬��һ����*/
	clock_t time1 = chapter9_4_1();
	clock_t time2 = chapter9_4_2();
	cout << "����1���ѵ�ʱ��Ϊ��" << time1 << endl;
	cout << "����2���ѵ�ʱ��Ϊ��" << time2 << endl;
}
void chapter9_5(void)
{
	/*����ϰ4�еĴ���ĸ����Ժʹ�С�����ԣ�
	�������ͷ���������һ��ƽ��*/
	/*ʵ��Ľ��Ϊinline���ѵ�ʱ��Ƚϸߣ��������෴*/
}
void chapter9_6(void)
{

}

/*chapter9_7*/
/*����һ���࣬����һ���������顣����һ���������캯��
��һ��������Ա����print().�������캯��ʹ�ñ�׼��C�⺯��
memset()��ʼ����Ӧ�ڹ��캯���Ĳ�����Ĭ��ʱΪ�㣩������
��������print()��ӡ���������Ԫ��ֵ*/
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
	 /*memse()���ڶ��ֽڵ�����ֻ�ܳ�ʼ��Ϊ0��
	 ��Ϊ�ǰ����Խڵ�˳������ʼ����*/
}
/*9-7*/
/*�����µ�����NestFriend.cpp�е����г�Ա�����ĳ�����������
��ʹ����Ϊ��in situ����������涨�壬����inline��־������������Ҳ���ڹ��캯������initalize()����*/
void chapter9_8(void)
{

}
void chapter9_9(void)
{

}
/*9_10*/
/*����һ����ΪHue��enum��������red��blue��yellow������һ��color��
���������һ��Hue���͵����ݳ�Ա���乹�캯���ò�������������ݳ�Ա
��ֵ�����ӷ��ʺ���������ȡ������Hue������ݳ�Ա��ֵ�����к���
ʹ����������*/
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
		cout << "ö��ֵ������Χ" << endl;
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
	/*ʹ�÷��������޸����ķ����޸���ϰ10�еĳ���*/
	/*��ϰ10�о�����������ʽ*/
}
/*9_12*/
/*�޸ĳ���Cpptime.cpp��ʹ���ӳ���Ŀ�ʼ����ʱ��ʼ��ʱ��ֱ���û�
��ȷ��(Enter)��س�(Return)*/
void chapter9_12(void)
{
	clock_t start = clock();
	clock_t end;
	cout <<"�����Ҫֹͣ��ʱ�Ͱ���enter��" << endl;
	char c = cin.get();
	if (c == 10 || c == 13)
		end= clock();
	cout <<"���ѵ�ʱ��Ϊ��" << end- start << endl;
}
/*����һ�������������Ա�������ڵ�һ����Ա����
���õڶ�����Ա����������Ҫ��ǰ����*/
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
	cout <<"class_chap9_13��iΪ��" << fun2()<<endl;
	i = m+1;
	cout << "class_chap9_13��iΪ��" << fun2() << endl;
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
/*����һ����A���������Լ���������Ĭ�ϵĹ��캯����
�ٴ���һ����B����A���һ��������ΪB�ĳ�Ա��B��
���캯��Ҳ�������ģ�����һ��B��Ķ�������*/
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
	/*����ǰ����ϰ�����д��������Ķ���ʹ��Time
	�������������������캯�����������캯��֮���
	ʱ����*/
}
/*chapter9_16*/
/*дһ������һ��string�����в����ĳ���дһ��forѭ��
��ѭ��ÿִ��һ����ȥ��string��һ����ĸ��ʹ��ÿ�µ�DEBUG()
���ӡstring*/
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
/*��ȷ���޸�TRACR()�꣬ʹ����Ϊ����ָ�����ض��ĺ꣬
��ʹ���ܹ���ȷ������*/
void chapter9_17(string str)
{
	int sz = str.size();
	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz - i; j++)
			TRACE(str[j]);
	}		
}
/*�޸�FIELD()�꣬ʹ������һ������(index)�ţ�����һ���࣬���ĳ�Ա��һЩ
��FIELD()��ĵ�����ɣ�����һ����Ա������������ʹ�������Ų鿴��дһ��
������main()���������*/
void chapter9_18(string str)
{
}
void chapter9_19(string str)
{
}
/*9-20*/
/*дһ����������������������һ��������һ���ļ���
ʹ��require.h��ȷ��������Ŀ��ȷ������������5��10֮��
�ļ��ܹ��ɹ��ش�*/
int chapter9_20(int num,const string & string_p)
{
	if (num > 5 && num < 10)
		;
	else
	{ 
		cout << "�����Ĳ�������5��10֮��" << endl;
		return 0;
	}	
	ifstream open_read(string_p);
	assure(open_read,string_p);
	return 1;
}
/*9_21*/
/*дһ��IFOPEN()��ĳ�����������һ���ļ�����Ϊһ��
��������ע��ifstream����Ĵ����Լ�����������*/
void chapter9_21(const string string_p)
{
	//IFOPEN(string_p);
}
void chapter9_22(const string string_p)
{

}