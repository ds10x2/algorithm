#include <iostream>
using namespace std;

int n;
int inorder[100001];
int postorder[100001];
int Index[100001];

//후위순회에 마지막에 방문하는  것이 루트 

void getPreorder(int inStart, int inEnd, int postStart, int postEnd) {
	if (inStart > inEnd || postStart > postEnd) 
		return;
	
	int root = Index[postorder[postEnd]];
	int leftSize = root - inStart;
	int rightSize = inEnd - root;
	cout << inorder[root] << ' ';

	getPreorder(inStart, root - 1, postStart, postStart + leftSize - 1);
	getPreorder(root + 1, inEnd, postStart + leftSize, postEnd - 1);
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	
	cin >> n;

	for (int i =1 ; i <= n; i++) {
		cin >> inorder[i];
		Index[inorder[i]] = i;
	}

	for (int i = 1; i <= n; i++) {
		cin >> postorder[i];
	}

	getPreorder(1, n, 1, n);


	return 0;
}