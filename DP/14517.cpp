//팰린드롬 개수 구하기 (Large)
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

const int MOD = 10007;
const int N = 1001;
int dp[N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string s;
    cin >> s;
    int n = s.length();
    for(int i=0;i<n;i++){
        dp[i][i]=1;
    }
    for(int i=1;i<n;i++){
        dp[i-1][i]=2;
        if(s[i-1]==s[i]) dp[i-1][i]++;
    }
    for(int i=2;i<n;i++){
        for(int j=i;j<n;j++){
            if(s[j-i]==s[j]) dp[j-i][j] = (dp[j-i+1][j] + dp[j-i][j-1] + 1) % MOD;
            else dp[j-i][j] = (dp[j-i+1][j] + dp[j-i][j-1] - dp[j-i+1][j-1] + MOD) % MOD;
        }
    }
    cout << dp[0][n-1] << '\n';
    return 0;
}
