#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a,b,c;

    cin >> a >> b >>c;
    if(a==b && b==c) cout << 10000+a*1000;
    else if(a==b) cout << 1000+a*100;
    else if(b==c) cout << 1000+b*100;
    else if(c==a) cout << 1000+c*100;
    else{
        int MAX;
        MAX=max(max(a,b),c);
        cout << 100*MAX;
    }
    return 0;
}
