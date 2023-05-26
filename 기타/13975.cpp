#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <map>
#include <set>
using namespace std;

typedef long long ll;

priority_queue<ll,vector<ll>,greater<ll>> pq;
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    ll sum=0;
    int T,n,x;
    cin >> T;
    for(int k=0;k<T;k++){
        cin >> n;
        while(!pq.empty()) pq.pop();
        for(int i=0;i<n;i++){
            cin >> x;
            pq.push(x);
        }
        sum=0;
        for(int i=0;i<n-1;i++){
            //cout << pq.top() << ' ';
            //pq.pop();
            ll a,b;
            a=pq.top();
            pq.pop();
            b=pq.top();
            pq.pop();
            //cout << a << ',' << b << ' ';
            b+=a;
            sum+=b;
            
            pq.push(b);
        }
        cout << sum << '\n';
    }
    

    return 0;
}