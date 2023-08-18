#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

const int N=8;

ll k, dx[8]={0,0,1,2,3,3,2,1}, dy[8]={0,1,2,2,1,0,-1,-1};
vll v;

ll solve(){
    cin >> k;
    v = vll(8);

}

int main(){// next_permutation 순열 STL 사용
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