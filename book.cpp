#include<iostream>
#include<iomanip>
#include"book.h"
using namespace std;
char* Book::getname() // �������
{
	return name;
}
int Book::getnote() //���ɾ�����
{
	return note;
}
int Book::getnumber() //���ͼ����
{
	return  number;
}
void Book::setname(char na[]) //��������
{
	strcpy_s(name, na);
}

void Book::addbook(int n, char* na)//���ͼ��
{
	note = 0;  //0��ʾδɾ��
	number = n;
	strcpy_s(name, na);
	onshelf = 1;  //�ϼܱ�־��Ϊ1
}
void Book::delbook() //ɾ��ͼ��
{
	note = 1;  //1��ʾ�Ѿ�ɾ��
}
void Book::recoverbook() //�ָ�ͼ��
{
	note = 0;  //1��ʾ�Ѿ�ɾ��
}

void Book :: bbook()
{
	onshelf = 0;
}

int Book::borrowbook()//�������
{
	return onshelf;
}

void Book::retbook()//�������
{
	onshelf = 1;
}
void Book::list()//���ͼ��
{
	cout << "  ͼ����:"<<  number << "    ����:" << name << "    �ϼ�״̬:" << onshelf << "    ɾ��״̬:" << note << endl;
}