#pragma once
#ifndef reader_H_
#define reader_H_
#include<iostream>
using namespace std;
const int Maxbor = 5; //最大借阅量
class Reader //读者类
{
private:
	int note;//删除标记（1：已删 0：未删）
	int number;//读者编号
	char name[10];//读者姓名
	int borbook[Maxbor];//所借图书
public:
	Reader(){}//构造函数
	char* getname();//获得姓名
	int getnote();//获得删除标记
	int getnumber();//获得读者编号
	void setname(char na[]);//设置姓名
	// void delbook();//设置删除标记
	void delreader();//设置删除标记
	void recoverreader();//恢复读者
	void addreader(int n,char* na);//添加读者
	void borrowbook(int bookid);//借书操作
	int retbook(int bookid);//还书操作
	void list();//输出读者信息
};
#endif // !reader_H_

