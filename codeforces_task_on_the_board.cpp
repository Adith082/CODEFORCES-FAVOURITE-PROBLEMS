//BISMILLAH
#include <bits/stdc++.h>
using namespace std;
unordered_map <char,int> mm;
unordered_map <char,int> tr;
int main(){
    int q,i,j,k,len,sum,fl,n,pp;
    int cnt0;
    string s;
    cin >> q;
    while(q--){
        fl = 0;
        mm.clear();
        tr.clear();
        sum = 0;
        cnt0 = 0;
        cin >> s;
        cin >> n;
        char res[n];
      //  int pos[n];
        int b[n];
        int flag[n];
        for(i = 0;i<n;i++) {
            cin >> b[i];
        }
      //  memset(pos,-1,sizeof(pos));
        memset(flag,0,sizeof(flag));
        len = s.size();
        int pos[len];
        memset(pos,-1,sizeof(pos));
        sort(s.begin(),s.end());
        for(i = 0;i<len;i++) mm[s[i]]++;
        pp = len-1;
        while(1)
        {
            sum = 0;
            cnt0 = 0;
            j = 0;
            for(i = 0;i<n;i++){
            if(flag[i] == 0 && b[i] == 0) {
                cnt0++;
                flag[i] = 1;
                pos[j++] = i;
                fl = 1;
               }
             }
             if(fl == 0) break;
             else fl = 0;
             i = pp;
            for(   ;i>=0;i--){
                if(tr[s[i]] == 0 && (mm[s[i]] >= cnt0)){
                        for(k = 0;k<j;k++) res[pos[k]] = s[i];
                        tr[s[i]] = 1;
                        pp = i;
                        break;
                }
            }
            for(i = 0;i<n;i++){
                if(flag[i] == 0){
                    for(k = 0;k<j;k++){
                        sum = sum + abs(pos[k] - i);
                    }
                    b[i] = b[i] - sum;
                    sum = 0;
                }
            }
       }
       for(i = 0;i<n;i++) cout << res[i];
       cout << endl;
    }
    
    return 0;
}