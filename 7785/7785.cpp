#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <set>
using namespace std;

typedef long long ll;


int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n;
    string name, k;
    set<string> s;
    
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> name >> k;
        if(k=="enter"){
            s.insert(name);
        }
        else if(k=="leave"){
            s.erase(name);
        }
    }
    for(auto itr = s.rbegin(); itr!=s.rend(); itr++){
        cout << *itr << '\n';
    }
    return 0;
}