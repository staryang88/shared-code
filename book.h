#pragma once
#ifndef BOOK_H_
#define BOOK_H_
#include<iostream>
using namespace std;
class Book   //ͼ����
{
private:
	int note; //ɾ����� 1����ɾ  0��δɾ
	int number;//ͼ����
	char name[10]; //����
	int onshelf;//�ϼܱ�־
public:
	Book(){}
	char* getname();//�������
	int getnote();//���ɾ�����
	int getnumber();//���ͼ����
	void setname(char na[]);//��������
	void delbook();//ɾ��ͼ��  1��ʾ�Ѿ�ɾ��
	void recoverbook();//�ָ�ͼ��
	void addbook(int n,char *na);//���ͼ��
	int borrowbook();//�������
	void bbook(); //���������״̬
	void retbook();//�������
	void list();//���ͼ��
};

#endif // !BOOK_H_

