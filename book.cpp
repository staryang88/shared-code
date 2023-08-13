#include<iostream>
#include<iomanip>
#include"book.h"
using namespace std;
char* Book::getname() // 获得书名
{
	return name;
}
int Book::getnote() //获得删除标记
{
	return note;
}
int Book::getnumber() //获得图书编号
{
	return  number;
}
void Book::setname(char na[]) //设置书名
{
	strcpy_s(name, na);
}

void Book::addbook(int n, char* na)//添加图书
{
	note = 0;  //0表示未删除
	number = n;
	strcpy_s(name, na);
	onshelf = 1;  //上架标志标为1
}
void Book::delbook() //删除图书
{
	note = 1;  //1表示已经删除
}
void Book::recoverbook() //恢复图书
{
	note = 0;  //1表示已经删除
}

void Book :: bbook()
{
	onshelf = 0;
}

int Book::borrowbook()//借书操作
{
	return onshelf;
}

void Book::retbook()//还书操作
{
	onshelf = 1;
}
void Book::list()//输出图书
{
	cout << "  图书编号:"<<  number << "    书名:" << name << "    上架状态:" << onshelf << "    删除状态:" << note << endl;
}