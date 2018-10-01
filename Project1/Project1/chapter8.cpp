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
	/*���������*/
}
void chapter8_4(void)
{
	/*��ͷ�ļ��д���const������������cpp�ļ���*/
	/*8-2�оͰ����˸����*/
}
void chapter8_5(void)
{
	time_t time1;
	time1 = time(NULL);
	const time_t now_time = time1;
	for (int i = 1; i < 10000; i++)
		;
	time1=time(NULL);
	//now_time = time1;//�����ԣ����벻ͨ����const�ڳ�ʼ��֮�����ڸı�
	cout <<"�������ʱ��Ϊ��" << now_time <<endl;
}
void chapter8_6(void)
{
	
	const char con_cha[] = "zhengzhida";
	int size = sizeof(con_cha)/sizeof(con_cha[0]);
	//con_cha[size - 1] = 'c';//��ͼ�޸Ļ����
}
void chapter8_7(void)
{
	extern const int chap8_7;
	cout << "chapter8_7��constֵΪ:"<<chap8_7 << endl;
}
void chapter8_8(int size)
{
	/*ʹ�ò�ͬ��������ʽ��������ָ��const long��ָ��
	��һ��ָ��long���飬��ʾ����ָ�����ӡ����٣�������
	�ı�����*/
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
		cout <<"const long ��ָ�������Ϊ��" <<*con_lon_poin << endl;
	}
	//con_lon_poin = 24;//��������
}
void chapter8_9(int size)
{
	/*дһ��ָ��double���͵�constָ�룬����ָ��double����
	��ʾ�ܸı�ָ������ݣ����ǲ������ӻ��Сָ��*/
	double* dou_num = new double[size];
	for (int i = 0; i < size; i++)
	{
		dou_num[i] = i;
	}
	double * const d_con_dou=&dou_num[0];
	cout << "double * const����ֵΪ��"<<*d_con_dou << endl;
	*d_con_dou = 123;
	//d_con_dou= &dou_num[1];//�����
	cout << "double * const����ֵΪ��" << *d_con_dou << endl;
}
void chapter8_10(int size)
{
	int* int_num = new int[size];
	for (int i = 0; i < size; i++)
	{
		int_num[i] = i;
	}
	const int *const  con_int_con=&int_num[size-1];
	cout <<"const int *const����ֵΪ��" <<*con_int_con <<endl;
	//con_int_con = &int_num[0];//����
	//*con_int_con = 123;//����
}
void chapter8_11(void)
{
}
void chapter8_12(void)
{
	/*���⻷���¿��Ըı���������ݣ�û�б���*/
	char char_array[] = "zhengzhida";
	char* char_pointer = char_array;
	int size = sizeof(char_array) / sizeof(char_array[0]);
	for (int i = 0; i < size; i++)
	{
		cout << "����ı�֮ǰ������Ϊ��" << char_array[i] << endl;
		* (char_pointer + i) = 'a' + i;
		cout << "ָ�������Ϊ��" << *(char_pointer + i) << endl;
		cout << "���������Ϊ��" << char_array[i] << endl;
	}
}
void chapter8_13(const int const_int)
{
	/*����һ��������������һ����constֵ���ݵĲ���
	Ȼ���ں���������ͼ�ı�ò���*/
	int temp = const_int;
	//const_int = (const_int + 1);//�����ں������ڲ��ɸı��ֵ
}
void chapter8_14(float fnum)
{
	/*�������������а�ֵ���ݵ�float�������ں�������
 ��const float&�󶨵������Ĳ����ϣ����Ҵ���ʱ��
 ����ʹ�����ã���ȷ�����ı����*/
	const float& con_flo = fnum;
	//con_flo++;//��������ܸı��ֵ
	cout << "�������ֵΪ��"<< con_flo <<endl;
}
void chapter8_15(float fnum)
{
	/*ConstReturnValues.cpp�ļ���ÿ��ɾ�������е�ע�ͣ�
	���������������ʲô������Ϣ*/
	/*����ΪConstReturnValues.cpp������*/
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
	//f6()=X(1);//f6()����ֵΪconst������Ϊ��ֵ
	//f6().modify();
	//f7(f6());		//�����һ����ʱ��
	}	
	*/
}
void chapter8_16(float fnum)
{
	/*ConstPointer.cpp�ļ���ÿ��ɾ��������ǰ��ע�ͣ�
	���������������ʲô������Ϣ*/
	/*������ConstPointer.cpp�ļ�*/
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
		//t(cip);//const int*������ʽ��ת��Ϊint*
		u(ip);
		u(cip);
		// char* cp=v();//v()�ķ���ֵΪconst char*,ֻ�ܸ�ֵ��const char*
		const char* ccp = v();
		//int* ip2=w();//���Ͳ�ƥ��
		const int* const ccip = w();
		const int* cip2 = w();
		//*w()=1;//��ͼ�ı�const int* const������
		}
	*/
}
void chapter8_17(float fnum)
{
	/*�����ļ�ConstPointer.cpp���°棬��ΪConstReference.cpp
	���а�ǰ��ʹ�õ�ָ�������ô���*/
	/*������ConstPointer.cpp�ļ�*/
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
	//t(cip);//const int*������ʽ��ת��Ϊint*
	u(ip);
	u(cip);
	// char* cp=v();//v()�ķ���ֵΪconst char*,ֻ�ܸ�ֵ��const char*
	const char* ccp = v();
	//int* ip2=w();//���Ͳ�ƥ��
	const int* const ccip = w();
	const int* cip2 = w();
	//*w()=1;//��ͼ�ı�const int* const������
	}
	*/
}
void chapter8_18(float fnum)
{
	/*�޸�ConstTemporary.cpp�ļ���ɾ��������ǰ��ע��
	���������������ʲô������Ϣ*/
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


/*����һ������const�ͷ�const float��Ա���ࡣ
�ù��캯���ĳ�ʼ���б���г�ʼ��*/
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
	cout <<"���е�aΪ��" << class_example.a << endl;
	cout << "���е�bΪ��" << class_example.b << endl;
}
void chapter8_20(void)
{
}
void chapter8_21(void)
{
	/*��������һ��const��Ա��һ��ö�ٳ�Ա���ࡣ
	�ڹ��캯���ĳ�ʼ���б��г�ʼ��const��Ա���ޱ�ǵ�
	ö�����ͳ�Ա����������Ĵ�С*/
}
void chapter8_22(void)
{
	/*��ConstMember.cpp�ļ��У�ɾ����Ա��
	������ǰ��const�޶�����������const�޶���
	�����������У�����������������ִ���
	����ΪConstMember.cpp*/
	/*
	class X
	{
		int i;
	public:
		X(int ii);
		int f() const;
	};
	X::X(int ii) :i(ii) {}
	int X::f()const {return i;}//ɾ��const�����û���ҵ����صĳ�Ա����
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
	cout <<"class_chap8_23��iΪ��" << i<< endl;
	return i;
}
const int class_chap8_23::fun2(void)
{
	cout << "class_chap8_23��jΪ��" << j << endl;
	return 2;
}
void chapter8_23(void)
{
/*����һ���࣬��һ��const�ͷ�const��Ա������
�ڴ��������const�ͷ�const�����ò�ͬ����
�Ķ�����ò�ͬ���͵ĳ�Ա����*/
	const class class_chap8_23 example1;
	class class_chap8_23 example2;
	//example1.fun2();//const�Ķ����ܵ�������ĺ���
	example2.fun2();
}
void chapter8_24(void)
{
	/*ǰ��8-23����*/
}
void chapter8_25(void)
{
	/*Mutable.cpp�ļ��У�ɾ��������ǰ��ע�ͣ�
	���������������ʲô������Ϣ*/
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
	/*�޸�Quoter.cpp�ļ��ĺ���quote(),ʹ����Ϊ
	const��Ա������lastquote mutable*/
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
	/*����һ����volatile���ݳ�Ա������һ��volatile��
	��volatile��Ա���������޸�volatile���ݳ�Ա������
	�����������ʲô��������������volatile�ͷ�volatile
	���󣬳��Ե���volatile�ͷ�volatile������������һ������óɹ�*/
	volatile class class_8_27 example;
	class class_8_27 example1;
	example.fun1();
	//example.fun2();//volatile���÷�volatile����
	example1.fun1();
	example1.fun2();
}
/*����һ��*/
class bird
{
public:
	int i;
	void fly(void);
	bird() :i(5) {};
};
void bird::fly(void)
{
	cout << "class bird��iΪ��"<< i<<  endl;
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