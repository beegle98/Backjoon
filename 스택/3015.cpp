#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n,v[500005],sum=0;

stack<pair<ll,ll>> s;

void solve(){
    s.push({v[0],1});

    for(int i=1;i<n;i++){
        //cout << sum;
        
        if(s.top().first<v[i]){
            
            while(1){
                if(s.empty()){
                    s.push({v[i],1});
                    break;
                }
                if(s.top().first>v[i]){
                    s.push({v[i],1});
                    sum++;
                    break;
                }
                else if(s.top().first==v[i]){       
                    sum+=s.top().second;
                    s.top().second++;
                    if(s.size()>1) sum++;
                    break;
                }
                
                sum+=s.top().second;
                s.pop();
                
            }
            
        }
        else if(s.top().first>v[i]){
            sum++;
            s.push({v[i],1});
        }
        else{
            sum+=s.top().second;
            s.top().second++;
            if(s.size()>1) sum++;
        } 
    }
    
    return;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    
    solve();
    // 스택은 내림차순으로만 정렬
    // 마지막 수보다 큰 수가 나오면 현재 수보다 작은 수들은 스택에서 제거
    // 제거한 개수 만큼 sum 추가
    // 작은 수가 나오면 스택에 넣고 sum++
    // 같은 수가 나오면 cnt++ sum+=cnt;
    

    cout << sum << '\n';
    
    return 0;
}