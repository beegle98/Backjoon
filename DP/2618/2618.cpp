#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n,w;
vector<pair<int,int>> pathA,pathB;

int dp[1001][1001];
int p[1001][1001];

int dist(pair<int,int> a, pair<int,int> b){
    return abs(a.first-b.first) + abs(a.second-b.second);
}
void printPath(int a,int b){
    if(a==w||b==w) return;

    cout << p[a][b] << '\n';

    int x=max(a,b)+1;

    if(p[a][b]==1) printPath(x,b);
    else printPath(a,x);

}
int minpath(int a,int b){
    
    if(a==w||b==w){
        return 0;
    }
    if(dp[a][b]!=-1) return dp[a][b];
    int x;
    x=max(a,b)+1;
    //cout << a << "," << b << ": ";
    //cout << dist(pathA[a],pathA[x])<< ','<< dist(pathB[b],pathB[x]) << '\n';
    int pA=minpath(x,b)+dist(pathA[a],pathA[x]);
    int pB=minpath(a,x)+dist(pathB[b],pathB[x]);
    if( pA<pB){
        p[a][b]=1;
        return dp[a][b]=pA;
    }
    else{
        p[a][b]=2;
        return dp[a][b]=pB;
    }
}
void solve(){
    cout << minpath(0,0) << '\n';// 최소 길이 구하는 함수
    printPath(0,0);
}


int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n >> w;
    int x,y;
    pathA.push_back({1,1});
    pathB.push_back({n,n});
    for(int i=1;i<=w;i++){
        cin >> x >> y;
        pathA.push_back({x,y});
        pathB.push_back({x,y});
    }
    memset(dp,-1,sizeof(dp));
    solve();

    return 0;
}