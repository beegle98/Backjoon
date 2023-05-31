#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <map>
#include <set>
using namespace std;

typedef long long ll;

deque<int> dq;
bool f,error;
int t,n,x,m;
char c;
string p;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> t;
    for(int k=0;k<t;k++){
        f=1;
        error=0;
        cin >> p; //string
        cin >> n; //원소 개수
        cin >> c; // '['
        for(int i=0;i<n;i++){
            cin >> x;
            dq.push_back(x);
            if(i<n-1) cin >> c; // ','
        }
        cin >> c; // ']'
        for(int i=0;i<p.size();i++){
            if(p[i]=='R'){
                f=!f;
            }
            else if(p[i]=='D'){
                if(dq.empty()){
                    error=1;
                    break;
                }
                else if(f){
                    dq.pop_front();
                }
                else dq.pop_back();
            }
        }
        if(error) cout << "error\n";
        else{
            m=dq.size();
            cout << '[';
            for(int i=0;i<m;i++){
                if(f){
                    cout << dq.front();
                    dq.pop_front();
                }
                else{
                    cout << dq.back();
                    dq.pop_back();
                }
                if(i<m-1) cout << ',';
            }
            cout << ']' <<'\n';
        }


        dq.clear();
    }
    return 0;
}