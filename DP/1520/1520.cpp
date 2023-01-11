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
bool visited[555][555];
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
    cout << x << " : " << y <<'\n';
    if(visited[x][y]>=1 || (x==n && y==m)){
        cout << x << " " << y << '\n';
        print();
        sum++;
        return 1;
    }
    else{
        if(s[x-1][y]<s[x][y] && x-1 >= 1){
            if(dfs(x-1,y)) visited[x][y]=1;
        }
        if(s[x+1][y]<s[x][y] && x+1 <= n){
            if(dfs(x+1,y)) visited[x][y]=1;
        }
        if(s[x][y-1]<s[x][y] && y-1 >= 1){
            if(dfs(x,y-1)) visited[x][y]=1;
        }
        if(s[x][y+1]<s[x][y] && y+1 <= m){
            if(dfs(x,y+1)) visited[x][y]=1;
        }
        
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
        }
    }
    dfs(1,1);
    cout << sum;
    return 0;
}