#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

const int N =100100;
vector<pair<ll,ll>> v,s;

void solve(){
    int n; cin >> n;

    for(int i=0;i<n;i++){
        int x,y; cin >> x >> y;
        v.push_back({x,y});
    }
    int k;cin >> k;
    ll Min;
    for(int i=0;i<k;i++){
        int a,b;
        cin >> a >> b;
        ll area = (v[a+1].first-v[a].first) * (v[a+1].second+v[a].second);
        Min = area;
        if(v[a-1].second<v[a].second) s.push_back(v[a-1]);
        s.push_back(v[a]);
        //stack(a,b);
        int m;
        for(int j=a+1;j<b;j++){
            //MinArea
            m=s.size()-1;
            while(m>=0 && s[m].second >= v[j].second){
                area = (v[j].first-s[m].first) * (v[j].second+s[m].second);
                if(Min > area) Min = area;
                s.pop_back();
                m--;
            }
            area = (v[j].first-s[m].first) * (v[j].second+s[m].second);
            if(Min > area) Min = area;
            s.push_back(v[j]);
            
        }
        m = s.size()-1;
        
        for(int j=m-1;j>=0;j--){
            area = (s[m].first-s[j].first) * (s[m].second+s[j].second);
            if(Min > area) Min = area;
        }
        s.clear();
        cout << Min <<'\n';
    }
    v.clear();
    
    return;
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
        
		cout << "Case #" << test_case+1 << '\n';
        solve();
	}

    return 0;
}