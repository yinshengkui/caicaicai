// 2016.9.3-1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm>

using namespace std;

//void sortaaa(int* a, int len){
//	int low = 0, height = len - 1;
//
//	while (low < height){
//		while (a[low] != 10){
//			low++;
//		}
//		while (a[height] == 10){
//			height--;
//		}
//
//		int temp;
//		temp = a[low];
//		a[low] = a[height];
//		a[height] = temp;
//		low++;
//		height--;
//
//	}
//
//}

int _tmain(int argc, _TCHAR* argv[])
{
	int i = 0,k=0;
	int a[15] = { 0 };



	while (cin >> a[0]){
		cin >> a[1];
		cin >> a[2];
		cin >> a[3];
		cin >> a[4];
		cin >> a[5];
		cin >> a[6];
		cin >> a[7];
		cin >> a[8];
		cin >> a[9];
		cin >> a[10];
		cin >> a[11];
		cin >> a[12];
		cin >> a[13];
		cin >> a[14];


		int j = 0;
		/*while (j<15){
			cout << a[j] << endl;
			j++;
		}*/
		int flag;
		int flage=1;
		int flags = 0;
		
		while (flage){
			flage = 0;
			/*cout << "flage=" << flage << endl;*/
			for (i = 0; i < 13;){
				//cout << "i=" << i << endl;
				if (a[i]==10 && i!=12){
					i++;
					continue;
				}
				else if (a[i] == 10 && i == 12)
				{
					i++;
					break;
				}
				flag = 1;
				flags = 0;
				for (j = i+1; j < 15;j++){
					if (a[j]==10 && j!=14){
						flags++;
						continue;
					}
					else if (a[j] == 10 && j == 14){
						flags++;
						if (flag >= 3){
							flage = 1;
							for (k = 0; k < flag + flags; k++){
								a[i + k] = 10;
							}
							i = i + flag + flags;
							break;
						}
						else{
							i = i + flag + flags;
							break;
						}
					}
					if (a[i]==a[j]){
						flag++;
						if (j==14){
							if (flag >= 3){
								flage = 1;
								for (k = 0; k < flag + flags; k++){
									a[i + k] = 10;
								}
								i = i + flag + flags;
								break;
							}
							else{
								i = i + flag + flags;
								break;
							}
						}
						continue;
					}else{
						if (flag>=3){
							flage = 1;
							for (k = 0; k < flag + flags; k++){
								a[i + k] = 10;
							}
							i = i + flag + flags;
							break;
						}else{
							i = i + flag + flags;
							break;
						}
					}
				}
			}	
			//cout << "flage=" << flage << endl;
		}
		int flago = 1;
		for (i = 0; i < 15;i++){
			if (a[i]!=10){
				flago = 0;
				cout << a[i];
			}
		}
		if (flago){
			cout << "none";
		}
		cout << endl;



	}



	system("pause");
	return 0;
}

