#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;


vi s,p,d;

ll solve(){
    ll sum = 0;
    int n,k; cin >> n >> k;
    s = vi(n+100);
    d=vi(n+100,0);//누적합
    p=vi(5*n+100,0);//누적합 위치
    int Max=0;
    for(int i=0;i<n;i++){
        cin >> s[i];
        Max+=s[i];
        d[i+1]=Max;
        p[Max]=i+1;
    }


    int x=0,m=0,w=0, r=0,sub=0;//x:배열 현재위치, m= 상태, w= 남은 값, r= 배열 반복 횟수

    while(r<k){
        if(m==0){//처음
            if(w<5 && p[d[x]+5-w]){
                if(p[d[x]+8-w]){
                    sub=17;
                    x=p[d[x]+8-w];
                    m=2;
                }
                else{
                    sub=9;
                    x=p[d[x]+5-w];
                    m=1;
                }
                w=0;
            }
            else if(w<10 && p[d[x]+10-w]){
                sub=14;
                x=p[d[x]+10-w];
                
                w=0;
                m=3;
            }
            else{
                if(w>10){
                    sub=0;
                    m=4;
                }
                else if(Max-d[x] + w < 10){//배열 한바퀴 돌고 다시 m=0
                    r++;
                    w+=Max-d[x];
                    x=0;
                    m=0;
                }
                else{
                    sub=0;
                    m=4;
                }
            }
        }
        else{//나머지 그냥 구해야됨
            int g=20-sub;
            if(Max-d[x] + w <= g){// 배열 돌고 다시 m=4;
                r++;
                w+=Max-d[x];
                x=0;
                m=4;
            }
            else{
                for(int i=1;i<=5;i++){
                    if(p[d[x]+g-w+i]){
                        //cout << "sub= " << sub << '\n';
                        //cout << sum << " : " << r << " , " << w <<'\n';
                        x=p[d[x]+g-w+i];
                        m=0;
                        w=0;
                        sum++;
                        break;
                    }
                }
            }
        }
    }

    
    return sum;
}

int main()//시뮬레이션 구현은 시간초과
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        ll ans;
        ans = solve();
		cout << "Case #" << test_case+1 << '\n' << ans << '\n';
	}

    return 0;
}