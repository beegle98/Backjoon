#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD=1e9+7;

ll h[2][2]=
{{0,1}
,{1,1}};

ll k[2][2]=
{{1,0}
,{0,1}};
void Matrix(ll b[][2]){
    ll tmp[2][2];
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            tmp[i][j]=(k[i][0]*b[0][j])%MOD+(k[i][1]*b[1][j])%MOD;
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            k[i][j]=tmp[i][j]%MOD;
        }
    }
}
void solve(ll n){
    if(n==0) return;
    if(n&1){
        solve(n-1);
        Matrix(h);
        
    }
    else{
        solve(n/2);
        Matrix(k);
        
    }
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    ll n;
    cin >> n;

    solve(n);
    cout << k[1][0];
    return 0;
}