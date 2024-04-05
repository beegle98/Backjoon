#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int N=100100;


vector<pii> tree;

pii min(pii a, pii b){
    if(a.first==0) return b;
    if(b.first==0) return a;
    
    if(a.first < b. first) return a;
    else if(a.first > b.first) return b;
    else{
        if(a.second <= b.second) return a;
        else return b;
    }
}

pii Min(int node, int start, int end, int left, int right){
    if(left > end || right < start) return {0,0};
    if(left <= start && right >= end){
        return tree[node];
    }
    return min(Min(node*2, start, (start+end)/2, left, right)
        , Min(node*2+1, (start+end)/2+1, end, left, right));
}

void update(int node, int start, int end, int idx, int val){
    if(idx<start || idx > end) return;
    if(start == end){
        tree[node]={val,start};
        return;
    }
    update(node*2, start, (start+end)/2, idx, val);
    update(node*2+1, (start+end)/2+1, end, idx, val);
    tree[node] = min(tree[node*2], tree[node*2+1]);
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n,m;
    cin >> n;
    
    tree = vector<pii>(4*N);

    for(int i=1;i<=n;i++){
        int a; cin >> a;
        update(1,1,N,i,a);
    }
    
    cin >> m;

    for(int i=0;i<m;i++){
        int x,a,b; cin >> x >> a >> b;
        if(x==1){
            update(1,1,N,a,b);
        }
        else if(x==2){
            if(a>b){
                int tmp=a;
                a=b;
                b=tmp;
            }
            cout << Min(1,1,N,a,b).second << '\n';
        }
    }

    return 0;
}