// ��߷�����.cpp : �������̨Ӧ�ó������ڵ㡣
//��ɸ���10λŮʿƴ������������һλ��ʿƴ����������ʿ������Ůʿ�����ظ��ַ�����Ϊ��߷����࣬�������ʿ��ƥ���Ůʿ����
//Ҫ���ظ����ַ�ֻ����һ��������Li Ling��Li Lei �ظ����ַ�Ϊ2������Ϊ4
//Ҫ�������ʿ�Ͷ�λŮʿ����ظ��ַ���ͬ���������һλƥ�����ߵ�Ůʿ����
//Ůʿ����wang fei�� zhang manyu�� zhang zhiyi�� fan bingbing�� liu yifei�� gao yuanyuan ��zhao wei ��lin xinru�� li ling��wang lingling

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
		//	cout << "Ůʿ" << strWomen << endl;
		//	cout<< "��ʿ"<<strMen << endl;
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

