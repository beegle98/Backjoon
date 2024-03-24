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

int n,v[1000001], result[1000001];
vector<int> LIS;
vector<pair<int,int>> p[1000001]; // value, index

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


    cin >> n;
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    
    
    LIS.push_back(v[0]);
    p[0].push_back({v[0],0});
    int len;
    for(int i=1;i<n;i++){
        if(LIS.back() < v[i]){
            LIS.push_back(v[i]);
            len=LIS.size();
            p[len-1].push_back({v[i],p[len-2].size()-1});
        }
        else{
            int iter = lower_bound(LIS.begin(), LIS.end(), v[i])-LIS.begin();
            LIS[iter] = v[i];
            p[iter].push_back({v[i],p[iter-1].size()-1});
        }
        
    }
    len = LIS.size();
    cout << len << '\n';
    int j=p[len-1].size()-1;
    
    for(int i=len-1;i>=0;i--){
        result[i]=p[i][j].first;
        j=p[i][j].second;
    }
    for(int i=0;i<len;i++){
        cout << result[i] << ' ';
    }
    return 0;
}