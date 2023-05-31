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

ll n;


int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    ll T, cnt=0;
    cin >> T;

    for(ll i=0;i<T;i++){
        cin >> n;
        if(n<2) n=2;
        while(1){
            cnt=0;
            for(ll j=2;j*j<=n;j++){
                if(n%j==0){
                    cnt++;
                    break;
                }
            }
            if(cnt==0){
                cout << n << '\n';
                break;
            }
            else n++;
        }
        
    }
    
    return 0;
}