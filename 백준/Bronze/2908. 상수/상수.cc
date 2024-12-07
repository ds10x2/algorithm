#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <cctype>
using namespace std;



int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	string a, b;
	cin >> a >> b;
	
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	if (a > b) cout << a;
	else cout << b;

	return 0;
}