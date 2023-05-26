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

ll a1,a2,b1,b2;
ll x,y;
int gcd(int a,int b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> a1 >> b1;
    cin >> a2 >> b2;

    x=a1*b2+a2*b1;
    y=b1*b2;

    ll g=gcd(x,y);
    cout << x/g << ' ' << y/g;
    
    return 0;
}