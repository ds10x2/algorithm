#include <iostream>
#include <algorithm>
using namespace std;

int LCS[1001][1001];


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string str1, str2;
	cin >> str1 >> str2;

	int Max = 0;

	for (int i = 0; i <= str1.length(); i++) {
		for (int j = 0; j <= str2.length(); j++) {
			if (i == 0 || j == 0)
				LCS[i][j] = 0;
			else if (str1[i-1] == str2[j-1]) {
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
				if (Max < LCS[i][j])
					Max = LCS[i][j];
			}
			else
				LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
		}
	}

	cout << Max;

	return 0;
}
