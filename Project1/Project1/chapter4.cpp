#include <stdio.h>
#include <iostream>
#include <cassert>
#include "chapter4.h"
using namespace std;
void chapter4_1(void)
{
	/*����Ŀǰû�и��ܵ�����*/
	puts("hello");
}
typedef struct
{
	int chapter4_2_1(int num);
}my_struct;
int my_struct::chapter4_2_1(int num)
{
	cout << "���������Ϊ��" << num << endl;
	return num - 1;
}
void chapter4_2(void)
{
	/*�ṹ��Ķ��壬�ṹ���Ա�а����ĺ����Ķ���
	ҲӦ����ṹ��Ķ���ķ�ΧΪͬ�������ڵ��ú������ⲿ*/
	my_struct struct_example1;
   int x= struct_example1.chapter4_2_1(3);
   cout << "���صĽ��Ϊ��" << x << endl;
}

// chapter4_3����
 struct struct1
{
	int chapter4_3_1(int num);
};

 int struct1::chapter4_3_1(int num)
 {
	 cout << "���������Ϊ��" << num << endl;
	 return num - 1;
 }

void chapter4_3(void)
{
	struct struct1 struct1_example;
	int x = struct1_example.chapter4_3_1(5);
	cout << "���صĽ��Ϊ��" << x << endl;
}
/*����һ��struct������һ��int���ݳ�Ա������ȫ�ֺ�����
ÿ����������һ��ָ��ú�����ָ�룬��һ�������ĵ�2������Ϊint��
�����丳ֵ���ṹ���int�������ڶ����������ӡ�ṹ���int����ֵ*/
struct struct4_5
{
	int int_num;
	void chapter4_5_1(struct4_5 *struct4_5example, int num);
	void chapter4_5_2(struct4_5 *struct4_5example);
};
void struct4_5::chapter4_5_1(struct4_5 *struct4_5example, int num)
{
	struct4_5example->int_num = num;
	cout <<"�ṹ���int�Ͳ���Ϊ��"<< struct4_5example->int_num << endl;
}
void struct4_5::chapter4_5_2(struct4_5 *struct4_5example)
{
	cout << "�ṹ���int�Ͳ���Ϊ��" << struct4_5example->int_num << endl;
}
void chapter4_5(void)
{
	struct struct4_5 struct_example;
	struct_example.int_num = 10;
	struct_example.chapter4_5_1(&struct_example, 9);
	struct_example.chapter4_5_2(&struct_example);
}
/*����һ���࣬ʹ�ùؼ���thisִ�����ݳ�Աѡ��ͳ�Ա�����ĵ��� 
this һ������������ڲ������У�����������ĳ�Ա������
����ṹ����ͬ�ı���*/
class class4_6
{
public:
	int age;
	int chapter4_6_1(class4_6 class4_6_example);
};

int class4_6::chapter4_6_1(class4_6 class4_6_example)
{
	cout << "����Ľṹ�����int�͵Ĳ���ֵΪ:" << this->age << endl;
	cout << "����Ľṹ����ĺ����Ĳ������int�͵Ĳ���ֵΪ:"
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
/*chapter4_7����*/
const int increment = 100;
struct Stash
{
	int size;//ÿ���ռ�Ĵ�С
	int quantity;//�洢�ռ������
	int next;//��һ���տռ�
	//��̬���������ֽ�
	unsigned char *storage;
	//����
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
	if (next >= quantity)//�Ƿ����㹻�Ŀռ�,���û��������increment��
		inflate(increment);
	//��Ԫ�ؿ�����storage
	//��ʼ����һ���յĿռ䣬�ڴ˻���������һ��Ԫ�صĴ�Сsize��Ȼ��nextָ��
	int startBytes = next*size;
	unsigned char *e = (unsigned char *)element;
	for (int i = 0; i < size; i++)
		storage[startBytes + i] = e[i];
	next++;
	return (next - 1);//����������Ԫ�ص�������
}
void *Stash::fetch(int index)//����
{
	//����Ƿ����
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
	for (int i = 0; i < oldBytes; i++)//������ת�Ƶ�b
		b[i] = storage[i];
	delete []storage;//ɾ���ƶ�֮��������
	storage = b;//�����ݣ���չ֮�󣩸�ֵ��storage
	quantity = newQuantity;//��չ֮���������ֵ��quantity
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
	/*Stash���double������25��doubleֵ��Ȼ���������ʾ������̨*/
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
/*��Stack��д��ϰ7*/
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
/*û��˼�������*/
}
void chapter4_11(void)
{
	/*����һ��Ԥ����,����������ݸ��Ƶ�main�����£��ſ���*/
#ifdef counter
	cout << "�Ѿ�����counter" << endl;
#endif
#ifndef counter
	cout << "û�ж���counter" << endl;
#endif // !counter
}
/*chapter4_13�Ӵ˴���ʼ*/
struct Video
{
	struct video
	{
		bool state;//0����ôŴ����𻵣�1��ʾ���
		char *name;//��ʾ�ôŴ�������
		int song_num;//�ôŴ��Ĵ�С���洢���ٸ���
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
	/*���������������ͱ�ʾ���޵��е�¼���
	�����ܶ�İ���¼��������������õ�����
	���ݺ����㣬����¼���Video��Ϣ��printf()��Ա����*/
	/*12-16���Ѷȣ�δ�ɹ�*/
}
void chapter4_17(void)
{
	int *p_int=new int;
	long *p_long = new long;
	char *p_char = new char [100];
	float *p_float = new float[100];
	cout << "p_int�ĵ�ַΪ��"<< (long)p_int << endl;
	cout << "p_long�ĵ�ַΪ��" << (long)p_long << endl;
	cout << "p_char�ĵ�ַΪ��" << (long)p_char << endl;
	cout << "p_float�ĵ�ַΪ��" << (long)p_float << endl;
	delete [] p_int;
	delete [] p_long;
	delete [] p_char;
	delete [] p_float;
	cout << "p_int�ĵ�ַΪ��" << (long)p_int << endl;
}
char * chapter4_18(char *p_char)
{
	//��ע�͵ĵط�����ʹ����main������
	/*
	static char *char_pointer = "my name is zhengzhida";
	static char *c_pointer, *c_pointer1;
	c_pointer = chapter4_18(char_pointer);
	c_pointer1 = chapter4_18(char_pointer);
	cout << c_pointer << "��ַ" << &c_pointer << endl;
	cout << c_pointer1 << "��ַ" << &c_pointer1 << endl;
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
	cout << "����Ϊ��"<< int_num << endl;
}
void struct_4_19::struct_4_19_1::printf_num(void)
{
	cout << "����Ϊ��" << f_num << endl;
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
	cout << "chapter4_20_2��intΪ��"<< int_num << endl;

}
struct chapter4_20_3 {}chapter4_20_3_example;
void chapter4_20(void)
{
	/*��ӡ�ṹ��ĳ��ȣ��������ݳ�Ա�Ľṹ��
	�������ݳ�Ա������Ա��û�г�Ա�Ľṹ*/
	int size1=sizeof(chapter4_20_1_example);
	int size2 = sizeof(chapter4_20_2_example);
	int size3 = sizeof(chapter4_20_3_example);
	cout << "���ݳ�Ա�Ľṹ����Ϊ��"<< size1 << endl;
	cout << "�������ݳ�Ա������Ա�Ľṹ�峤�ȣ�" << size2 << endl;
	cout << "�����ݳ�Ա�Ľṹ�峤�ȣ�" << size3 << endl;
}
/*21��25δ��*/
void chapter4_24(void)
{

}

