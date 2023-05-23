#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=500005;
const ll MOD=1e9+7;
ll dp[N],v[N],s[N];
ll Fac[N],Inv[N];
int n,k;

ll comb(int n, int r){ return r > n ? 0 : Fac[n] * Inv[r] % MOD * Inv[n-r] % MOD; }

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    // aM 일때 dp[a]+=dp[a-1]
    // dp[k-1]이 정답
    

    int T, test_case;
    ll sum=0, m, x, Answer;
    cin >> T;
    Fac[0]=1;
    for(int i=1;i<N;i++){Fac[i]=Fac[i-1] * i % MOD;}
    for(int i=0;i<N;i++){}
	for(test_case = 0; test_case  < T; test_case++)
	{
        cin >> n >> k;
        sum=0;
        cin >> v[0];
        s[0]=v[0];
        for(int i=1;i<n;i++){
            cin >> v[i];
            s[i]=s[i-1]+v[i];
        }
        if(s[n-1]%k!=0){
            cout << "Case #" << test_case+1 << endl << "0" << endl;
            continue;
        }
        m=s[n-1]/k;
        dp[0]=1;
        if(m==0){
            // M==0 이면 0 개수 (x)C(k-1)
            
            x=0;
            for(int i=0;i<n;i++){
                if(s[i]==0) x++;
                Answer = comb(x,k-1);
            }
        }
        else{
            for(int i=0;i<n;i++){
                if(s[i]%m==0 && s[i]/m>0){
                    x=s[i]/m;
                    dp[x]+=dp[x-1];
                }
            }
            Answer = dp[k-1];
        }
        // aM 이면 dp[a]+=dp[a-1];
        cout << "Case #" << test_case+1 << endl << Answer << endl;
	}
    return 0;
}