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
    ll n, f1=1,f2=1,f3;
    scanf("%lld",&n);
    for(int i=3;i<=n;i++){
        f3=f1+f2;
        f1=f2;
        f2=f3;
    }
    printf("%lld %lld\n",f3,n-2);
}