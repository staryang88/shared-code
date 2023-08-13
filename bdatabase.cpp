#include"bdatabase.h"
#include<iostream>
#include<fstream>
using namespace std;
BDatabase::BDatabase()//构造函数初始化：读文件
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
void BDatabase::clear()//全部删除
{
	top = -1;
}
int BDatabase::addbook(int n, char* na)//添加图书
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
Book* BDatabase::query(int bookid)//查找图书
{
	for (int i = 0; i <= top; i++)
		if (book[i].getnumber() == bookid && book[i].getnote() == 0)
			return &book[i];
	return NULL;
}
Book* BDatabase::query_id(int bookid)//查找图书
{
	for (int i = 0; i <= top; i++)
		if (book[i].getnumber() == bookid )
			return &book[i];
	return NULL;
}
void BDatabase::list()//输出图书信息
{
	for (int i = 0; i <= top; i++)
	{
		book[i].list();
	}
}

void BDatabase::delete_all()//删除图书信息
{
	for (int i = 0; i <= top; i++)
	{
		book[i].delbook();//删除图书

	}
}

BDatabase::~BDatabase()//析构函数：写文件
{
	cout << "写文件" << endl;
	fstream file;
	file.open("book.dat", ios::out | ios::binary);
	for (int i = 0; i <= top; i++)
		if (book[i].getnote() == 0)
			file.write(((char*)&book[i]), sizeof(book[i]));
	file.close();
}
void BDatabase::bookdata()//图书库的维护
{
	int choice = 1;
	char bookname[20];
	int bookid;
	Book* b;

	while (choice != 0)
	{
		cout << "图书维护：" << endl;
		cout << "----------------------------" << endl;
		cout << "1:新增 2:更改 3:删除 4:查找 5:显示 6:全删 7:恢复 0:退出" << endl;
		cin >> choice;
		cout << "----------------------------" << endl;
		switch (choice)
		{
		case 1://新增图书
			cout << "输入图书编号：" << endl;
			cin >> bookid;
			cout << "输入图书名：" << endl;
			cin >> bookname;
			addbook(bookid, bookname);
			break;
		case 2://更改图书
			cout << "输入图书编号：" << endl;
			cin >> bookid;
			b = query(bookid);
			if (b == NULL)
			{
				cout << "该图书不存在！" << endl;
				break;
			}
			cout << "输入新的图书名：" << endl;
			cin >> bookname;
			b->setname(bookname);
			break;
		case 3://删除图书
			cout << "输入图书编号：" << endl;
			cin >> bookid;
			b = query(bookid);
			if (b == NULL)
			{
				cout << "该图书不存在！" << endl;
				break;
			}
			//b->delbook();//删除图书？
			b->delbook(); break;
		case 4://查找图书
			cout << "输入图书编号：" << endl;
			cin >> bookid;
			b = query(bookid);
			if (b == NULL)
			{
				cout << "该图书不存在！" << endl;
				break;
			}
			b->list();
			break;
		case 5://显示图书
			list();
			break;
		case 6://全删
			delete_all();
			break;
		case 7://恢复
			cout << "输入图书编号：" << endl;
			cin >> bookid;
			b = query_id(bookid);
			if (b == NULL)
			{
				cout << "该图书不存在！" << endl;
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
