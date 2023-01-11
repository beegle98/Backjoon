#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <map>
#include <set>
using namespace std;

typedef long long ll;

#define INF 1987654321
int n,m;
int s[555][555];
int visited[555][555];
ll sum=0;
void print(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout << visited[i][j] << " ";
        }
        cout << '\n';
    }
}
int dfs(int x,int y){
    if(visited[x][y] >=1 || (x==n && y==m)){
        sum+=visited[x][y];
        return visited[x][y];
    }
    else if(visited[x][y]==0) return 0;
    else{
        int ret=0;
        if(s[x-1][y]<s[x][y] && x-1 >= 1){
            ret += dfs(x-1,y);
            //cout << "in x-1: " << x << y << ':' <<ret << '\n';
        }
        if(s[x+1][y]<s[x][y] && x+1 <= n){
            ret += dfs(x+1,y);
            //cout << "in x+1: " << x << y << ':' <<ret << '\n';
        }
        if(s[x][y-1]<s[x][y] && y-1 >= 1){
            ret += dfs(x,y-1);
            //cout << "in y-1: " << x << y << ':' <<ret << '\n';
        }
        if(s[x][y+1]<s[x][y] && y+1 <= m){
            ret += dfs(x,y+1);
            //cout << "in y+1: " << x << y << ':' <<ret << '\n';
        }
        visited[x][y]=ret;
       // cout << x << ":" << y << " " << ret << '\n';
        
    }
    return visited[x][y];
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> s[i][j];
            visited[i][j]=-1;
        }
    }
    visited[n][m]=1;
    dfs(1,1);
    cout << sum;
    return 0;
}
