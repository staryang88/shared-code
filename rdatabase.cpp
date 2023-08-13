#include"rdatabase.h"
#include<fstream>
#include<iostream>
using namespace std;
RDatabase::RDatabase()//���캯����ʼ�������ļ�
{
	Reader s;
	top = -1;
	ifstream file;
	file.open("reader.dat", ios::in | ios::binary);
	while (1)
	{
		file.read((char*)&s, sizeof(s));
		if (!file) break;
		top++;
		read[top] = s;
	}
	file.close();
}
void RDatabase::clear()//ɾ�����ж�����Ϣ
{
	top = -1;
}
int RDatabase::addreader(int n, char* na)//��Ӷ��߼�¼ʱ��ȷ�����Ƿ����
{
	Reader* p = query(n);
	if (p == NULL)
	{
		top++;
		read[top].addreader(n, na);
		return 1;
	}
	return 0;
}
Reader* RDatabase::query(int readerid)//���ձ�Ų���
{
	for (int i = 0; i <= top; i++)
		if (read[i].getnumber() == readerid && read[i].getnote() == 0)
		{
			return &read[i];
		}
	return NULL;
}

Reader* RDatabase::query_id(int readerid)//���ձ�Ų���
{
	for (int i = 0; i <= top; i++)
		if (read[i].getnumber() == readerid )
		{
			return &read[i];
		}
	return NULL;
}


void RDatabase::list()//������ж�����Ϣ
{
	for (int i = 0; i <= top; i++)
	{
		read[i].list();
	}
}


void RDatabase::delet_all()//ɾ�����ߣ����е�ɾ��״̬Ϊ1
{
	for (int i = 0; i <= top; i++)
	{
		read[i].delreader();
	}
}

RDatabase::~RDatabase()//����������д�ļ�
{
	fstream file;
	file.open("reader.dat", ios::out | ios::binary);
	for (int i = 0; i <= top; i++)
		if (read[i].getnote() == 0)
			file.write((char*)&read[i], sizeof(read[i]));
	file.close();
}
void RDatabase::readerdata()//���߿�ά��
{
	int choice = 1;
	char readername[20];
	int readerid;
	Reader* r;

	while (choice != 0)
	{
		cout << "����ά����" << endl;
		cout << "----------------------------" << endl;
		cout << "1:���� 2:���� 3:ɾ�� 4:���� 5:��ʾ 6:ȫɾ 7:�ָ� 0:�˳�" << endl;
		cin >> choice;
		cout << "----------------------------" << endl;
		switch (choice)
		{
		case 1://��������
			cout << "������߱�ţ�";
			cin >>readerid;
			cout << "�������������";
			cin >> readername;
			addreader(readerid, readername);
			break;
		case 2://���Ķ���
			cout << "������߱�ţ�" << endl;
			cin >> readerid;
			r = query(readerid);
			if (r == NULL)
			{
				cout << "�ö��߲����ڣ�" << endl;
				break;
			}
			cout << "�����µ�������" << endl;
			cin >> readername;
			r->setname(readername);
			break;
		case 3://ɾ������
			cout << "������߱�ţ�" << endl;
			// cin >> readername;
			cin >> readerid;
			r = query(readerid);
			if (r == NULL)
			{
				cout << "�ö��߲����ڣ�" << endl;
				break;
			}
			r->delreader();//ɾ�����ߣ�
			break;
		case 4://���Ҷ���
			cout << "������߱�ţ�" << endl;
			cin >> readerid;
			r = query(readerid);
			if (r== NULL)
			{
				cout << "�ö��߲����ڣ�" << endl;
				break;
			}
			r->list();
			break;
		case 5://��ʾͼ��
			list();
			break;
		case 6://
			delet_all();
			break;
		case 7:
			cout << "������߱�ţ�" << endl;
			cin >> readerid;
			r = query_id(readerid);
			if (r == NULL)
			{
				cout << "�ö��߲����ڣ�" << endl;
				break;
			}
			r->recoverreader();//�ָ�����
			break;
		default:
			break;
		}
	}
}