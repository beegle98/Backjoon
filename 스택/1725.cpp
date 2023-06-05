#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n,v[100005],sum=0,MAX=0;

stack<pair<ll,ll>> s;
void MaxArea(ll k){

    ll end=s.top().second;
    ll area,h,w;
    while(!s.empty() && s.top().first>k){
        h = s.top().first;
        w = (end-s.top().second+1);
        s.pop();
        if(!s.empty()){
            w = end - s.top().second;
        }
        area = h * w;
        if(MAX < area) MAX = area;
    }
}
void solve(){
    s.push({0,0});
    for(int i=1;i<=n;i++){
        if(s.top().first>v[i]){
            MaxArea(v[i]);
            s.push({v[i],i});
        }
        else{
            s.push({v[i],i});
        }
    }
    if (!s.empty()){
        MaxArea(0);
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n;
    
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }
    
    solve();
    // 스택은 오름차순으로만 정렬
    // 마지막 수보다 작은 수가 나오면 현재 수보다 큰 수들은 스택에서 제거
    // 하나씩 제거하면서 최대 넓이 계산

    cout << MAX << '\n';
    
    return 0;
}