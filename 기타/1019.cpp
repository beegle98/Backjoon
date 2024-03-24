//책 페이지
#include <bits/stdc++.h>

using namespace std;
#define MAX 1234567890

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

ll dp[11][11];
ll ans[11];

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    ll n;
    cin >> n;
    
    dp[1][0]=0;
    for(int i=1;i<=10;i++){
        dp[1][i]=1;
    }
    ll tmp=1;
    for(int i=2;i<=10;i++){
        tmp*=10;
        dp[i][0]=dp[i-1][1]*9+dp[i-1][0];
        for(int j=1;j<10;j++){
            dp[i][j]=i*tmp;
            
        }
        
    }
    /*
    for(int i=1;i<=n;i++){
        int tmp=i;
        while(tmp){
            ans[tmp%10]++;
            tmp/=10;
        }
    }
    for(int i=0;i<10;i++){
        cout << ans[i] << ' ';
    }*/
    ll total=0;
    ll sum=0;
    int r;
    tmp=1;
    ll m = n;
    for(int i=1;i<=10;i++){
        r=n%10;
        n/=10;

        ans[r]+=sum+1;
        for(int j=1;j<r;j++){
            ans[j]+=tmp;
        }
        for(int j=1;j<10;j++){
            ans[j]+=dp[i-1][1]*r;
        }
        if(n==0){
            total+=i*(m-tmp+1);
            for(int j=0;j<10;j++){
                total+=dp[i-1][j];
            }
            break;
        }
        
        sum+=r*tmp;
        tmp*=10;
    }
    ans[0]=total;
    for(int i=1;i<10;i++){
        ans[0]-=ans[i];
    }
    for(int i=0;i<10;i++){
        cout << ans[i] << ' ';
    }
    
    return 0;
}
