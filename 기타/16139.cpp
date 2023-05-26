#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long ll;

int n, sum[30][220000];
char c;
string s;
int main() {
	int x, y;

	getline(cin,s);
	scanf("%d", &n);
	
	for (int i = 1; i <= s.size(); i++) {
		for (int j = 0; j < 26; j++) {
			sum[j][i] = sum[j][i - 1];
		}
		sum[s[i - 1] - 'a'][i] ++;
	}
	
	while(n--){
		scanf("%c %c %d %d",&c, &c, &x, &y);
		printf("%d\n", sum[c - 'a'][y+1] - sum[c - 'a'][x]);
	}

	return 0;
}