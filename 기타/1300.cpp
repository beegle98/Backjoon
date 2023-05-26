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

int n,k;

bool check(int mid){
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=min(mid/i,n);
        if(sum>=k) return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n >> k;
   
    
    int l=0,h=k;

    while(l+1<h){
        int mid = (l+h)/2;
        if(check(mid)) h=mid;
        else l=mid;
    }
    cout << h << '\n';
    return 0;
}