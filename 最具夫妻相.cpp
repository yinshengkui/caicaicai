// 最具夫妻相.cpp : 定义控制台应用程序的入口点。
//题干给出10位女士拼音姓名，输入一位男士拼音姓名，男士姓名和女士姓名重复字符最多的为最具夫妻相，输出与男士最匹配的女士姓名
//要求重复的字符只能算一个，比如Li Ling和Li Lei 重复的字符为2而不是为4
//要求如果男士和多位女士最多重复字符相同，则输出第一位匹配度最高的女士姓名
//女士姓名wang fei， zhang manyu， zhang zhiyi， fan bingbing， liu yifei， gao yuanyuan ，zhao wei ，lin xinru， li ling，wang lingling

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
string QuChong(string str)
{
	char cha[128] = {'0'};
	int len = str.size();
	int i;
	string strNew;
	for (i = 0; i < len;i++)
	{
		cha[str[i]] = '1';
	}
	for (i = 0; i < 128; i++)
	{
		if (cha[i]=='1')
		{
			char temp = i;
			strNew.push_back(temp);
		}

	}
	return strNew;

}
int main(int argc, _TCHAR* argv[])
{
	int i, j, k,m;
	string str;
	string women[10] = { "wang feie", "wang fei", "zhang zhiyi", "fan bingbing", "liu yifei",
		                 "gao yuanyuan", "zhao wei", "lin xinru", "li ling", "wang lingling" };
	while (getline(cin,str))
	{
		int num[10];
		for (i = 0; i < 10;i++)
		{
			k = 0;
			string strWomen = QuChong(women[i]);
			string strMen = QuChong(str);
		//	cout << "女士" << strWomen << endl;
		//	cout<< "男士"<<strMen << endl;
			int len1 = strWomen.size();
			int len2 = strMen.size();
		
			for (j = 0; j < len2;j++)
			{
				for (m = 0; m < len1;m++)
				{
					if (strWomen[m] == strMen[j])
					{
						k++;
			     	}
				}
			}

			num[i] = k;
		}
		int max = 0;
		j = 0;
		for (i = 0; i < 10;i++)
		{
			if (num[i]>max)
			{
				max = num[i];
				j = i;
			}
			else if (num[i]==max)
			{
				max = num[i];
			}
		}
		cout << women[j] << endl;
	}
	return 0;
}

