#include<iomanip>//?
#include"reader.h"
//const int Maxbor = 5; //��������
#include<iostream>
char* Reader::getname()//�������
{
	return name;
}
int Reader::getnote()//���ɾ�����
{
	return note;//1:��ɾ�� 0:δɾ��
}

int Reader::getnumber()//��ö��߱��
{
	return number;
}
void Reader::setname(char na[])//��������
{
	strcpy_s(name, na);
}

void Reader::delreader()//����ɾ�����
{
	note = 1;
}

void Reader::recoverreader()//����ɾ�����
{
	note = 0;
}


void Reader::addreader(int n, char* na)//��Ӷ���
{
	note = 0;
	number = n;
	strcpy_s(name, na);
	for (int i = 0; i < Maxbor; i++)
	{
		borbook[i] = 0;  //����ͼ�� ��ʼ������ͼ���б�
	}

}
void Reader::borrowbook(int bookid)//�������
{
	
	for (int i = 0; i < Maxbor; i++)
	{
		if (borbook[i] ==0)
		{
			borbook[i] = bookid;
			return;
		}
	}
}
int Reader::retbook(int bookid)//�������
{
	for (int i = 0; i < Maxbor; i++)
	{
		if (borbook[i] == bookid)
		{
			borbook[i] = 0;
			return 1; 
		}
		return 0; 
	}
}
void Reader::list()//���������Ϣ
{
	// cout << setw(5) << number << setw(10) << name  << setw(10) << "ɾ����־" << note << setw(10) << "    �����ţ�[";	
	cout << "  ���߱��:" << number << "    ����:" << name <<  "    ɾ��״̬:" << note << "    �����ţ�[";
	for (int i = 0; i < Maxbor; i++)
	{
		// if (borbook[i] == 0) cout << borbook[i] << "";
		if (borbook[i] != 0) cout << borbook[i] << " ";
		
	}
	cout << "]" << endl;
}
