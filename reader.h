#pragma once
#ifndef reader_H_
#define reader_H_
#include<iostream>
using namespace std;
const int Maxbor = 5; //��������
class Reader //������
{
private:
	int note;//ɾ����ǣ�1����ɾ 0��δɾ��
	int number;//���߱��
	char name[10];//��������
	int borbook[Maxbor];//����ͼ��
public:
	Reader(){}//���캯��
	char* getname();//�������
	int getnote();//���ɾ�����
	int getnumber();//��ö��߱��
	void setname(char na[]);//��������
	// void delbook();//����ɾ�����
	void delreader();//����ɾ�����
	void recoverreader();//�ָ�����
	void addreader(int n,char* na);//��Ӷ���
	void borrowbook(int bookid);//�������
	int retbook(int bookid);//�������
	void list();//���������Ϣ
};
#endif // !reader_H_

