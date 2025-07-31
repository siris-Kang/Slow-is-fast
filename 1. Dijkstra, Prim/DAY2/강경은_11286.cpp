#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct Compare {
	bool operator()(int a, int b) {
		if (abs(a) == abs(b))
			return a > b;
		return abs(a) > abs(b);
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, input;
	cin >> N;

	priority_queue<int, vector<int>, Compare> pque;
	while (N--) {
		cin >> input;
		if (input != 0) {
			pque.push(input);
		}
		else {
			if (pque.size() == 0)
				cout << 0 << "\n";
			else {
				cout << pque.top() << "\n";
				pque.pop();
			}
		}
	}

	return 0;
}