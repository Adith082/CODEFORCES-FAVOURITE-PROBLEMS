//BISMILLAH
#include <bits/stdc++.h>
using namespace std;
unordered_map <long long int,long long int> mm;
int main(){
    long long int t,n,len;
    long long int val,left,res,i;
    cin >> t;
    while(t--){
        res = 0;
        left = 0;
        cin >> n;
        set <long long int> ss;
        set <long long int> :: iterator it;
        for(i = 0;i<n;i++){
            cin >> val;
            mm[val]++;
            ss.insert(val);
        }
        len = ss.size();
        for(it  = ss.begin();it != ss.end() ;++it){
            val = *it;
            res = res + ((mm[val] + left)/val);
            left = (mm[val] + left) % val;
        }
        cout << res << endl;
        mm.clear();
        ss.clear();
    }
    return 0;
}