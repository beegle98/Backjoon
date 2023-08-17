#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

const int N=1000100;

int n;

vll tree, arr;

ll init(int node, int start, int end){
    if(start == end){
        return tree[node] = arr[start];
    }
    return tree[node] = init(node*2, start, (start+end)/2)
        + init(node*2+1,(start+end)/2+1, end);
}

ll sum(int node, int start, int end, int left, int right){
    if(left > end || right < start) return 0;
    if(left <= start && right >= end){
        return tree[node];
    }
    return sum(node*2, start, (start+end)/2, left, right)
        + sum(node*2+1, (start+end)/2+1, end, left, right);
}

void update(int node, int start, int end, int left,int right, ll diff){
    
    if(left > end || right < start) return;
    int ld,rd;
    ld = (start > left) ? start-left : 0;
    rd = (end < right) ? right-end : 0;
    tree[node] += diff*(right-left+1-rd-ld);
    if(start != end){
        update(node*2, start, (start+end)/2, left, right, diff);
        update(node*2+1, (start+end)/2+1, end, left, right, diff);
    }
}
int main(){//lazy propagation
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n,m,k;
    cin >> n >> m >> k ;
    arr = vll(n+10);
    tree = vll(4*(n+10));

    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }

    init(1,1,n);

    for(int i=0;i<m+k;i++){
        int a,b,c,d;
        cin >> a >> b >> c;
        if(a==1){
            cin >> d;
            update(1,1,n,b,c,d);
        }
        else{
            ll ans = sum(1,1,n,b,c);
            cout << ans <<'\n';
        }
    }
    return 0;
}