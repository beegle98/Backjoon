#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, v[1000001], s[1000001], cnt[1000001];
stack<pair<int,int>> st;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    
    cin >> n;
    for(int i=0;i<n;i++){
        v[i]=-1;
    }

    
    for(int i=0;i<n;i++){
        cin >> s[i];
        cnt[s[i]]++;
    }
    int x;
    for(int i=0;i<n;i++){
        x = cnt[s[i]];
        while(!st.empty()){
            if(st.top().first < x){
                v[st.top().second] = s[i];
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