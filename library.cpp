#include"reader.h"
#include"rdatabase.h"
#include"book.h"
#include"bdatabase.h"
#include<iostream>
using namespace std;
int main(int argc, char* argv[])
{
	int choice = 1, bookid, readerid;
	RDatabase ReaderDB;
	BDatabase BookDB;
	Reader *r;
	Book *b;
	cout << "��ӭ���롰ССͼ��ݡ��������" << endl;
	cout << "----------------------------------" << endl;
	while (choice != 0)
	{
		cout << "1:���� 2:���� 3:ͼ��ά�� 4:����ά�� 0:�뿪" << endl;
		cin >> choice;
		cout << "----------------------------------" << endl;
		switch (choice)
		{
		case 1://����
			cout << "���������߱��";
			cin >> readerid;
			cout << "����ͼ����";
			cin >> bookid;
			r = ReaderDB.query(readerid);
			if (r == NULL)
			{
				cout << "���߲����ڣ����ܽ��飡" << endl;
				break;
			}
			b = BookDB.query(bookid);
			if (b == NULL)
			{
				cout << "ͼ�鲻���ڣ����ܽ��飡" << endl;
				break;
			}
			if (b->borrowbook() == 0)
			{
				cout << "��ͼ���ѽ�������ܽ��飡" << endl;
				break;
			}
			b->bbook();
			r->borrowbook(b->getnumber());
			break;
		case 2://����
			cout << "���뻹����߱��";
			cin >> readerid;
			cout << "����ͼ����";
			cin >> bookid;
			r = ReaderDB.query(readerid);
			if (r == NULL)
			{
				cout << "�ö��߲����ڣ����ܻ��飡" << endl;
				break;
			}
			b = BookDB.query(bookid);
			if (b == NULL)
			{
				cout << "��ͼ�鲻���ڣ����ܻ��飡" << endl;
				break;
			}
			b->retbook();
			r->retbook(b->getnumber());
			break;
		case 3:
			BookDB.bookdata();
			break;
		case 4:
			ReaderDB.readerdata();
			break;

		default:
			break;
		}
	}



	return 0;
}