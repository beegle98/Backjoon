#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

multimap<int,int> mx,my;
int n;
ll sum;

void solve(){
    cin >> n;
    
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        mx.insert({x,y});
        my.insert({y,x});
    }
    
    

    int p=0,cnt;
    for(auto i=mx.begin();i!=mx.end();advance(i,cnt)){
        cnt=mx.count(i->first);

        cout << "count : " << cnt << '\n';
        
    }
    sum=0;

    
    cout << sum << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        mx.clear();
        my.clear();
        solve();
		cout << "Case #" << test_case+1 << endl << sum << endl;
	}

    return 0;
}