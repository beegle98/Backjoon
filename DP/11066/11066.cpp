#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <map>
#include <set>
using namespace std;

typedef long long ll;


int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    ll sum=0;
    int T,n,x;
    int dp[501][501];

    cin >> T;
    for(int k=0;k<T;k++){
        cin >> n;
        for(int i=0;i<n;i++){
            int x;
            cin >> dp[i][i];
        }
        for(int i=0;i<n;i++){
            
        }
        cout << sum << '\n';
    }
    return 0;
    https://gist.github.com/injae-kim/2b419af2a077ae6b24007a8458850df7
}