#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
struct compare {
	bool operator()(int a, int b) {
		if (abs(a) == abs(b)) {
			return a > b;
		}
		else return abs(a) > abs(b);

	}
};
int main() {
	priority_queue<int, vector<int>, compare> pq;
	int x,n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (x == 0) {
			if (pq.empty()) printf("0\n");
			else {
				printf("%d\n", pq.top());
				pq.pop();
			}
		}
		else pq.push(x);
	}
	return 0;
}