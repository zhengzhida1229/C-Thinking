#include <iostream>
#include <cstdlib>
#include <string>
/*29题之后基本没做，同时这些也是非常重要的*/
using namespace std;
void chapter3_4(void)
{
	char c='c';
	while (c!='q')
	{
		cout << "MAIN MENU:" << endl;
		cout << "l:left,r:right,q:quit ->";
		cin >> c;
		switch (c)
		{
			case 'q': {break; }
			case 'l':
				{
					cout << "LEFT MENU:" << endl;
					cout << "select a or b:";
					cin >> c;
					switch (c)
					{
					case 'a': {cout << "you chose 'a'" << endl; continue; }
					case 'b': {cout << "you chose 'b'" << endl; continue; }
					default: {cout << "you didn't chose a or b" << endl; continue; }
					}
					break;
				}
			case 'r':
			{
				cout << "RIGHT MENU:" << endl;
				cout << "select c or d:";
				cin >> c;
				switch (c)
				{
				case 'c': {cout << "you chose 'c'" << endl; continue; }
				case 'd': {cout << "you chose 'd'" << endl; continue; }
				default: {cout << "you didn't chose c or d" << endl; continue; }
				}
				break;
			}
			default: {cout << "you must type l,r or q" << endl; break; }
		}

	}
	cout << "quit menu ..." << endl;
}
float* chapter3_5(float x, float y, float z)
{
	float result[2];
	result[0] = x + y - 2 / 2 + z;
	result[1]= x +( y - 2) / (2 + z);
	cout << "first result is " << result[0] << " second result is " << result[1] << endl;
	return result;
}
void chapter3_6(void)
{
	cout << "没有多大的意思，所以没有做" << endl;
}
void chapter3_7_1(string *str)
{
	cout << *str << endl;
	*str = "I'm the best";
	cout << *str << endl;
		
}
void chapter3_7_2(string &str)
{
	cout << str << endl;
	str = "I'm the best1";
	cout << str << endl;
}
void chapter3_8(void)
{

}
void chapter3_9_1(void)
{
	//这个程序是C++Thinking 中的Static.cpp的原本内容
	static int i = 0;
	cout << "i" << ++i << endl;
}
void chapter3_9_2(void)
{
	//这个程序是C++Thinking 中的Static.cpp的原本内容中去掉“static”
	int i = 0;
	cout << "i" << ++i << endl;
	/*两个结果的不同，源于static 在跳出函数的时候仍然保持不变，
	再次进入函数的时候不会再一次的初始化；
	而去掉static则函数每运行一次就会重新初始化*/
}
void chapter3_10_1(void)
{
	/*extern 或static在哪一个先声明，哪一个起作用，后者与前者冲突的话会编译不通过*/
	static int fs;
}
//extern int fs;
void chapter3_10_2(void)
{
	//fs = 100;
}
void chapter3_11(void)
{
	/*修改Boolean.cpp，用double值代替int值*/
	//在比较的过程中最好使用int类型的数据，
	//因为一般情况下double类型的数据后面有很多的小数难以实现相等。
	double i, j;
	cout << "enter an double:";
	cin >> i;
	cout << "enter another double:";
	cin >> j;
	cout << "i>j is " << (i > j) << endl;
	cout << "i<j is " << (i < j) << endl;
	cout << "i>=j is " << (i >= j) << endl;
	cout << "i<=j is " << (i <= j) << endl;
	cout << "i==j is " << (i == j) << endl;
	cout << "i!=j is " << (i != j) << endl;
	cout << "i&&j is " << (i && j) << endl;
	cout << "i||j is " << (i || j) << endl;
	cout << "(i<10)&&(j<10) is " << ((i<10) && (j<10)) << endl;
}
void chapter3_12_1(const unsigned char val)
{
	/*输出一个字符的2进制码*/
	for (int i = 7; i >= 0; i--)
		if (val&(1 << i))
			cout << "1";
		else
			cout << "0";
	cout << endl;
}
void chapter3_12(void)
{
	/*将Bitwise.cpp 中的类型转换采用显式的方式*/
	unsigned int getval;
	unsigned char a,b;
	cout << "Enter a number between 0 and 255 :";
	cin >> getval; a = unsigned char(getval);//显式的方式
	cout << "a in binary:"; chapter3_12_1(a);
	cout << "Enter a number between 0 and 255 :";
	cin >> getval; b= unsigned char(getval);
	cout << "b in binary:"; chapter3_12_1(b);
	cout << "a|b="; chapter3_12_1(a|b);
	cout << "a&b="; chapter3_12_1(a & b);
	cout << "a^b="; chapter3_12_1(a ^ b);
	cout << "~a"; chapter3_12_1(~a);
	cout << "~b"; chapter3_12_1(~b);
	unsigned char c = 0x5A;
	cout << "c in binary:"; chapter3_12_1(c);
	a |= c;
	cout << "a |= c;a="; chapter3_12_1(a);
	b &= c;
	cout << "b &= c;b="; chapter3_12_1(b);
	b ^= a;
	cout << "b ^= a;b="; chapter3_12_1(b);
}
void chapter3_14(void)
{
	/*修改Ifthen.cpp程序，使用三重if-else运算符（？：）*/
	/*a=--b?b:(b=-99)*/
	//意思为如果b自减之后为0，则b赋值为-99，如果为1则把b赋值给a;
	int i,a;
	cout << "type a number and 'Enter'" << endl;
	cin >> i;
	a = (i > 5) ? 0 : (i < 5) ? 1 : 2;
	/*使用？：运算符，当i>5成立的时候a为0，
	否则判断i<5是否成立，如果成立则为1否则为2*/
	switch(a)
	{
		case 0: {cout << "It's grater than 5" << endl; break; }
		case 1: {cout << "It's less than 5" << endl; break; }
		case 2: {cout << "It's equal to 5" << endl; break; }
	}

}
/*3_14*/
void chapter3_15(void)
{
	string str1_temp;
	typedef struct
	{
		string str1;
		string str2;
		int num;
	}struct3_14;
	struct3_14 struct_example1, *struct_example2;
	struct_example1.num = 110;
	struct_example1.str1 = "zhengzhida";
	struct_example1.str2 = "lihaile";
	cout << struct_example1.str1 << struct_example1.str2 << struct_example1.num << endl;
	struct_example2 = &struct_example1;
	struct_example2->str1 = "zhengzhida1";
	struct_example2->str2 = "lihaile1";
	struct_example2->num = 111;
	cout << struct_example1.str1 << struct_example1.str2 << struct_example1.num << endl;
	cout << struct_example2->str1 << struct_example2->str2 << struct_example2->num << endl;
}
void chapter3_16(void)
{
	/*编制一个使用枚举类型的程序
	创建一个enum类型的变量
	用for循环输出与颜色名对应的数字*/
	string str;
	enum color {greeen =1,red =2,blue, Orange	};
	for (int i = greeen; i <  (Orange+1); i++)
	{
		cout << i << endl;

	}
}
void chapter3_17(void)
{
	union packed {
		char my_char;
		char *mchar;
		int int_num;
		double double_num;
		float float_num;
		short i;
	};
	packed myunion;
	myunion.int_num = 100;
	myunion.double_num = 100.012;
	cout << sizeof(myunion) << endl;
}
void chapter3_18( int int_arry[], int int_arry1[])
{
	/*这种做法是极其不好的方式，因为指针或数组
	的最后一个如果不是字符串的结束符的时候，不知道指针会指向何处*/
	int i=0, intsize;
	int num_int_arry, num_int_arry1;
	intsize = sizeof(i);
	num_int_arry = sizeof(int_arry) / intsize;
	num_int_arry1 = sizeof(int_arry1) / intsize;
	int *p= int_arry;
	char a = 'a';
	int *p1 = int_arry1;
	cout << "下面是原有数据输出" << endl;
	cout << "第一个数据输出" << endl;
	while (p[i] != '\0')
	{
		cout << p[i];
		i++;
	}
	cout << endl;
	cout << "第二个数据输出" << endl;
	i = 0;
	while (p1[i] != '\0')
	{
		cout << p1[i];
		i++;
	}
	cout << endl;
	cout << "下面是按照题目进行处理的输出" << endl;
	i = 0;
	cout << "这是第一个数组的输出" << endl;
	while (p[i] != '\0')
	{
		cout << p[i];
		i++;
	}
	cout << endl;
	cout << "这是第二个数组的输出" << endl;
	while (p1[i] != '\0')
	{
		cout << p1[i];
		i++;
	}
	cout << endl;
	//cout <<p[1] << endl;;
}
void chapter3_18_1(int int_arry[], int int_arry1[])
{
	int *p = int_arry;
	int *p1 = int_arry1;
	cout << p[1] << endl;
}
void chapter3_19( int chose )
{	
	/*在C++中，函数的形参没有的情况下，意思为可以为任意类型，任意数目*/
	/*修改ArrayAddresses.cpp程序，使之能够处理
	char,long,int,float,double类型的数据*/
	char char_size;
	long long_size;
	int int_size,fz,cz,lz,dz;
	float float_size;
	double double_size;
	/*确定每种类型的数据的大小*/
	int_size = sizeof(int_size);
	fz = sizeof(float_size);
	cz= sizeof(char_size);
	dz= sizeof(double_size);
	lz= sizeof(long_size);
	/*定义各种类型的数组*/
	char ch[] = { "hello" };
	long lo[] = { 1,2,3,4,5,6 };
	int in[] = { 1,2,3,4,5,6 };
	float fl[] = { 3.0,4.0,5.2,6.0 };
	double dou[]= { 3.0,4.0,5.2,6.0 };
	int size;
	switch (chose)
	{
		/*char类型的处理*/
	case 1:
		{
			cout << "sizeof(char)=" << cz << endl;
			size = sizeof(ch) / cz;
			for (int i = 0; i < size; i++)
				cout << "&ch[" << i << "]=" << (long)&ch[i] << endl;
			break;
		}
		/*long类型的处理*/
	case 2:
	{
		cout << "sizeof(long)=" << lz << endl;
		size = sizeof(lo) / lz;
		for (int i = 0; i < size; i++)
			cout << "&lo[" << i << "]=" << (long)&lo[i] << endl;
		break;
	}
	/*int类型的处理*/
	case 3:
	{
		cout << "sizeof(int)=" << int_size << endl;
		size = sizeof(in) / int_size;
		for (int i = 0; i < size; i++)
			cout << "&in[" << i << "]=" << (long)&in[i] << endl;
		break;
	}
	/*float类型的处理*/
	case 4:
	{
		cout << "sizeof(float)=" << fz << endl;
		size = sizeof(fl) / fz;
		for (int i = 0; i < size; i++)
			cout << "&fl[" << i << "]=" << (long)&fl[i] << endl;
		break;
	}
	/*double类型的处理*/
	case 5:
	{
		cout << "sizeof(double)=" << dz << endl;
		size = sizeof(dou) / dz;
		for (int i = 0; i < size; i++)
			cout << "&dou[" << i << "]=" << (long)&dou[i] << endl;
		break;
	}
	default:cout << "请输入1到5之间的整数" << endl;
	}
	
}
void chapter3_20(void)
{
	/*运用ArrayAddresses.cpp程序的技术，
	输出StructArray.cpp程序中定义的struct
	的大小以及数组元素的地址*/
	typedef struct 
	{
		int i, j, k;
	}ThreeDpoint;
	ThreeDpoint p1;
	p1.i = 0; p1.j = 1; p1.k = 2;
	cout << "p1.i=" << p1.i << endl;
	cout << "p1.j=" << p1.j << endl;
	cout << "p1.k=" << p1.k << endl;
	cout << "struct的大小为" << sizeof(p1) << endl;
}
void chapter3_21(void)
{
	/*创建一个string对象数组且对
	每一个元素赋一个字符串，用for循环输出该数组*/
	string str[3];
	str[0] = "zheng";
	str[1] = "zhi";
	str[2] = "da";
	for (int i = 0; i < 3; i++)
		cout << str[i] << endl;
}
void chapter3_22(int argc,char *argv[])
{
	/*在ArgsToInts.cpp的基础上，
	编制两个程序，他们各自使用atol()和atof()函数*/
	/*将ASCII转化为long*/
	cout << "将ASCII转化为long" << endl;
	for (int i = 1; i < argc; i++)
		cout << atol(argv[i]) << endl;
	/*将ASCII转化为int*/
	cout << "将ASCII转化为int" << endl;
	for (int i = 1; i < argc; i++)
		cout << atoi(argv[i]) << endl;
	/*将ASCII转化为double*/
	cout << "将ASCII转化为double" << endl;
	for (int i = 1; i < argc; i++)
		cout << atof(argv[i]) << endl;
	cout << argv[1] << endl;
}
void chapter3_23(void)
{
	/*PoniterIncrement2.cpp,其中使用union代替struct*/
	union packed 
	{
		char c;
		short s;
		int i;
		long l;
		float f;
		double d;
		long double ld;
	};
	packed p[10];
	packed *pp = p;
	cout << "sizeof(packed)="
		<< sizeof(packed) << endl;
	cout << "pp=" << (long)pp << endl;
	pp++;
	cout<<"pp="<< (long)pp << endl;
}
void chapter3_24(void)
{
	/*修改PointerArithmetic.cpp其中使用long和long double*/
	#define P(EX) cout<<#EX<<":"<<EX<<endl;
	long double a[10];
	for (int i = 0; i < 10; i++)
		a[i] = i;
	long double *ip = a;
	P(*ip);
	P(*++ip);
	P(*(ip+5));
	long double *ip2 = ip+5;
	P(*ip2);
	P(*(ip2-4));
	P(*--ip2);
	P(ip2-ip);
}
void chapter3_25(float fl)
{
	/*printBinary*/
	float fd =fl;
	unsigned char lint = (unsigned char)(&fd);
	unsigned char *cha_pointer = &lint;
	for (int i = 0; i < sizeof(float); i++)
	{
		for (int j = 0; j < 8; j++)
			if ((cha_pointer[i] << j) & 0x80)
				cout << "1";
			else
				cout << "0";
		cout << endl;
	}
}
void chapter3_26(void *pointer,int byte_num,unsigned short int init_value)
{
/*没能成功*/
}
void chapter3_27(void )
{
	/*利用const_cast把每个元素转化为non-cast和non-volatile，然后对每个元素赋值*/
	const double cd[] = { 0,0,0 };
	volatile double vd[] = { 1,1 };
	int num1 = sizeof(cd) / sizeof(double), num2 = sizeof(vd) / sizeof(double);
	double *newdou=	const_cast<double*>(cd);
	double *newdou_vd = const_cast<double*>(vd);
	cout << "下面是第一组" << endl;
	for (int i = 0; i < num1; i++)
	{
		newdou[i] = i;
		cout << cd[i] << endl;
	}
	cout << "下面是第二组" << endl;
	for (int i = 0; i < num2; i++)
	{
		newdou_vd[i] = i;
		cout << vd[i] << endl;
	}
}
void chapter3_28(double *dou_pointer,int size)
{
	for (int i = 0; i < size;i++)
		 dou_pointer[i]=0;
	unsigned char *char_pointer=reinterpret_cast<unsigned char *>(dou_pointer);
	int all_step = size*sizeof(double);
	for (int i = 0; i < all_step; i++)
	{
		*(char_pointer + i) = 1;		

	}
}
void chapter3_30(void)
{
	/*创建makefile文件，可以编译YourPets1.cpp和YourPets2.cpp程序
	（用你特定的编译器）以及执行这两个程序作为默认的目标，确保使用后缀规则*/
	//暂时不做
}
int chapter3_32_1(double d_num)
{
	cout << "输出的数值为："<< d_num << endl;
	int num = d_num - 1;
	return num;
}
void chapter3_32(void)
{
	/*创建和初始化一个指向该函数的指针，通过指针调用这个函数*/
	double d_num = 2.5;
	int(*fun_pointer)(double d_num);
	fun_pointer = chapter3_32_1;
	int x=fun_pointer(3.5);
	cout << "函数返回为：" << x	<<"," <<fun_pointer(4.5) <<endl;
}


