#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, m, k;
/*
n : ���� ����
m : ������ �Ͼ�� Ƚ��
k : ������ ���� ���ϴ� Ƚ��
*/

vector<long long> arr;

long long Init(vector<long long>& arr, vector<long long>& tree, int node, int start, int end) {
	if (start == end) //��尡 ���� ����� ���
		return tree[node] = arr[start]; 

	int mid = (start + end) / 2;

	//���� ���� ���ϴ� ���
	return tree[node] = Init(arr, tree, node * 2, start, mid) + Init(arr, tree, node * 2 + 1, mid + 1, end);
}

long long Sum(vector<long long>& tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];
	
	int mid = (start + end) / 2;
	return Sum(tree, node * 2, start, mid, left, right) + Sum(tree, node * 2 + 1, mid + 1, end, left, right);

}

void Update(vector<long long>& tree, int node, int start, int end, int index, long long diff) {
	if (index < start || index > end) return;
	tree[node] = tree[node] + diff;

	if (start != end) {
		int mid = (start + end) / 2;
		Update(tree, node * 2, start, mid, index, diff);
		Update(tree, node * 2 + 1, mid + 1, end, index, diff);
	}
}


int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n >> m >> k;

	//�� �Է� �ޱ�
	for (int i = 0; i < n; i++) {
		long long x;
		cin >> x;
		arr.push_back(x);
	}

	int h = ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<long long> tree(tree_size);

	Init(arr, tree, 1, 0, n - 1);

	for (int i = 0; i < m + k; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		/*
		a�� 1�� ���, b��° ���� c�� �ٲ�
		a�� 2�� ���, b��° ������ c��° �������� ���� ���Ͽ� ���
		*/

		if (a == 1) {
			Update(tree, 1, 0, n - 1, b - 1, c - arr[b-1]);
			arr[b - 1] = c;
		}
		else if (a == 2) {
			long long result = Sum(tree, 1, 0, n - 1, b-1, c-1);
			cout << result << "\n";
		}
	}

	return 0;
}