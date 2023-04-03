#include <iostream>
using namespace std;

pair <char, char> arr[27];
int N;
bool visited[27] = { false, };

//A가 항상 루트 노드

void preorder(char node) { //전위 순회
	
	if (node != '.') {
		cout << node;
		preorder(arr[(int)node - 65].first);
		preorder(arr[(int)node - 65].second);
	}
}

void inorder(char node) { //중위 순회

	if (node != '.') {
		inorder(arr[(int)node - 65].first);
		cout << node;
		inorder(arr[(int)node - 65].second);
	}

}

void postorder(char node) { //후위 순회
	if (node != '.') {
		postorder(arr[(int)node - 65].first);
		postorder(arr[(int)node - 65].second);
		cout << node;
	}
}

int main() {

	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		char ch;
		cin >> ch; //A 아스키코드: 65

		char left, right;
		cin >> left >> right;

		int index = (int)ch - 65;

		arr[index].first = left;
		arr[index].second = right;

	}

	preorder('A');
	cout << "\n";
	inorder('A');
	cout << "\n";
	postorder('A');

	return 0;
}