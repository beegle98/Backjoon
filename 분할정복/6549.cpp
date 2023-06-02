#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


ll n;

ll h[100010];
ll maxArea(int a,int b){

    ll maxA, mid = (a+b)/2;
    ll minH=h[mid],left=mid, right=mid+1;
    maxA=0;
    while(left>=a && right <=b){
        minH = min({minH, h[left], h[right]});
        maxA = max(maxA, (right-left+1) * minH);
        if(left == a) right++;
        else if(right==b) left--;
        else if(h[left-1] <= h[right+1]) right++;
        else left--;
    }
    return maxA;
}
ll divide(int a,int b){
    if(a==b){
        return h[a];
    }
    else{
        int mid=(a+b)/2;
        ll area=maxArea(a,b);
        return max({area,divide(a,mid),divide(mid+1,b)});
    }
}

void solve(){
    
    while(1){
        cin >> n;
        if(n==0) break;
        for(int i=0;i<n;i++){
            cin >> h[i];
        }
        ll MAX = divide(0,n-1);
        cout << MAX << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    solve();
    

    
    return 0;
}