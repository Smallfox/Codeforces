#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
#include <map>
using namespace std;
typedef long long LL;
const int maxn = 1e6 + 8;

map<char, int> ch;
queue<char> que, ans;

int main()
{
    #ifdef LOCAL
    freopen("b.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
    int T = 6;
    while(T--){
    #endif // LOCAL
    ios::sync_with_stdio(false); cin.tie(0);

    string s;
    cin >> s;
    int sz = s.size();
    if(sz < 26) cout << -1 << endl;
    else{
        int ptr = 0, ind = 0;

        while(que.size() < 26){
            que.push(s[ptr]);
            ch[s[ptr]]++;
            while(s[ptr] != '?' && ch[s[ptr]] > 1){
                ch[que.front()]--;
                que.pop();
                ind++;
            }
            ptr++;
            if(ptr >= sz) break;
        }
        if(que.size() == 26){
            for(int i = 0; i < 26 ; i++){
                if(ch[i + 'A'] == 0){
                    ans.push(i + 'A');
                }
            }

            for(int i = 0; i < ind; i++){
                if(s[i] != '?') cout << s[i];
                else cout << 'A';
            }
            while(!que.empty()){
                if(que.front() != '?'){
                    cout << que.front();
                }
                else{
                    cout << ans.front();
                    ans.pop();
                }
                que.pop();
            }
            for(int i = ind + 26; i < sz; i++){
                if(s[i] != '?') cout << s[i];
                else cout << 'A';
            }
            cout << endl;
        }
        else{ cout << -1 << endl;}
    }



    #ifdef LOCAL
    ch.clear();
    while(!que.empty()) que.pop();
    cout << endl;
    }
    #endif // LOCAL
    return 0;
}
