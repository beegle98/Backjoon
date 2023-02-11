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

int n,s[1001],dp[1001];


int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n;
    int Max=0;
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(s[i]<s[j] && dp[i]<=dp[j]) dp[i]=dp[j]+1;
        }
        if(Max < dp[i]) Max=dp[i];
    }
    cout << Max+1;
    return 0;
}