//BISMILLAH
#include <bits/stdc++.h>
using namespace std;
int main(){
    
    long long int i,j,t,n,sum,maxx = -1;
    cin >> n >> t;
    long long int a[n];
    for(i = 0;i<n;i++) cin >> a[i];
    i = 0;
    j = -1;
    sum = 0;
    for(i = 0;i<n;i++){
        if(sum <= t)
        {do{ 
            j++;
            sum += a[j];
        }while(j<n && sum <= t);
        }
        maxx = max(maxx,(j) - i);
        sum = sum - a[i];
    }
      cout << maxx << endl;
    return 0;
}
