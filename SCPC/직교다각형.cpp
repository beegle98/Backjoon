#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll sum;

void solve(){

    int n;
    cin >> n;
    map<int,int> mx,my;
    vector<pair<int,int>> vx;

    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        vx.push_back({x,y});
        mx[x]^=1;
        my[y]^=1;
    }
    for(int i=0;i<n;i++){
        if(mx[vx[i].first] && my[vx[i].second]){
            n--;
            vx.erase(vx.begin()+i);
            break;
        }
    }


    sum=0;
    sort(vx.begin(),vx.end());
    for(int i=0;i<n;i+=2){
        sum += vx[i+1].second - vx[i].second;
    }
    for(pair<int,int> &p : vx) swap(p.first, p.second);
    sort(vx.begin(),vx.end());
    for(int i=0;i<n;i+=2){
        sum += vx[i+1].second - vx[i].second;
    }
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
        solve();
		cout << "Case #" << test_case+1 << endl << sum << endl;
	}

    return 0;
}