#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <map>
#include <set>
using namespace std;

typedef long long ll;

#define INF 1987654321
int n,m;
int s[501][501];
bool visited[501][501];


int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> s[i][j];
        }
    }
    return 0;
}