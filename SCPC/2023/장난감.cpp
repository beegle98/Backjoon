#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int ans;
int n, s[543210];

void solve(){
    
    vector<int> v;
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    for(int i=1;i*i<=n;i++){
        if(n%i==0) v.push_back(i);
    }
    int vsize = v.size();
    for(int i=vsize-1;i>=0;i--){
        v.push_back(n/v[i]);
    }
    int flag;
    ans = n;
    for(int i=0;i<v.size();i++){
        //cout << "v : " <<v[i] << '\n';
        flag=1;
        for(int j=0;j<n;j++){
            if(s[j]!=s[j%v[i]]){
                flag=0;
                break;
            }
        }
        if(flag){
            ans=v[i];
            break;
        }
    }
}

int main()//60점
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        solve();
		cout << "Case #" << test_case+1 << '\n' << ans << '\n';
	}

    return 0;
}