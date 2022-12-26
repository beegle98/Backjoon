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

int s[1111],dp1[1111],dp2[1111];
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,max=0;

	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> s[i];
		dp1[i] = 1;
        dp2[i]=1;
		for (int j = 0; j < i; j++){
			if (s[i] > s[j] && dp1[i]<=dp1[j]){
				dp1[i] = dp1[j] + 1;
            }
		}
        for(int j=i-1;j>=0;j--){
            if(s[i] > s[j] && dp2[i]<=dp2[j]){
                dp2[i]=dp2[j]+1;
            }
        }
	}
    for(int i=0;i<n;i++){
        printf("%d %d\n",dp1[i],dp2[i]);
        if(max < dp1[i]+dp2[i]){
            max = dp1[i]+dp2[i];
        }
    }
	cout << max;
	return 0;
}