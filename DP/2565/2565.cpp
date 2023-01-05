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

int dp[1111];
vector<pair<int,int>> s;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,max=0;

	cin >> n;
    int x, y;
    for(int i=0;i<n;i++){
        cin >> x >> y;
        s.push_back({x,y});
    }
    sort(s.begin(),s.end());
    
	for (int i = 0; i < n; i++){
		
		dp[i] = 1;
		for (int j = 0; j < i; j++){
			if (s[i].first > s[j].first && s[i].second > s[j].second && dp[i]<=dp[j]){
				dp[i] = dp[j] + 1;
            }
		}
        if(max < dp[i]) max = dp[i];
	}

	cout << n-max;
	return 0;
}