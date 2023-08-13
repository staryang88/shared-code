#pragma once
#ifndef rdatabase_H_
#define rdatabase_H_
#include<iostream>
#include"reader.h"
using namespace std;
const int Maxr = 100;//最大读者数
class RDatabase
{
private:
	int top;  //读者记录指针
	Reader read[Maxbor]; //读者记录
public:
	RDatabase();//构造函数初始化：读文件
	void clear();//删除所有读者信息
	int addreader(int n, char* na);//添加读者记录时，确认他是否存在
	Reader* query(int readerid);//按照编号查找
	Reader* query_id(int readerid);//仅按照编号查找
	void list();//输出所有读者信息
	void delet_all();//删除所有读者
	void readerdata();//读者库维护
	~RDatabase();//析构函数：写文件
};
#endif rdatabase_H_
