#pragma once
#ifndef rdatabase_H_
#define rdatabase_H_
#include<iostream>
#include"reader.h"
using namespace std;
const int Maxr = 100;//��������
class RDatabase
{
private:
	int top;  //���߼�¼ָ��
	Reader read[Maxbor]; //���߼�¼
public:
	RDatabase();//���캯����ʼ�������ļ�
	void clear();//ɾ�����ж�����Ϣ
	int addreader(int n, char* na);//��Ӷ��߼�¼ʱ��ȷ�����Ƿ����
	Reader* query(int readerid);//���ձ�Ų���
	Reader* query_id(int readerid);//�����ձ�Ų���
	void list();//������ж�����Ϣ
	void delet_all();//ɾ�����ж���
	void readerdata();//���߿�ά��
	~RDatabase();//����������д�ļ�
};
#endif rdatabase_H_
