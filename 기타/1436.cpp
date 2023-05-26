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
    int n,cnt=0,k=665,tmp,ans;
    scanf("%d",&n);
    while(cnt<n){
        k++;
        tmp=k;
        ans=k;
        while(tmp>665){
            if(tmp%1000==666){
                cnt++;
                break;
            }
            tmp/=10;
        }
    }
    printf("%d",ans);
    return 0;
}