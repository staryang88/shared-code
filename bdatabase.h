#pragma once
#ifndef bdatabase_H_
#define bdatabase_H_
#include<iostream>
#include"book.h"
using namespace std;
const int Maxb = 100;//���ͼ������
class BDatabase //ͼ�����
{
private:
	int top;//ͼ���¼ָ��
	Book book[Maxb];//ͼ���¼
public:
	BDatabase();//���캯����ʼ�������ļ�
	void clear();//ȫ��ɾ��
	int addbook(int n, char* na);//���ͼ��
	Book* query(int bookid);//����ͼ��
	Book* query_id(int bookid);//����ͼ����
	void list();//���ͼ����Ϣ
	void bookdata();//ͼ����ά��
	void delete_all();//ɾ������ͼ��
	~BDatabase();//����������д�ļ�
};
#endif  bdatabase_H_
