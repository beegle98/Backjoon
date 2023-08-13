#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

const int N=500500;

int n;

vi tree, arr;
int s[1000100];

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

void update(int node, int start, int end, int idx, ll diff){
    if(idx<start || idx > end) return;
    tree[node] += diff;
    if(start != end){
        update(node*2, start, (start+end)/2, idx, diff);
        update(node*2+1, (start+end)/2+1, end, idx, diff);
    }
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n;
    cin >> n;
    arr = vi(n+10);
    tree = vi(4*(n+10));

    for(int i=1;i<=n;i++){
        int x; cin >> x;
        s[x]= i;
    }
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        arr[i]=s[x];
    }
    
    ll ans = 0;

    for(int i=1;i<=n;i++){
        ans += sum(1, 1, n, arr[i]+1, n);
        update(1,1,n,arr[i],1);
    }

    cout << ans;

    return 0;
}