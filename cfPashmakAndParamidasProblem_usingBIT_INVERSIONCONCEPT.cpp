//IN THE NAME OF ALLAH THE MOST MERCIFUL THE ENTIRELY MERCIFUL
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
#define sz 1000009
int BIT[sz];
unordered_map <int,int> mm;
void update(int i,int val,int n){
    for( ;i<=n;i += i&(-i)){
        BIT[i]+=val;
    }   return;
}   int sum(int i){
    int ss = 0;
    while(i>0){
        ss += BIT[i];
        i -= (i&(-i));
    }   return ss;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,n,tm,id;
    long long int res = 0;
    cin >> n;
    int temp[n+1];
    int a[n+1];
    int pre[n+1];
    int post[n+1];
    temp[0] = 0;
    a[0] = 0;
    for(i = 1;i<=n;i++){
        cin >> temp[i];
        a[i] = temp[i];
    }
    sort(temp,temp+(n+1));
    id = 1;
    for(i = 1;i<=n;i++){
        if(i == 1) mm[temp[i]] = id++;
        else {
            if(temp[i] != temp[i-1]) mm[temp[i]] = id++;
        }
    }   for(i = 1;i<=n;i++) a[i] = mm[a[i]];
       
    mm.clear();
    for(i = 1;i<=n;i++){
        mm[a[i]]++;
        pre[i] = mm[a[i]];
    }   mm.clear();
    for(i = n;i>=1;i--){
        mm[a[i]]++;
        post[i] = mm[a[i]];
    }
    for(i = 1;i<=n;i++){
        tm = sum(n) - sum(post[i]);
        res += tm;
        update(pre[i],1,n);
    }   cout << res << endl;
    return 0;
}




