#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<pair<int,int>> vx,vy;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        vx.push_back({x,y});
        vy.push_back({y,x});
    }

    sort(vx.begin(),vx.end());
    sort(vy.begin(),vy.end());
    
    ll sum=0;

    for(int i=0;i<vx.size();i+=2){
        sum += vx[i+1].second - vx[i].second;
        sum += vy[i+1].second - vy[i].second;
    }
    cout << sum;
    return 0;
}