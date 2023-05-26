#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

set<string> s;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n,sum=0;
    cin >> n;
    string a,b;
    s.insert("ChongChong");
    for(int i=0;i<n;i++){
        cin >> a >> b;
        if(s.find(a)!=s.end() || s.find(b)!=s.end()){
            s.insert(a);
            s.insert(b);
        }
    }
    cout << s.size();
    return 0;
}