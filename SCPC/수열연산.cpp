#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll Cnt,Cost=0;
int n,k,Max[2],input[111111];
int l,r,r2,s[111111][2],s2[111111][2];


void solve(){
    cin >> n >> k;

    Max[0] = -1;
    for(int i=0;i<n;i++){
        cin >> input[i];
        input[i] = k-input[i] > 0 ? k-input[i] : 0;
        //k값 적용
        if(Max[0] < input[i]){
            Max[0] = input[i];
            Max[1] = i;
        }
    }
    l=0;
    r=-1;
    int p=0;
    
    for(int i=0;i<=Max[1];i++){//오름차순
        if(p<input[i]){
            
            p=input[i];
            r++;
            s[r][0]=p;
            s[r][1]=i;
        }
    }
    // Max값 기준 반으로 쪼갬
    r2=-1;
    p=0;
    for(int i=n-1;i>Max[1];i--){//반대로 오름차순
        if(p<input[i]){
            p=input[i];
            r2++;
            s2[r2][0]=p;
            s2[r2][1]=i;
        }
    }
    for(int i=r2;i>=0;i--){//합치기
        r++;
        s[r][0]=s2[i][0];
        s[r][1]=s2[i][1];
        
    }
    int cur=0;
    Cnt=0;
    Cost=0;
    while(l<=r && cur<Max[0]){
        Cnt++;
        if(s[l][0] < s[r][0]){
            Cost += (s[l][0]-cur) * (s[r][1] - s[l][1] + 1);
            cur=s[l][0];
            l++;
        }
        else if(s[l][0] > s[r][0]){
            Cost += (s[r][0]-cur) * (s[r][1] - s[l][1] + 1);
            cur=s[r][0];
            r--;
        }
        else{
            Cost += (s[l][0]-cur) * (s[r][1] - s[l][1] + 1);
            cur=s[l][0];
            l++;
            r--;
        }
        //cout << Cnt << " : " <<l<<" "<<r<< " "<< cur<<'\n';

    }
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    

    int T, test_case;
    
    cin >> T;
    
	for(test_case = 0; test_case  < T; test_case++)
	{   
        solve();
        cout << "Case #" << test_case+1 << '\n' << Cnt << " " << Cost << '\n';
	}
    return 0;
}