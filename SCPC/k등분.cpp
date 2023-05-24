#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=500005;
const ll MOD=1e9+7;
ll dp[N],v[N],s[N];
ll Fac[N],Inv[N];
ll n,k;
ll Pow(ll a,ll b){
    ll res=1;
    for(;b;b/=2, a = a * a % MOD) if(b & 1) res = res * a % MOD;
    return res;
}
ll Comb(int n, int r){ return r <= n ? Fac[n] * Inv[r] % MOD * Inv[n-r] % MOD : 0 ; }

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    // aM 일때 dp[a]+=dp[a-1]
    // dp[k-1]이 정답
    

    int T, test_case;
    ll m, x, Answer;
    cin >> T;
    Fac[0]=1;
    for(int i=1;i<N;i++){Fac[i]=Fac[i-1] * i % MOD;}
    Inv[N-1]=Pow(Fac[N-1],MOD-2);
    for(int i=N-2;i>=0;i--){Inv[i]=Inv[i+1]*(i+1)%MOD;}

	for(test_case = 0; test_case  < T; test_case++)
	{
        memset(dp,0,sizeof(dp));
        cin >> n >> k;
        for(int i=1;i<=n;i++){
            cin >> v[i];
            s[i]=s[i-1]+v[i];
        }
        if(s[n]%k!=0){
            cout << "Case #" << test_case+1 << endl << "0" << endl;
            continue;
        }                                   
        m=s[n]/k;
        dp[0]=1;
        if(m==0){
            // M==0 이면 0 개수 (x)C(k-1)
            
            x=0;
            for(int i=1;i<n;i++){
                if(s[i]==0) x++;

                Answer = Comb(x,k-1);
            }
        }
        else{
            // aM 이면 dp[a]+=dp[a-1];
            for(int i=1;i<=n;i++){
                if(s[i]%m) continue;
                if(s[i]/m<=k && s[i]/m>=1){
                    x=s[i]/m;
                    dp[x]= (dp[x] + dp[x-1]) % MOD;
                }
            }
            Answer = dp[k-1];
        }
        
        cout << "Case #" << test_case+1 << endl << Answer << endl;
	}
    return 0;
}