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
	cout << "���캯���Ѿ�������"  << endl;
	cout <<"int��ֵΪ��" <<i << endl;
	cout << "float��ֵΪ��" << j << endl;
}
Simple::~Simple(void)
{
	cout <<"���������Ѿ�������" << endl;

}
void chapter6_1(void)
{
	/*дһ���򵥵���Simple,�乹�캯��
	��ӡһЩ��Ϣ����������������*/
	struct Simple example;
	example.i = 1;
	example.j = 1.23;
	cout << "example.i:" << example.i << endl;
	cout << "example.i:" << example.i << endl;


}
void chapter6_2(void)
{
	/*���������ڳ���{}�����ͻ�ִ��*/
	{
		struct Simple example;
		example.i = 1;
		example.j = 1.23;
		cout << "example.i:" << example.i << endl;
		cout << "example.i:" << example.i << endl;
		cout << "���������Ƿ����0" << endl;
	}
	cout << "���������Ƿ����1" << endl;
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
	cout <<"�ڶ�����" << endl;
	for (int i = 0; i < 11;i++)
		cout << i << endl;
}
void chapter6_6(void)
{
	cout <<"���˾��ÿ��Բ�����" << endl;
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
/*����һ��û�й��캯�����࣬��ʾ���ǿ���ͨ��Ĭ�ϵ�
���캯�������������ڴ���һ����Ĭ�ϵĹ��캯�����������Կ�*/
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


	/*��һ�����*/
	//struct struct6_10 example1;
	/*�ڶ������*/
	struct struct6_10 example1= struct6_10(1);
	


}