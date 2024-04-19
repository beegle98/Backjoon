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
    cin >> a >> b >> c;
    int h,m,tmp;
    m=(b+c)%60;
    tmp=(b+c)/60;
    h=(a+tmp)%24;
    cout << h << ' ' << m <<'\n';
    return 0;
}
