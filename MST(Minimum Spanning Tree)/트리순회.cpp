#include <bits/stdc++.h>

using namespace std;
#define MAX 26
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;


typedef struct node{
    char left='.';
    char right='.';
}node;

vector<node> v(MAX);

void preOrder(char c){
    if(c=='.') return;

    cout << c;
    preOrder(v[c].left);
    preOrder(v[c].right);
}
void inOrder(char c){
    if(c=='.') return;
    
    inOrder(v[c].left);
    cout << c;
    inOrder(v[c].right);
}
void postOrder(char c){
    if(c=='.') return;
    
    postOrder(v[c].left);
    postOrder(v[c].right);
    cout << c;
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int n;
    cin >> n;
    
    for(int i=0;i<n;i++){
        char c,l,r;
        cin >> c >> l >> r;
        v[c].left=l;
        v[c].right=r;
    }
    preOrder('A');
    cout << '\n';
    inOrder('A');
    cout << '\n';
    postOrder('A');
    cout << '\n';
    return 0;

}
