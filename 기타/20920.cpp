#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
struct obj{
    int cnt;
    int len;
    string str;
    obj(int a,int b,string c) : cnt(a), len(b), str(c) {}
};
struct cmp{
    bool operator()(obj a, obj b){
        if(a.cnt==b.cnt){
            if(a.len==b.len){
                return a.str > b.str;
            }
            return a.len < b.len;
        }
        return a.cnt < b.cnt;
    }
};

map<string,int> s;
priority_queue<obj,vector<obj>,cmp> pq;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n,m,sum=0;
    cin >> n >> m;
    string a;
    
    for(int i=0;i<n;i++){
        cin >> a;
        if(a.size()<m) continue;
        if(s.find(a)==s.end()){
            s.insert({a,1});
        }
        else{
            s[a]++;
        }
    }
    for(auto i=s.begin();i!=s.end();i++){
       // cout << i->first << ", " << i->second<< '\n';
        pq.push(obj(i->second, i->first.size(),i->first));
    }
    while(!pq.empty()){
        cout << pq.top().str << '\n';
        pq.pop();
    }
    return 0;
}