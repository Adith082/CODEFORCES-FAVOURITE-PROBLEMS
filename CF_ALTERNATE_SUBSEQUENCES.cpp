//BISMILLAH
#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int n,i,j,t,v;
    long long int maxx = INT_MIN,cnt = 0;
    long long int sum = 0;
    stack <long long int > s;
    cin >> t;
    while(t--)
    {
        maxx = INT_MIN;
        cnt = 0;
        sum = 0;
        cin >> n;
    long long int a[n];
    for(i = 0;i<n;i++) {
        cin >> a[i];
        maxx = max(maxx,a[i]);
        if(a[i] > 0) cnt++;
    }
    if(cnt == n || cnt == 0) cout << maxx << endl;
    else{
        for(i = 0;i<n;i++){
            if(s.empty() == 1) s.push(a[i]);
            else{
                v = s.top();
                if(v > 0 && a[i] < 0) s.push(a[i]);
                else if(v < 0 && a[i] > 0) s.push(a[i]);
                else {
                    s.pop();
                    s.push(max(v,a[i]));
                }
            }
        }
        while(!s.empty()){
            sum += s.top();
            s.pop();
        }
        cout << sum << endl;
    }
    }
    return 0;
}


