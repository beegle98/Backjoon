//철로
#include <bits/stdc++.h>

using namespace std;
#define MAX 2034567890

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pii;


vector<pii> v1,v2;
priority_queue<pii,vector<pii>,greater<pii>> pq;



int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int n,d; cin >> n;
    for(int i=0;i<n;i++){
        int tmp,x,y;
        cin >> x >> y;
        if(x>y){
            tmp=x;
            x=y;
            y=tmp;
        }
        v1.push_back({x,y});
        v2.push_back({y,x});
    }
    cin >> d;
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    int t=0,Max=0;
    for(int i=0;i<n;i++){
        int x,y;
        x=v1[i].first;
        y=x+d;
        while(t<n){//y보다 작은 곳 pq에 삽입
            if(v2[t].first>y) break;
            pq.push({v2[t].second,v2[t].first});
            t++;
        }
        while(!pq.empty()){//pq에서 x보다 작으면 삭제
            if(pq.top().first<x) pq.pop();
            else break;
        }
        if(Max<pq.size()) Max = pq.size();
    }
    cout << Max;
    return 0;
}
