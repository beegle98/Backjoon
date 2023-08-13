#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

const int N=1000100;

int n;

vi tree;
vector<pair<int, int>> arr;


ll sum(int node, int start, int end, int left, int right){
    if(left > end || right < start) return 0;
    if(left <= start && right >= end){
        return tree[node];
    }
    return sum(node*2, start, (start+end)/2, left, right)
        + sum(node*2+1, (start+end)/2+1, end, left, right);
}

int search(int node,int start, int end, int key){
    if(start == end) return end;
    if(key <= tree[node*2]) return search(node*2, start, (start+end)/2, key);
    else return search(node*2+1, (start+end)/2+1, end, key-tree[node*2]);
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
    
    tree = vi(4*N);

    for(int i=1;i<=n;i++){
        int x; cin >> x;
        int a,b;//순위, 개수
        if(x==1){
            cin >> a;
            int ans = search(1,1,N,a);
            cout << ans <<'\n';
            update(1,1,N,ans,-1);
        }
        else if(x==2){
            cin >> a >> b;
            update(1,1,N,a,b);
        }
    }

    return 0;
}