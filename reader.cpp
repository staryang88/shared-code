#include<iomanip>//?
#include"reader.h"
//const int Maxbor = 5; //最大借阅量
#include<iostream>
char* Reader::getname()//获得姓名
{
	return name;
}
int Reader::getnote()//获得删除标记
{
	return note;//1:已删除 0:未删除
}

int Reader::getnumber()//获得读者编号
{
	return number;
}
void Reader::setname(char na[])//设置姓名
{
	strcpy_s(name, na);
}

void Reader::delreader()//设置删除标记
{
	note = 1;
}

void Reader::recoverreader()//设置删除标记
{
	note = 0;
}


void Reader::addreader(int n, char* na)//添加读者
{
	note = 0;
	number = n;
	strcpy_s(name, na);
	for (int i = 0; i < Maxbor; i++)
	{
		borbook[i] = 0;  //所借图书 初始化借阅图书列表
	}

}
void Reader::borrowbook(int bookid)//借书操作
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
int Reader::retbook(int bookid)//还书操作
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
void Reader::list()//输出读者信息
{
	// cout << setw(5) << number << setw(10) << name  << setw(10) << "删除标志" << note << setw(10) << "    借书编号：[";	
	cout << "  读者编号:" << number << "    姓名:" << name <<  "    删除状态:" << note << "    借书编号：[";
	for (int i = 0; i < Maxbor; i++)
	{
		// if (borbook[i] == 0) cout << borbook[i] << "";
		if (borbook[i] != 0) cout << borbook[i] << " ";
		
	}
	cout << "]" << endl;
}
