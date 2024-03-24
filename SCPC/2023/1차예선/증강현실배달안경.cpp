#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll sum;

void solve(){
    int n, a, b;

    cin >> n >> a >> b;
    if (a > b) swap(a,b);
    
    sum=0;
    while(n>0){
        if(n%a==0){
            sum+= n/a;
            n=0;
            break;
        }
        n-=b;
        sum++;
    }
}

int main()//만점
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        solve();
		cout << "Case #" << test_case+1 << '\n' << sum << '\n';
	}

    return 0;
}