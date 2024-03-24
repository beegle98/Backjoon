#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll sum;

void solve(){
    vector<pair<int, int>> v1,v2;//음수, 양수
    map<int, int> m1,m2;
    int n,d;
    cin >> n >> d;

    sum=0;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        if(x<0) m1[-x]+=1;
        else if(x>0) m2[x]+=1;
        else sum++; // 좌표가 0인 딸기는 미리 합
    }
    v1.push_back({0,0});
    v2.push_back({0,0});
    int p=0;
    for(auto i=m1.begin(); i!=m1.end();i++){
        //cout << i->first << " : " << i->second << '\n';
        p+=i->second;
        v1.push_back({i->first,p});
    }
    p=0;
    for(auto i=m2.begin(); i!=m2.end();i++){
        //cout << i->first << " : " << i->second << '\n';
        p+=i->second;
        v2.push_back({i->first,p});
    }
    int l,r,Max=0;
    l=v1.size()-1;
    for(r=0;r<v2.size();r++){
        //cout << v1[r].first << " : " << v1[r].second << '\n';
        if(l>0){
            while(l > 0 && (v1[l].first + v2[r].first + min(v1[l].first, v2[r].first)) > d){
                l--;
            }
            
            if(Max < v1[l].second + v2[r].second){
                Max = v1[l].second + v2[r].second;
            }
        }
        else{
            if(v2[r].first <= d && v2[r].second > Max){
                Max = v2[r].second;
            }
        }
    }
    sum += Max;
    return;
}

int main()//만점
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