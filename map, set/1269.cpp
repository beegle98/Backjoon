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
    map<int,int> s;

    cin >> n >> m;
    int x;
    for(int i=0;i<n+m;i++){
        cin >> x;
        if(s.find(x)==s.end()) s.insert({x,1});
        else s[x]++;
    }
    for(auto i=s.begin();i!=s.end();i++){
        if(i->second == 1) sum++;
        //cout << i->second << '\n';
    }
    cout << sum;
    return 0;
}