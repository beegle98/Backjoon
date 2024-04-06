//이항계수와 쿼리
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

const int N=4000004;
const ll MOD=1e9+7;

ll Pow(ll a,ll b){
    ll res=1;
    for(;b;b/=2, a = a * a % MOD) if(b & 1) res = res * a % MOD;
    return res;
}
ll fact[N];
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int m,n,k;
    cin >> m;
    fact[0]=1;
    for(int i=1;i<N;i++) fact[i] = fact[i-1] * i % MOD;
    
    for(int i=0;i<m;i++){
        int n,k; cin >> n >> k;
        ll a = fact[k] * fact[n-k] % MOD;
        cout << fact[n] * Pow(a,MOD-2) % MOD << '\n';
    }

    return 0;

}