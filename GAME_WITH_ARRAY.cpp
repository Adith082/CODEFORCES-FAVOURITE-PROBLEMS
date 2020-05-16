//BISMILLAH
#include <bits/stdc++.h>
using namespace std;
unordered_map <long long int ,long long int> mm;
int main(){
   long long int i,j,n,s,k,temp,sum;
   cin >> n >> s;
   sum = 0;
   k = -1;
   mm[0] = 1;
   mm[s] = 1;
   long long int a[n];
   temp = s - (n-1);
   for(i = 0;i<n;i++) a[i] = 1;
   a[n-1] = temp;
   for(i = 0;i<n;i++){
       sum = sum + a[i];
       mm[sum] = 1;
       mm[s-sum] = 1;
   }
   for(i = 0;i<=s;i++){
       if(mm[i] == 0) {
           k = i;
           break;
       }
   }
   if(k == -1) cout << "NO" << endl;
   else if(k != -1){
       cout << "YES" << endl;
       for(i = 0;i<n;i++) {
           cout << a[i] << " ";
       }
       cout << endl;
       cout << k << endl;
   }
     mm.clear();
    return 0;
}