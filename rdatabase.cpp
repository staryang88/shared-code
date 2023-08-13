#include"rdatabase.h"
#include<fstream>
#include<iostream>
using namespace std;
RDatabase::RDatabase()//构造函数初始化：读文件
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
void RDatabase::clear()//删除所有读者信息
{
	top = -1;
}
int RDatabase::addreader(int n, char* na)//添加读者记录时，确认他是否存在
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
Reader* RDatabase::query(int readerid)//按照编号查找
{
	for (int i = 0; i <= top; i++)
		if (read[i].getnumber() == readerid && read[i].getnote() == 0)
		{
			return &read[i];
		}
	return NULL;
}

Reader* RDatabase::query_id(int readerid)//按照编号查找
{
	for (int i = 0; i <= top; i++)
		if (read[i].getnumber() == readerid )
		{
			return &read[i];
		}
	return NULL;
}


void RDatabase::list()//输出所有读者信息
{
	for (int i = 0; i <= top; i++)
	{
		read[i].list();
	}
}


void RDatabase::delet_all()//删除读者：所有的删除状态为1
{
	for (int i = 0; i <= top; i++)
	{
		read[i].delreader();
	}
}

RDatabase::~RDatabase()//析构函数：写文件
{
	fstream file;
	file.open("reader.dat", ios::out | ios::binary);
	for (int i = 0; i <= top; i++)
		if (read[i].getnote() == 0)
			file.write((char*)&read[i], sizeof(read[i]));
	file.close();
}
void RDatabase::readerdata()//读者库维护
{
	int choice = 1;
	char readername[20];
	int readerid;
	Reader* r;

	while (choice != 0)
	{
		cout << "读者维护：" << endl;
		cout << "----------------------------" << endl;
		cout << "1:新增 2:更改 3:删除 4:查找 5:显示 6:全删 7:恢复 0:退出" << endl;
		cin >> choice;
		cout << "----------------------------" << endl;
		switch (choice)
		{
		case 1://新增读者
			cout << "输入读者编号：";
			cin >>readerid;
			cout << "输入读者姓名：";
			cin >> readername;
			addreader(readerid, readername);
			break;
		case 2://更改读者
			cout << "输入读者编号：" << endl;
			cin >> readerid;
			r = query(readerid);
			if (r == NULL)
			{
				cout << "该读者不存在！" << endl;
				break;
			}
			cout << "输入新的姓名：" << endl;
			cin >> readername;
			r->setname(readername);
			break;
		case 3://删除读者
			cout << "输入读者编号：" << endl;
			// cin >> readername;
			cin >> readerid;
			r = query(readerid);
			if (r == NULL)
			{
				cout << "该读者不存在！" << endl;
				break;
			}
			r->delreader();//删除读者？
			break;
		case 4://查找读者
			cout << "输入读者编号：" << endl;
			cin >> readerid;
			r = query(readerid);
			if (r== NULL)
			{
				cout << "该读者不存在！" << endl;
				break;
			}
			r->list();
			break;
		case 5://显示图书
			list();
			break;
		case 6://
			delet_all();
			break;
		case 7:
			cout << "输入读者编号：" << endl;
			cin >> readerid;
			r = query_id(readerid);
			if (r == NULL)
			{
				cout << "该读者不存在！" << endl;
				break;
			}
			r->recoverreader();//恢复读者
			break;
		default:
			break;
		}
	}
}