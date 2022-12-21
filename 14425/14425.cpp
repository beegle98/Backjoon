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

int main(){
    int n,m,sum;
    string x;
    set<string> s;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        cin >> x;
        s.insert(x);
    }
    sum=0;
    for(int i=0;i<m;i++){
        cin >> x;
        if(s.find(x)!=s.end()){
            sum++;
        }
    }
    printf("%d",sum);
    return 0;
}