#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

ll p[1000100],cnt[1000100];
stack<char> s;

ll solve(){
    ll sum=0;
    int n; cin >> n;
    string arr; cin >> arr;

    int h=0;
    for(int i=0;i<n;i++){
        if(arr[i]==')'){
            if(s.empty()){
                sum+=p[cnt[1]];
                cnt[1]=0;
                continue;
            }
            h=s.size();
            sum+=p[cnt[h+1]];
            cnt[h+1]=0;
            if(s.top()=='{'){
                for(int j=h;j>=1;j--){
                    sum+=p[cnt[j]];
                    cnt[j]=0;
                }
                while(!s.empty()) s.pop();
            }
            else{
                cnt[h]++;
                s.pop();
            }
        }
        else if(arr[i]=='}'){
            if(s.empty()){
                sum+=p[cnt[1]];
                cnt[1]=0;
                continue;
            }
            h=s.size();
            sum+=p[cnt[h+1]];
            cnt[h+1]=0;
            if(s.top()=='('){
                for(int j=h;j>=1;j--){
                    sum+=p[cnt[j]];
                    cnt[j]=0;
                }
                while(!s.empty()) s.pop();
            }
            else{
                cnt[h]++;
                s.pop();
            }
        }
        else{
            s.push(arr[i]);
        }
    }
    if(s.size()>h) h=s.size();
    for(int j=h+1;j>=1;j--){
        sum+=p[cnt[j]];
        cnt[j]=0;
    }
    while(!s.empty()) s.pop();
    return sum;
}

int main()//만점
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int T, test_case;

    p[0]=0;
    for(int i=1;i<=1000000;i++){
        p[i]=i+p[i-1];
    }
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        ll ans;
        ans = solve();
		cout << "Case #" << test_case+1 << '\n' << ans << '\n';
	}

    return 0;
}