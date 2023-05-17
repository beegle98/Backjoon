#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n,w;
vector<pair<int,int>> pathA,pathB;

int dp[1001][1001];
void minpath(int x,int y){

}
void solve(){
    minpath(0,0);// 최소 길이 구하는 함수
    //path출력 함수 추가
}

int dist(pair<int,int> a, pair<int,int> b){
    return abs(a.first-b.first) + abs(a.second-b.second);
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

    solve();

    return 0;
}