#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <map>
#include <set>
using namespace std;

typedef long long ll;



int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int n,k;
    cin >> n;

    queue<int> q;

    for(int i=1;i<=n;i++){
        q.push(i);
    }
    for(int i=1;i<n;i++){
        q.pop();
        k=q.front();
        q.pop();
        q.push(k);
    }
    k=q.front();
    cout << k;
    return 0;
}