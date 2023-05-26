#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n,s[200][200],sum[2];


void solve(int x1, int y1,int x2,int y2){
    if (x1==x2){
        sum[s[x1][y1]]++;
        return;
    }
    int cnt=0;
    for(int i=x1;i<=x2;i++){
        for(int j=y1;j<=y2;j++){
            cnt+=s[i][j];
        }
    }
    if(cnt==0){
        sum[0]++;
        return;
    }
    else if(cnt==(x2-x1+1)*(y2-y1+1)){
        sum[1]++;
        return;
    }
    else{
        int x3=(x1+x2)/2;
        int y3=(y1+y2)/2;
        solve(x1,y1,x3,y3);
        solve(x1,y3+1,x3,y2);
        solve(x3+1,y1,x2,y3);
        solve(x3+1,y3+1,x2,y2);
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

    cout << sum[0] << '\n' << sum[1];
    
    return 0;
}