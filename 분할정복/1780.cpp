#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n,sum[3],s[3333][3333];

void solve(int x1, int y1,int x2,int y2){
    if (x1==x2){
        if(s[x1][y1]==-1) sum[2]++;
        else sum[s[x1][y1]]++;
        return;
    }
    int cnt[3]={0,0,0};
    for(int i=x1;i<=x2;i++){
        for(int j=y1;j<=y2;j++){
            if(s[i][j]==-1) cnt[2]++;
            else cnt[s[i][j]]++;
        }
    }
    int area=(x2-x1+1)*(y2-y1+1);
    for(int i=0;i<3;i++){
        if(cnt[i]==area){
            sum[i]++;
            return;
        }
    }
    
    int dx=(x2-x1+1)/3;
    int dy=(y2-y1+1)/3;

    for(int i=0;i<3;i++){
        int x3=x1+dx*i;
        for(int j=0;j<3;j++){
            int y3=y1+dy*j;
            solve(x3,y3,x3+dx-1,y3+dy-1);
        }
    }
    
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> s[i][j];
        }
        
    }
    
    solve(1,1, n,n);
    cout << sum[2] << '\n' << sum[0] << '\n' << sum[1];

    
    return 0;
}