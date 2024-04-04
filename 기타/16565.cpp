#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

const int MOD = 10007;
int nCk[60][60];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i=0;i<=52;i++){
        nCk[i][0]=1;
        nCk[i][i]=1;
    }
    int n;
    cin >> n;
    for(int i=1;i<=52;i++){
        for(int j=1;j<i;j++){
            nCk[i][j] = (nCk[i-1][j]+nCk[i-1][j-1]) % MOD;
        }
    }
    int ans=0;
    for(int i=4;i<=n;i+=4){
        if((i/4)%2==1) ans += nCk[13][i/4] * nCk[52-i][n-i];
        else ans -= nCk[13][i/4] * nCk[52-i][n-i];
        ans %= MOD;
    }
    if(ans<0) ans+=MOD;
    cout << ans <<'\n';
    return 0;
}
