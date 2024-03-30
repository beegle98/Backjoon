#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int n,m,b,sum=0,s[501][501];
    cin >> n >> m >> b;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> s[i][j];
            sum+=s[i][j];
        }
    }
    int Max,Min=1234567890,hMax=0;
    Max = (sum+b)/(n*m);

    for(int h=Max;h>=0;h--){
        sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(h<s[i][j]) sum+=(s[i][j]-h)*2;
                else sum+=(h-s[i][j]);
            }
        }
        if(Min>sum){
            Min = sum;
            hMax=h;
        }
    }
    cout << Min << ' ' << hMax;
    return 0;

}
