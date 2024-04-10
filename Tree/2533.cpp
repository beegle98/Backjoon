//사회망 서비스
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

const int N = 1000001;
vi e[N];
int dp[N][2]; // 0=일반인 1=어답터
bool visited[N];

void f(int v){
    visited[v]=true;
    dp[v][1]=1;
    for(int i=0;i<e[v].size();i++){
        int w=e[v][i];
        if(visited[w]) continue;
        f(w);
        dp[v][0]+=dp[w][1];
        dp[v][1]+=min(dp[w][0],dp[w][1]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >>n;
    int u,v;
    for(int i=0;i<n-1;i++){
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    f(1);
    cout << min(dp[1][0],dp[1][1]) <<'\n';
    return 0;
}
