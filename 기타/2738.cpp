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

int s[200][200]={0,};
int main(){
    int n;
    int x,y,sum=0;
    cin >> n;
    for(int t=0;t<n;t++){
        cin >> x >> y;
        for(int i=x;i<x+10;i++){
            for(int j=y;j<y+10;j++){
                s[i][j]=1;
            }
        }
    }
    for(int i=1;i<=100;i++){
        for(int j=1;j<=100;j++){
            if(s[i][j]==1){
                sum++;
            }
        }
    }
    cout << sum;
    return 0;
}