#include <iostream>
using namespace std;

bool arr[26];

int main(){

	string s1, s2, s3;
	cin >> s1 >> s2 >>s3;

	arr[s1[0] - 'a'] = true;
	arr[s2[0] - 'a'] = true;
	arr[s3[0] - 'a'] = true;

	if(arr['l' - 'a']  && arr['k' - 'a'] && arr['p' - 'a'])
		cout << "GLOBAL";
	else
		cout << "PONIX";


	return 0;
}