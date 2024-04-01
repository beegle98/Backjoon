//쉬운 최단거리
#include <bits/stdc++.h>

using namespace std;
#define MAX 1234567890

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

queue<pair<int,pair<int,int>>> q;
int n,m,s[1011][1011], len[1011][1011];
int d[4][2]={{0,-1},{1,0},{0,1},{-1,0}};
bool visited[1011][1011];

void bfs(int l,int x,int y){
    if(x<0 || x>=n || y<0 || y>=m) return;
    if(visited[x][y] || s[x][y]==0) return;
    visited[x][y]=true;
    len[x][y]=l;
    for(int i=0;i<4;i++){
        q.push({l+1,{x+d[i][0],y+d[i][1]}});
    }
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int x,y;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            len[i][j]=-1;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> s[i][j];
            if(s[i][j]==2){
                x=i;
                y=j;
            }
            else if(s[i][j]==0){
                len[i][j]=0;
            }
        }
    }
    q.push({0,{x,y}});
    while(!q.empty()){
        pair<int,pair<int,int>> tmp;
        tmp = q.front();
        q.pop();
        bfs(tmp.first,tmp.second.first,tmp.second.second);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << len[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
