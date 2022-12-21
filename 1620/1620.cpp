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
string x,ans[100001];
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int n,m;
    map<string,string> map_name;
    map<string,string> map_index;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> x;
        //cout << to_string(i) <<"\n";
        map_index.insert(make_pair(to_string(i),x));
        map_name.insert(make_pair(x,to_string(i)));
    }

    for(int i=0;i<m;i++){
        cin >> x;
        
        if('0'<=x[0] && x[0]<='9')
        {
            //printf("%s\n",map_index.at(x).c_str());
            ans[i] = map_index.at(x);
        }
        else ans[i] = map_name.at(x);
                
    }
    for(int i=0;i<m;i++){
        cout << ans[i] << '\n';
    }
    return 0;
}