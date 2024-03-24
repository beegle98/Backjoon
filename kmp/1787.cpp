#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;


vi getPi(string p){
    int m = (int)p.size(), j=0;
    vi pi(m, 0);
    for(int i = 1; i< m ; i++){
        while(j > 0 && p[i] !=  p[j])
            j = pi[j-1];
        if(p[i] == p[j])
            pi[i] = ++j;
    }
    return pi;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int n;
    ll ans=0;
    string s;
    cin >> n >> s;
    vi dp(n,0);
    auto pi = getPi(s);

    for(int i=0;i<n;i++){
        if(!pi[i])continue;
        dp[i] = (pi[pi[i]-1] > 0 ? dp[pi[i]-1] : pi[i]);
        if(!dp[i]) continue;
        ans += i+1 - dp[i];
        
    }
    
    cout << ans;
    return 0;
}

