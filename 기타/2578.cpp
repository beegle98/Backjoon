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
    int sum=0,n;
    for(int i=0;i<5;i++){
        scanf("%d",&n);
        sum+=n;
        s.push_back(n);
    }
    sort(s.begin(), s.end());
    printf("%d\n%d",sum/5,s[2]);
    return 0;
}