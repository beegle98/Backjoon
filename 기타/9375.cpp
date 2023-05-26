#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <map>
using namespace std;

typedef long long ll;

int main(){
    int T,n,sum=0;
    map<string,int> s;
    string a,b;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d",&n);
        for(int j=0;j<n;j++){
            cin >> a >> b;
            //cout << a << " " << b << "\n";
            if(s.find(b)==s.end()) s.insert(make_pair(b,1));
            else s[b]++;
        }
        sum=1;
        for(auto j=s.begin(); j!=s.end();j++){
            sum*=(j->second+1);
           // cout << j->first << " " << j->second << "\n";
        }
        cout << sum-1 << "\n";
        s.clear();
    }
    return 0;
}