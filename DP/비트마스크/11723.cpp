#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    int n, s=0, x, ch;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> input;
        if (input == "add")
        {
            cin >> x;
            s = s | (1<<x-1);
        }
        else if (input == "remove")
        {
            cin >> x;
            s = s & ~(1<<x-1);
        }
        else if (input == "check")
        {
            cin >> x;
            
            if(s & (1<<x-1)) cout << 1 <<'\n';
            else cout << 0 << '\n';
        }
        else if (input == "toggle")
        {
            cin >> x;
            s = s ^ (1<<x-1);
        }
        else if (input == "all")
        {
            s = s | ((1<<21)-1);
        } 
        else if (input == "empty")
        {
            s = s & 0;
        }
       // cout << "s = " << s << '\n';
    }

    return 0;
}