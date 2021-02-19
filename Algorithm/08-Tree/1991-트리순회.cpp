// 트리 순회
/*
# SOLUTION

[배열 index]
배열의 index는 0부터 시작하므로, 
character(A-Z)를 배열의 index로 사용하려면 
character - 'A' 한 값을 인덱스로 넣어야 한다.
*/

#include <iostream>
using namespace std;
#define MAX 26


struct NODE {
	int left_child = -1, right_child = -1;
};

int N;
struct NODE tree[MAX];

void preorder(char root) {
	cout << root;
	if (tree[root - 'A'].left_child != -1) preorder(tree[root - 'A'].left_child);
	if (tree[root - 'A'].right_child != -1) preorder(tree[root - 'A'].right_child);
}

void inorder(char root) {
	if (tree[root - 'A'].left_child != -1) inorder(tree[root - 'A'].left_child);
	cout << root;
	if (tree[root - 'A'].right_child != -1) inorder(tree[root - 'A'].right_child);
}

void postorder(char root) {
	if (tree[root - 'A'].left_child != -1) postorder(tree[root - 'A'].left_child);
	if (tree[root - 'A'].right_child != -1) postorder(tree[root - 'A'].right_child);
	cout << root;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	char node, left, right;
	for (int i = 1; i <= N; i++) {
		cin >> node >> left >> right;
		if (left != '.') tree[node - 'A'].left_child = left;
		if (right != '.') tree[node - 'A'].right_child = right;
	}

	preorder('A');
	cout << '\n';
	inorder('A');
	cout << '\n';
	postorder('A');
}