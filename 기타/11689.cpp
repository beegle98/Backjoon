#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n,ans,num;
    cin >> n;
    ans = n; num = n;
    for(ll i=2;i*i<=n;i++){
        if(num%i==0){
            ans = ans - ans/i;
            while(num%i==0) num/=i;
        }
    }
    if(num>1) ans = ans - ans/num;
    cout << ans << '\n';
    return 0;
}
