#include <iostream>
#include <cstdlib>
#include <string>
/*29��֮�����û����ͬʱ��ЩҲ�Ƿǳ���Ҫ��*/
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
	cout << "û�ж�����˼������û����" << endl;
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
	//���������C++Thinking �е�Static.cpp��ԭ������
	static int i = 0;
	cout << "i" << ++i << endl;
}
void chapter3_9_2(void)
{
	//���������C++Thinking �е�Static.cpp��ԭ��������ȥ����static��
	int i = 0;
	cout << "i" << ++i << endl;
	/*��������Ĳ�ͬ��Դ��static ������������ʱ����Ȼ���ֲ��䣬
	�ٴν��뺯����ʱ�򲻻���һ�εĳ�ʼ����
	��ȥ��static����ÿ����һ�ξͻ����³�ʼ��*/
}
void chapter3_10_1(void)
{
	/*extern ��static����һ������������һ�������ã�������ǰ�߳�ͻ�Ļ�����벻ͨ��*/
	static int fs;
}
//extern int fs;
void chapter3_10_2(void)
{
	//fs = 100;
}
void chapter3_11(void)
{
	/*�޸�Boolean.cpp����doubleֵ����intֵ*/
	//�ڱȽϵĹ��������ʹ��int���͵����ݣ�
	//��Ϊһ�������double���͵����ݺ����кܶ��С������ʵ����ȡ�
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
	/*���һ���ַ���2������*/
	for (int i = 7; i >= 0; i--)
		if (val&(1 << i))
			cout << "1";
		else
			cout << "0";
	cout << endl;
}
void chapter3_12(void)
{
	/*��Bitwise.cpp �е�����ת��������ʽ�ķ�ʽ*/
	unsigned int getval;
	unsigned char a,b;
	cout << "Enter a number between 0 and 255 :";
	cin >> getval; a = unsigned char(getval);//��ʽ�ķ�ʽ
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
	/*�޸�Ifthen.cpp����ʹ������if-else�������������*/
	/*a=--b?b:(b=-99)*/
	//��˼Ϊ���b�Լ�֮��Ϊ0����b��ֵΪ-99�����Ϊ1���b��ֵ��a;
	int i,a;
	cout << "type a number and 'Enter'" << endl;
	cin >> i;
	a = (i > 5) ? 0 : (i < 5) ? 1 : 2;
	/*ʹ�ã������������i>5������ʱ��aΪ0��
	�����ж�i<5�Ƿ���������������Ϊ1����Ϊ2*/
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
	/*����һ��ʹ��ö�����͵ĳ���
	����һ��enum���͵ı���
	��forѭ���������ɫ����Ӧ������*/
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
	/*���������Ǽ��䲻�õķ�ʽ����Ϊָ�������
	�����һ����������ַ����Ľ�������ʱ�򣬲�֪��ָ���ָ��δ�*/
	int i=0, intsize;
	int num_int_arry, num_int_arry1;
	intsize = sizeof(i);
	num_int_arry = sizeof(int_arry) / intsize;
	num_int_arry1 = sizeof(int_arry1) / intsize;
	int *p= int_arry;
	char a = 'a';
	int *p1 = int_arry1;
	cout << "������ԭ���������" << endl;
	cout << "��һ���������" << endl;
	while (p[i] != '\0')
	{
		cout << p[i];
		i++;
	}
	cout << endl;
	cout << "�ڶ����������" << endl;
	i = 0;
	while (p1[i] != '\0')
	{
		cout << p1[i];
		i++;
	}
	cout << endl;
	cout << "�����ǰ�����Ŀ���д�������" << endl;
	i = 0;
	cout << "���ǵ�һ����������" << endl;
	while (p[i] != '\0')
	{
		cout << p[i];
		i++;
	}
	cout << endl;
	cout << "���ǵڶ�����������" << endl;
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
	/*��C++�У��������β�û�е�����£���˼Ϊ����Ϊ�������ͣ�������Ŀ*/
	/*�޸�ArrayAddresses.cpp����ʹ֮�ܹ�����
	char,long,int,float,double���͵�����*/
	char char_size;
	long long_size;
	int int_size,fz,cz,lz,dz;
	float float_size;
	double double_size;
	/*ȷ��ÿ�����͵����ݵĴ�С*/
	int_size = sizeof(int_size);
	fz = sizeof(float_size);
	cz= sizeof(char_size);
	dz= sizeof(double_size);
	lz= sizeof(long_size);
	/*����������͵�����*/
	char ch[] = { "hello" };
	long lo[] = { 1,2,3,4,5,6 };
	int in[] = { 1,2,3,4,5,6 };
	float fl[] = { 3.0,4.0,5.2,6.0 };
	double dou[]= { 3.0,4.0,5.2,6.0 };
	int size;
	switch (chose)
	{
		/*char���͵Ĵ���*/
	case 1:
		{
			cout << "sizeof(char)=" << cz << endl;
			size = sizeof(ch) / cz;
			for (int i = 0; i < size; i++)
				cout << "&ch[" << i << "]=" << (long)&ch[i] << endl;
			break;
		}
		/*long���͵Ĵ���*/
	case 2:
	{
		cout << "sizeof(long)=" << lz << endl;
		size = sizeof(lo) / lz;
		for (int i = 0; i < size; i++)
			cout << "&lo[" << i << "]=" << (long)&lo[i] << endl;
		break;
	}
	/*int���͵Ĵ���*/
	case 3:
	{
		cout << "sizeof(int)=" << int_size << endl;
		size = sizeof(in) / int_size;
		for (int i = 0; i < size; i++)
			cout << "&in[" << i << "]=" << (long)&in[i] << endl;
		break;
	}
	/*float���͵Ĵ���*/
	case 4:
	{
		cout << "sizeof(float)=" << fz << endl;
		size = sizeof(fl) / fz;
		for (int i = 0; i < size; i++)
			cout << "&fl[" << i << "]=" << (long)&fl[i] << endl;
		break;
	}
	/*double���͵Ĵ���*/
	case 5:
	{
		cout << "sizeof(double)=" << dz << endl;
		size = sizeof(dou) / dz;
		for (int i = 0; i < size; i++)
			cout << "&dou[" << i << "]=" << (long)&dou[i] << endl;
		break;
	}
	default:cout << "������1��5֮�������" << endl;
	}
	
}
void chapter3_20(void)
{
	/*����ArrayAddresses.cpp����ļ�����
	���StructArray.cpp�����ж����struct
	�Ĵ�С�Լ�����Ԫ�صĵ�ַ*/
	typedef struct 
	{
		int i, j, k;
	}ThreeDpoint;
	ThreeDpoint p1;
	p1.i = 0; p1.j = 1; p1.k = 2;
	cout << "p1.i=" << p1.i << endl;
	cout << "p1.j=" << p1.j << endl;
	cout << "p1.k=" << p1.k << endl;
	cout << "struct�Ĵ�СΪ" << sizeof(p1) << endl;
}
void chapter3_21(void)
{
	/*����һ��string���������Ҷ�
	ÿһ��Ԫ�ظ�һ���ַ�������forѭ�����������*/
	string str[3];
	str[0] = "zheng";
	str[1] = "zhi";
	str[2] = "da";
	for (int i = 0; i < 3; i++)
		cout << str[i] << endl;
}
void chapter3_22(int argc,char *argv[])
{
	/*��ArgsToInts.cpp�Ļ����ϣ�
	���������������Ǹ���ʹ��atol()��atof()����*/
	/*��ASCIIת��Ϊlong*/
	cout << "��ASCIIת��Ϊlong" << endl;
	for (int i = 1; i < argc; i++)
		cout << atol(argv[i]) << endl;
	/*��ASCIIת��Ϊint*/
	cout << "��ASCIIת��Ϊint" << endl;
	for (int i = 1; i < argc; i++)
		cout << atoi(argv[i]) << endl;
	/*��ASCIIת��Ϊdouble*/
	cout << "��ASCIIת��Ϊdouble" << endl;
	for (int i = 1; i < argc; i++)
		cout << atof(argv[i]) << endl;
	cout << argv[1] << endl;
}
void chapter3_23(void)
{
	/*PoniterIncrement2.cpp,����ʹ��union����struct*/
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
	/*�޸�PointerArithmetic.cpp����ʹ��long��long double*/
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
/*û�ܳɹ�*/
}
void chapter3_27(void )
{
	/*����const_cast��ÿ��Ԫ��ת��Ϊnon-cast��non-volatile��Ȼ���ÿ��Ԫ�ظ�ֵ*/
	const double cd[] = { 0,0,0 };
	volatile double vd[] = { 1,1 };
	int num1 = sizeof(cd) / sizeof(double), num2 = sizeof(vd) / sizeof(double);
	double *newdou=	const_cast<double*>(cd);
	double *newdou_vd = const_cast<double*>(vd);
	cout << "�����ǵ�һ��" << endl;
	for (int i = 0; i < num1; i++)
	{
		newdou[i] = i;
		cout << cd[i] << endl;
	}
	cout << "�����ǵڶ���" << endl;
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
	/*����makefile�ļ������Ա���YourPets1.cpp��YourPets2.cpp����
	�������ض��ı��������Լ�ִ��������������ΪĬ�ϵ�Ŀ�꣬ȷ��ʹ�ú�׺����*/
	//��ʱ����
}
int chapter3_32_1(double d_num)
{
	cout << "�������ֵΪ��"<< d_num << endl;
	int num = d_num - 1;
	return num;
}
void chapter3_32(void)
{
	/*�����ͳ�ʼ��һ��ָ��ú�����ָ�룬ͨ��ָ������������*/
	double d_num = 2.5;
	int(*fun_pointer)(double d_num);
	fun_pointer = chapter3_32_1;
	int x=fun_pointer(3.5);
	cout << "��������Ϊ��" << x	<<"," <<fun_pointer(4.5) <<endl;
}


