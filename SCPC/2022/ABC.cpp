#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int n, m, k;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int T, test_case;
    ll Ans;

    cin >> T;
    

	for(test_case = 0; test_case  < T; test_case++)
	{
        
        cin >> n >> m >> k;
        
        Ans=1;
        
        
        cout << "Case #" << test_case+1 << '\n' << Ans << '\n';
	}
    return 0;
}