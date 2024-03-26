//개미굴
#include <bits/stdc++.h>

using namespace std;
#define MAX 26
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

typedef priority_queue<string, vector<string>, greater<string>> pq;

//struct compare;

typedef struct node{

    int level;
    string data;
    priority_queue<node, vector<node>, compare> child;
    
}node;

struct compare {
    bool operator(node a, node b){
        return a.data > b.data;
    }
};

node root;

void preOrder(node n){
    if(n==NULL) return;

    for(int i=1;i<n.level;i++) cout << "--";
    cout << c << '\n';
    for(int i=0;i<n.child.size();i++){
        preOrder(n.child.top());
        n.child.pop();
    }
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int n;
    cin >> n;
    
    root.level=0;
    

    for(int i=0;i<n;i++){
        int m;
        cin >> m;
        node* tmp;
        tmp = &root;
        for(int j=0;j<m;j++){
            string s;
            cin >> s;
            node a;
            a.level = *tmp->level+1;
            a.data = s;
            *tmp->child.push(a);
            tmp =&a;
        }
    }
    preOrder(root);
    return 0;

}