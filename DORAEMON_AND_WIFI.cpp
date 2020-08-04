//BISMILLAH
#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x,long long int n){
    long long int r = 1;
    while(n!=0){
        if(n%2 == 1){
            r = r * x;
            n--;
        }
        else{
            x = x * x;
            n = n/2;
        }
    }
    return r;
}
long long int fact(long long int n){
    if(n == 0 || n == 1) return 1;
    return n*fact(n-1);
}
 long long int NPR(long long int n,long long int r){
     return fact(n)/fact(n-r);
 }
int main(){
    long long int i,j,tik = 0,sum1 = 0,plus = 0,minus = 0,sum2 = 0,left,p,m;
    double res;
    string s1,s2;
    cin >> s1;
    cin >> s2;
    long long int len = s1.size();
    for(i = 0;i<len;i++){
        if(s1[i] == '+') sum1++;
        else sum1--;
    }
    for(i = 0;i<len;i++){
        if(s2[i] == '?') tik++;
        else{
            if(s2[i] == '+') sum2++;
        else sum2--;
        }
    }
    if(tik == 0){
        if(sum1 == sum2) cout << "1.000000000000" << endl;
        else cout << "0.000000000000" << endl;
    }
    else{
        int flag = 0;
        left = sum1 - sum2;
        p = tik;
        m = 0;
        while(1){
            if(p + m == left) {
                flag = 1;
                break;
            }
            if(p == 0) break;
                p--;
                m--;
        }
        if(flag == 0) cout << "0.000000000000" << endl;
        else if(flag == 1){
            long long int al = power(2,tik);
            long long int re = NPR(tik,p)/fact(p);
               res = (re * 1.0)/al;
               printf("%.12lf\n",res);
        }
    }
    return 0;
}






