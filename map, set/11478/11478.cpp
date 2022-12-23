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

    set<string> s;
    string x;
    cin >> x;
    int n=x.size();
    for(int i=0;i<n;i++){
        //cout << '\n' << i << ": \n";
        for(int j=0;j<n-i;j++){
            //cout << x.substr(j, i+1) << ' ';
            s.insert(x.substr(j, i+1));
        }
    }
    cout << s.size();
    return 0;
}