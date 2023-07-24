#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, m, k;
/*
n : 수의 개수
m : 변경이 일어나는 횟수
k : 구간의 합을 구하는 횟수
*/

vector<long long> arr;

long long Init(vector<long long>& arr, vector<long long>& tree, int node, int start, int end) {
	if (start == end) //노드가 리프 노드인 경우
		return tree[node] = arr[start]; 

	int mid = (start + end) / 2;

	//구간 합을 구하는 경우
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

	//수 입력 받기
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
		a가 1인 경우, b번째 수를 c로 바꿈
		a가 2인 경우, b번째 수부터 c번째 수까지의 합을 구하여 출력
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