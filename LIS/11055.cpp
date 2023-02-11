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
    for(int i=0;i<n;i++){
        dp[i]=s[i];
        for(int j=i-1;j>=0;j--){
            if(s[i]>s[j] && dp[i]<dp[j]+s[i]) dp[i]=dp[j]+s[i];
        }
        if(Max < dp[i]) Max=dp[i];
    }
    cout << Max;
    return 0;
}