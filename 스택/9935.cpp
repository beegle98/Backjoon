#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n,k;

stack<pair<char,int>> s;
string str,c;

void solve(){
    
    for(int i=0;i<n;i++){
        if(str[i]==c[0]){
            s.push({str[i],1});
            if(s.top().second==k){
                
                for(int j=0;j<k;j++) s.pop();
                
            }
        }
        else if(!s.empty() && str[i]==c[s.top().second]){
            s.push({str[i],s.top().second+1});
            if(s.top().second==k){
                
                for(int j=0;j<k;j++) s.pop();
                
            }
        }
        else{
            s.push({str[i],0});
        }
    }
    if(s.empty()){
        cout << "FRULA";
    }
    else{
        vector<char> result;
        int len=s.size();
        for(int i=0;i<len;i++){
            result.push_back(s.top().first);
            s.pop();
        }
        for(int i=0;i<len;i++){
            cout << result[len-i-1];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> str >> c;
    n=str.size();
    k = c.size();
    solve();
   
    return 0;
}