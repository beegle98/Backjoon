#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

const int N=300300;

vi t, s[N];
int n;

void build(){
    for(int i = n-1; i>0 ;i--) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p,int value){
    for(t[p+=n] += value; p > 1; p >>=1) t[p>>1] = t[p] + t[p^1];
}
ll sum_query(int l,int r){// sum on interval [l,r)
    ll res = 0;
    for(l += n, r += n; l<r; l >>=1, r>>=1){
        if(l&1) res+=t[l++];
        if(r&1) res+=t[--r];
    }
    return res;
}

ll solve(){
    ll Sum=0;
    vector<pair<int,int>> arr;
    cin >> n;
    t = vi(2*(n+10));

    for(int i=0;i<n;i++){
        int x; cin >> x;
        s[x].push_back(i);
    }
    for(int i=1;i<=n;i++){
        int size=s[i].size();
        int l=0, r=size-1;
        while(size>1){
            //cout << i << " : " << l << ", "<<r<<'\n';
            size-=2;
            arr.push_back({s[i][l],s[i][r]});
            Sum += s[i][r]-s[i][l];
            l++;
            r--;
        }
    }
    sort(arr.begin(), arr.end(), [&](pair<int, int> a, pair<int, int> b)
         { return a.second - a.first > b.second - b.first; });
    
    for(int i=0;i<arr.size();i++){
        //cout << arr[i].first << " : " << arr[i].second << '\n';

        Sum += sum_query(arr[i].first,arr[i].second+1);
        modify(arr[i].first,-1);
        modify(arr[i].second,-1);
    }

    for(int i=1;i<=n;i++){
        s[i].clear();
    }


    return Sum;
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