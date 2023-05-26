#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

set<string> s;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n,sum=0;
    cin >> n;
    string input;
    for(int i=0;i<n;i++){
        cin >> input;
        if(input=="ENTER"){
            s.clear();
        }
        else{
            if(s.find(input)==s.end()){
                s.insert(input);
                sum++;
            }
        }
    }
    cout << sum;
    return 0;
}