#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
int main() {
	priority_queue<int, vector<int>, less<int>> pq;
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