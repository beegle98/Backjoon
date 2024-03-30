#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

deque<int> dq;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;

        if(s=="push_front"){
            int a;
            cin >> a;
            dq.push_front(a);
        }
        else if(s=="push_back"){
            int a;
            cin >> a;
            dq.push_back(a);
        }
        else if(s=="pop_front"){
            if(dq.empty()) cout << "-1\n";
            else{
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        }
        else if(s=="pop_back"){
            if(dq.empty()) cout << "-1\n";
            else{
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        }
        else if(s=="size"){
            cout << dq.size() << '\n';
        }
        else if(s=="empty"){
            cout << dq.empty() << '\n';
        }
        else if(s=="front"){
            if(dq.empty()) cout << "-1\n";
            else cout << dq.front() << '\n';
        }
        else if(s=="back"){
            if(dq.empty()) cout << "-1\n";
            else cout << dq.back() << '\n';
        }
        else continue;
    }
    return 0;

}
