#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <set>
#include <map>
using namespace std;

typedef long long ll;

ll sum=0;
ll p[300001], v[300001];
vector<pair<int,int>> s;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
       
		/////////////////////////////////////////////////////////////////////////////////////////////
		
        int n;
        cin >> n;
        s.clear();
        for(int i=0;i<n;i++){
            cin >> p[i];
        }
        for(int i=0;i<n;i++){
            cin >> v[i];
            s.push_back({v[i],p[i]});
        }
        sort(s.begin(),s.end());
        sum=0;
        for(int i=0;i<n;i++){
            sum+=abs(s[i].second-p[i]);
        }

		/////////////////////////////////////////////////////////////////////////////////////////////
		
        
        cout << "Case #" << test_case+1 << "\n" << sum << "\n";

	}

   
    return 0;
}