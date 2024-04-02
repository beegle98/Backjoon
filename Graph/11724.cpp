//연결 요소의 개수
#include <bits/stdc++.h>

using namespace std;
#define MAX 1234567890

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

vi s[1011];
bool visited[1011];

void dfs(int v){
    if(visited[v]) return;
    visited[v]=true;
    for(int i=0;i<s[v].size();i++){
        dfs(s[v][i]);
    }
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int x,y; cin >> x >> y;
        s[x].push_back(y);
        s[y].push_back(x);
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i);
            sum++;
        }
    }
    cout << sum;
    return 0;
}
