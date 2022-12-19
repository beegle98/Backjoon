#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long ll;

int main(){
    string a,b,c;
    cin >> a;
    cin >> b;
    ll al=a.length(), bl=b.length(), sum=0;
    for(int i=0;i<al || i<bl;i++){
        if(i<al){
            sum+=a[al-i-1]-'0';
        }
        if(i<bl){
            sum+=b[bl-i-1]-'0';
        }
        c+=(sum%10)+'0';
        sum/=10;
    }
    if(sum>0) c+=(sum%10)+'0';
    reverse(c.begin(),c.end());
    cout << c;
    return 0;
}