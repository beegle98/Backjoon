//개미굴
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

typedef struct trie{

    map<string, trie*> child;

    void trieInsert(vector<string> &s,int idx){
        if(idx==s.size()) return;

        if(child.find(s[idx])!=child.end()){ // 이미 존재하는 노드(이름이 같음)
            child[s[idx]]->trieInsert(s,idx+1);
        }
        else{
            trie* node = new trie;
            child.insert({s[idx],node});
            node->trieInsert(s,idx+1);
        }        
    }

    void dfs(int idx){
        for(auto& i : child){
            for(int j=0;j<idx;j++) cout << "--";
            cout << i.first << '\n';
            i.second->dfs(idx+1);
            delete i.second;
        }
    }
}trie;


int main(){
    FASTIO
    int n;
    cin >> n;
    
    trie* root = new trie;

    for(int i=0;i<n;i++){
        int m; cin >> m;
        vector<string> s(m);
        for(int j=0;j<m;j++)cin >> s[j];
        root->trieInsert(s,0);
    }
    root->dfs(0);
    delete(root);
    return 0;

}