#include <iostream>
using namespace std;

pair <char, char> arr[27];
int N;
bool visited[27] = { false, };

//A�� �׻� ��Ʈ ���

void preorder(char node) { //���� ��ȸ
	
	if (node != '.') {
		cout << node;
		preorder(arr[(int)node - 65].first);
		preorder(arr[(int)node - 65].second);
	}
}

void inorder(char node) { //���� ��ȸ

	if (node != '.') {
		inorder(arr[(int)node - 65].first);
		cout << node;
		inorder(arr[(int)node - 65].second);
	}

}

void postorder(char node) { //���� ��ȸ
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
		cin >> ch; //A �ƽ�Ű�ڵ�: 65

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