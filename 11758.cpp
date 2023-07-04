#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int x1, x2, x3, y1, y2, y3;


	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;

	if ((x1 * y2 - x2 * y1 + x2 * y3 - x3 * y2 + x3 * y1 - x1 * y3) / 2 > 0)
		cout << 1;
	else if ((x1 * y2 - x2 * y1 + x2 * y3 - x3 * y2 + x3 * y1 - x1 * y3) / 2 < 0)
		cout << "-1";
	else
		cout << 0;




	return 0;
}