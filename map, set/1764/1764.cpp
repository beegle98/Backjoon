#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <map>
#include <set>
using namespace std;

typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int n,m,sum=0;
    set<string> s,ans;

    cin >> n >> m;
    string x;
    for(int i=0;i<n;i++){
        cin >> x;
        s.insert(x);
    }
    for(int j=0;j<m;j++){
        cin >> x;
        if(s.find(x)!=s.end()){
            ans.insert(x);
            sum++;
            
        }
    }
    cout << sum << '\n';
    for(auto i=ans.begin();i!=ans.end();i++){
        cout << *i << '\n';
    }
    return 0;
}