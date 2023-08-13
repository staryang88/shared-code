#include"bdatabase.h"
#include<iostream>
#include<fstream>
using namespace std;
BDatabase::BDatabase()//���캯����ʼ�������ļ�
{
	Book s;
	top = -1;
	fstream file;
	file.open("book.dat", ios::in | ios::binary);
	while (1)
	{
		file.read((char*)&s, sizeof(s));
		if (!file) break;
		top++;
		book[top] = s;
	}
	file.close();
}
void BDatabase::clear()//ȫ��ɾ��
{
	top = -1;
}
int BDatabase::addbook(int n, char* na)//���ͼ��
{
	
	Book *p = query(n);
	if (p == NULL)
	{
		
		top++;
		book[top].addbook(n, na);
		return 1;
	}
	return 0;
}
Book* BDatabase::query(int bookid)//����ͼ��
{
	for (int i = 0; i <= top; i++)
		if (book[i].getnumber() == bookid && book[i].getnote() == 0)
			return &book[i];
	return NULL;
}
Book* BDatabase::query_id(int bookid)//����ͼ��
{
	for (int i = 0; i <= top; i++)
		if (book[i].getnumber() == bookid )
			return &book[i];
	return NULL;
}
void BDatabase::list()//���ͼ����Ϣ
{
	for (int i = 0; i <= top; i++)
	{
		book[i].list();
	}
}

void BDatabase::delete_all()//ɾ��ͼ����Ϣ
{
	for (int i = 0; i <= top; i++)
	{
		book[i].delbook();//ɾ��ͼ��

	}
}

BDatabase::~BDatabase()//����������д�ļ�
{
	cout << "д�ļ�" << endl;
	fstream file;
	file.open("book.dat", ios::out | ios::binary);
	for (int i = 0; i <= top; i++)
		if (book[i].getnote() == 0)
			file.write(((char*)&book[i]), sizeof(book[i]));
	file.close();
}
void BDatabase::bookdata()//ͼ����ά��
{
	int choice = 1;
	char bookname[20];
	int bookid;
	Book* b;

	while (choice != 0)
	{
		cout << "ͼ��ά����" << endl;
		cout << "----------------------------" << endl;
		cout << "1:���� 2:���� 3:ɾ�� 4:���� 5:��ʾ 6:ȫɾ 7:�ָ� 0:�˳�" << endl;
		cin >> choice;
		cout << "----------------------------" << endl;
		switch (choice)
		{
		case 1://����ͼ��
			cout << "����ͼ���ţ�" << endl;
			cin >> bookid;
			cout << "����ͼ������" << endl;
			cin >> bookname;
			addbook(bookid, bookname);
			break;
		case 2://����ͼ��
			cout << "����ͼ���ţ�" << endl;
			cin >> bookid;
			b = query(bookid);
			if (b == NULL)
			{
				cout << "��ͼ�鲻���ڣ�" << endl;
				break;
			}
			cout << "�����µ�ͼ������" << endl;
			cin >> bookname;
			b->setname(bookname);
			break;
		case 3://ɾ��ͼ��
			cout << "����ͼ���ţ�" << endl;
			cin >> bookid;
			b = query(bookid);
			if (b == NULL)
			{
				cout << "��ͼ�鲻���ڣ�" << endl;
				break;
			}
			//b->delbook();//ɾ��ͼ�飿
			b->delbook(); break;
		case 4://����ͼ��
			cout << "����ͼ���ţ�" << endl;
			cin >> bookid;
			b = query(bookid);
			if (b == NULL)
			{
				cout << "��ͼ�鲻���ڣ�" << endl;
				break;
			}
			b->list();
			break;
		case 5://��ʾͼ��
			list();
			break;
		case 6://ȫɾ
			delete_all();
			break;
		case 7://�ָ�
			cout << "����ͼ���ţ�" << endl;
			cin >> bookid;
			b = query_id(bookid);
			if (b == NULL)
			{
				cout << "��ͼ�鲻���ڣ�" << endl;
				break;
			}
			//b->delbook();
			b->recoverbook();
			break;
		default:
			break;
		}
	}
	}
