#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long ll;



int main(){
    ll n,sum=0,min=1000000001;
    vector<int> len,cost;

    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int x;
        scanf("%d",&x);
        len.push_back(x);
    }
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        cost.push_back(x);
    }
    for(int i=0;i<n-1;i++){
        if(min>cost[i]){
            min=cost[i];
        }
        sum+=min*len[i];
        
    }
    printf("%lld",sum);
    return 0;
}