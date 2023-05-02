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
ll p[300001],v[300001];
multiset<int, int> m;


int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        ll c;
		sum = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		int n;
        cin >> n;

        //큐
        
        for(int i=0;i<n;i++){
            cin >> p[i];
        }
        for(int i=0;i<n;i++){
            cin >> v[i];
            m.insert(v[i]);
            
        }
		/////////////////////////////////////////////////////////////////////////////////////////////
		
        for(int i=0;i<n;i++){
            auto f=m.lower_bound(v[i]);
            cout << *f << " : " << f-m. << "\n";
            c= *f-p[i];
            sum+= c >= 0 ? c : -c;
            m.erase(f);

        }
        cout << "Case #" << test_case+1 << "\n" << sum << "\n";

        ///multiset 
        

	}

   
    return 0;
}