#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 251111;

int sum,v[N],pi[N];
string r,p;


void getPi(){
    int m=(int)p.size(), j=0;
    memset(pi,0,m*sizeof(int));
    for(int i = 1; i< m ; i++){
        while(j > 0 && p[i] !=  p[j]){
            j = pi[j-1];
        }
        if(p[i] == p[j]){
            pi[i] = ++j;
        }
    }
}

void solve(){

    cin >> r >> p;
    
    getPi();
    int n=(int)r.size(), m=(int)p.size(), j=0;
    
    memset(v,0,n*sizeof(int));

    for(int i=0;i<n;i++){
        if(j>0 && r[i]!=p[j]){
            v[i-1]=j;
            while(j>0 && r[i]!=p[j]){
                j=pi[j-1];
            }
            if(v[i-1-j]<v[i-1]-j) v[i-1-j]=v[i-1]-j;
        }
        if(r[i]==p[j]){
            if(j==m-1){
                v[i]=j+1;
                j=pi[j];
                if(v[i-j]<v[i]-j) v[i-j]=v[i]-j;
            }
            else j++;
        }
        else{
            sum=-1;
            return;
        }
    }
    if(!v[n-1]) v[n-1]=j;
    
    int i=n-1;
    sum=0;
    while(i>=0){
        if(!v[i]){
            sum=-1;
            return;
        }
        sum++;
        i-=v[i];
    }
    
}

int main()//kmp 추가하다가 코드가 너무 꼬였다
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        solve();
		cout << "Case #" << test_case+1 << '\n' << sum << '\n';
	}

    return 0;
}