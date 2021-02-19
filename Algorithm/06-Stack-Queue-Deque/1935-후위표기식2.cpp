// ���� ǥ���2
#include <iostream>
#include <string>
#include <stack>
using namespace std;
#define MAX 26


int N;
string postfix;
int operand[MAX + 1];
int x;
double a, b, c;	// float�� �ϸ� Ʋ��
stack<double> s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cout << fixed;
	cout.precision(2);	// �Ҽ��� 2�ڸ����� ���

	cin >> N;

	cin >> postfix;

	for (int i = 0; i < N; i++) {
		cin >> operand[i];
	}

	int k = 0;
	for (int i = 0; i < postfix.length(); i++) {
		x = postfix[i];
		if (x >= 65 && x <= 122) {	// �빮�� ASCII
			s.push(operand[x-65]);
		}
		else {
			b = s.top();
			s.pop();
			a = s.top();
			s.pop();
			
			switch (x) {
			case '+':
				c = a + b;
				break;
			case '-':
				c = a - b;
				break;
			case '*':
				c = a * b;
				break;
			case '/':
				c = a / b;
				break;
			}

			s.push(c);
		}
	}

	cout << s.top();
}
