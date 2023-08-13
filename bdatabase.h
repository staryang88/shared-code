#pragma once
#ifndef bdatabase_H_
#define bdatabase_H_
#include<iostream>
#include"book.h"
using namespace std;
const int Maxb = 100;//最大图书数量
class BDatabase //图书库类
{
private:
	int top;//图书记录指针
	Book book[Maxb];//图书记录
public:
	BDatabase();//构造函数初始化：读文件
	void clear();//全部删除
	int addbook(int n, char* na);//添加图书
	Book* query(int bookid);//查找图书
	Book* query_id(int bookid);//查找图书编号
	void list();//输出图书信息
	void bookdata();//图书库的维护
	void delete_all();//删除所有图书
	~BDatabase();//析构函数：写文件
};
#endif  bdatabase_H_
