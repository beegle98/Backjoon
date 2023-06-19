#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, v[1000001];
stack<pair<int,int>> st;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    
    cin >> n;
    for(int i=0;i<n;i++){
        v[i]=-1;
    }

    int x;
    cin >> x;
    st.push({x,0});
    for(int i=1;i<n;i++){
        cin >> x;
        while(!st.empty()){
            if(st.top().first < x){
                v[st.top().second] = x;
                st.pop();
            }
            else break;
        }
        st.push({x,i});
    }
    for(int i=0;i<n;i++){
        cout << v[i] << ' ';
    }
    
    
    return 0;
}