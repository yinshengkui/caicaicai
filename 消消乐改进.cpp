

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main()
{
	int i = 0,k=0;
	int a[15] = { 0 };



	while (cin >> a[0]){
		i = 1;
		while (i<15){
			cin >> a[i];
			i++;
		}
		string str;
		for (i = 0; i < 15;i++){
			str += to_string(a[i]);
		}

		int j = 0;
		cout << "str=" << str << endl;
		int flag;
		int flage=1;
		int flags = 0;
		
		while (flage){
			flage = 0;
			for (i = 0; i < str.size();){
				cout << "i=" << i << endl;
				flag = 1;
				for (j = i + 1; j < str.size(); j++){
					if (j == str.size() - 1 && str[i] == str[j]){
						flag++;
						if (flag >= 3){
							str.erase(str.begin() + i, str.begin() + i + flag);
							i = i + flag;
							break;
						}
						else{
							i = i + flag;
							break;
						}
					}

					if (str[i] == str[j]){
						flag++;
						if (j == 14){
							if (flag >= 3){
								flage = 1;
								//str.erase(&str[i], &str[i] + flag);
								str.erase(str.begin() + i, str.begin() + i + flag);
								break;
							}
							else{
								i = i + flag;
								break;
							}
						}
						continue;
					}
					else{
						if (flag >= 3){
							flage = 1;
							str.erase(str.begin() + i, str.begin() + i + flag);
							break;
						}
						else{
							i = i + flag;
							break;
						}
					}
				}
			}
		}
		int flago = 1;
		for (i = 0; i < str.size(); i++){
				flago = 0;
				cout << str[i];
		}
		if (flago){
			cout << "none";
		}
		cout << endl;



	}



	system("pause");
	return 0;
}

