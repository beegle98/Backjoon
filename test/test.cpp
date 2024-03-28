#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

int p(string s){
    int n = s.length();
    for(int i=0;i<n/2;i++){
        if(s[i]!=s[n-1-i]) return 0;
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int n;
    cin >> n;
    cout << (n+8-1)%8;
    return 0;

}
