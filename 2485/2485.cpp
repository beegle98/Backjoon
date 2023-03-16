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

int n,s[100001];

int gcd(int a,int b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n;
    cin >> s[0] >> s[1];
    int g=s[1]-s[0];
    for(int i=2;i<n;i++){
        cin >> s[i];
        g=gcd(g,s[i]-s[i-1]);
    }
    //cout << g;
    int sum=0;
    for(int i=1;i<n;i++){
        sum += (s[i]-s[i-1])/g - 1;
    }
    cout << sum;
    return 0;
}