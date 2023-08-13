#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

const int N=500500;

int n;

vi tree,ans;
vector<pair<int, int>> arr;


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
    ans = vi(n+10);
    tree = vi(4*(n+10));

    for(int i=1;i<=n;i++){
        int x; cin >> x;
        arr.push_back({x,i});
    }

    sort(arr.begin(),arr.end());

    for(int i=0;i<n;i++){
        int j = arr[i].second;
        ans[j] = j - sum(1,1,n,1,j-1);
        update(1,1,n,j,1);
    }
    for(int i=1;i<=n;i++){
        cout << ans[i] << '\n';
    }

    return 0;
}