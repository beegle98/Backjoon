#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

const int N=300300;


ll solve(){
    ll sum=0, R; cin >> R;
    ll x=1;
    for(ll y=R-1;y>=0;y--){
        while(x*x+y*y < R*R){
            x++;
        }
        sum+=x-1;
    }
    sum*=4;
    sum++;

    return sum;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int T, test_case;
    
    cin >> T;
    
	for(test_case = 0; test_case  < T; test_case++)
	{   
        ll ans;
        ans = solve();
        cout << "Case #" << test_case+1 << '\n' << ans << '\n';
	}

    

    return 0;
}