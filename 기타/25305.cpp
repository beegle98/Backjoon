#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long ll;

int main(){
    
    vector<int> s;
    int n,x,k;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        s.push_back(x);
    }
    sort(s.begin(), s.end());
    printf("%d",s[n-k]);
    return 0;
}