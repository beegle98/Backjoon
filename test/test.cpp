#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

int n,dp[50010];

void f(int p){
    int min=4,t;
    t=(int)sqrt(p);
    for(int i=t;i>=1;i--){
        if(min>dp[i*i]+dp[p-(i*i)]) min = dp[i*i]+dp[p-(i*i)];
    }
    dp[p]=min;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i=1;i<=223;i++){
        dp[i*i]=1;
    }
    int n; cin >> n;
    for(int i=1;i<=n;i++){
        if(!dp[i]) f(i);
    }
    cout << dp[n];
    return 0;
}
