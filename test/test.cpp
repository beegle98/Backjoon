#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int n[10];
    int sum=0;
    for(int i=0;i<5;i++){
        cin >> n[i];
        sum+=n[i]*n[i];
    }
    cout << sum%10;
    return 0;

}
