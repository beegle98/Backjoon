#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long ll;

int n,v[1000001];
ll m;

bool check(int mid){
    ll sum=0;
    for(int i=0;i<n;i++){
        if (v[i] > mid) sum+=v[i]-mid;
    }
    return sum >= m;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    sort(v,v+n);
    
    int l=0,h=v[n-1];

    while(l+1<h){
        int mid = (l+h)/2;
        if(check(mid)) l=mid;
        else h=mid;
    }
    cout << l << '\n';
    return 0;
}