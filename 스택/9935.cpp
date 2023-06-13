#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n,k;

stack<int> s;
string str,c;

void solve(){
    int cnt=0;
    for(int i=0;i<n;i++){
        if(str[cnt]==c[0]){
            s.push(1);
            if(s.top()==k){
                str.erase(cnt-k+1,k);
                for(int j=0;j<k;j++) s.pop();
                cnt-=k;
            }
        }
        else if(!s.empty() && str[cnt]==c[s.top()]){
            s.push(s.top()+1);
            if(s.top()==k){
                str.erase(cnt-k+1,k);
                for(int j=0;j<k;j++) s.pop();
                cnt-=k;
            }
        }
        else{
            while(!s.empty()){
                s.pop();
            }
        }
        cnt++;
    }
    if(str.size()==0){
        cout << "FRULA";
    }
    else cout << str;
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