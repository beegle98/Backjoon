#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

queue<pi> q;

int n,m,ans=-1;
char s[11][11];

void bfs(pi R, pi B){

}

int main(){
    FASTIO
    cin >> n >> m;
    pi r,b;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> s[i][j];
            if(s[i][j]=='R'){
                r.first=i;
                r.second=j;
                s[i][j]='.';
            }
            else if(s[i][j]=='B'){
                b.first=i;
                b.second=j;
                s[i][j]='.';
            }
        }
    }
    int cnt=10;
    while(cnt--){

    }
    cout << ans << '\n';
    return 0;

}