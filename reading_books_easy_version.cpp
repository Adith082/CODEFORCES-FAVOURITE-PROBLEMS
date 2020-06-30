//BISMILLAH
#include <bits/stdc++.h>
using namespace std;
struct edge{
   long long int t;  
   long long int a;
   long long int b;
};
 vector <edge> grp1;
 vector <edge> grp2;
 vector <edge> grp3;
 bool cmp(edge A,edge B){
     return A.t < B.t;
 }
int main(){
    edge get;
    long long int n,k,i,j,temp,aa,bb,tt,cnt1,cnt2,len1,len2,len3,res,dd;
    cnt1 = 0;
    res = 0;
    cnt2 = 0;
    cin >> n >> dd;
    for(i = 0;i<n;i++){
        cin >> tt >> aa >> bb;
        if(aa == 1) cnt1++;
        if(bb == 1) cnt2++;
            get.t = tt;
            get.a = aa;
            get.b = bb;
        if(a == 1 && b == 1){
            grp3.push_back(get);
        }
        else if(a == 1 && b == 0){
            grp1.push_back(get);
        }
        else if(a == 0 && b == 1){
            grp2.push_back(get);
        }
    }
    if(cnt1 < dd || cnt2 < dd)  cout << -1 << endl;
    else{
        sort(grp1.begin(),grp1.end(),cmp);
        sort(grp2.begin(),grp2.end(),cmp);
        sort(grp3.begin(),grp3.end(),cmp);
        len1 = grp1.size();
        len2 = grp2.size();
        len3 = grp3.size();
        i = 0;
        j = 0;
        k = 0;
        cnt1 = 0;
        cnt2 = 0;
        while(1){
            if(i<len1 &&  j<len2 && k<len3){
                temp = grp3[k].t;
                aa = grp1[i].t;
                bb = grp2[j].t;
                if(temp <= (aa + bb)){
                    res += temp;
                    k++;
                    cnt1++;
                    cnt2++;
                }
                else{
                    res += (aa + bb);
                    i++;
                    j++;
                    cnt1++;
                    cnt2++;
                }
                if(cnt1 == dd && cnt2 == dd) break;
            }
            else if(i<len1 && j <len2){
                aa = grp1[i].t;
                bb = grp2[j].t;
                res += (aa + bb);
                cnt1++;
                cnt2++;
                i++;
                j++;
                if(cnt1 == dd && cnt2 == dd) break;
            }
            else {
                 temp = grp3[k].t;
                 res += temp;
                 cnt1++;
                 cnt2++;
                 k++;
                 if(cnt1 == dd && cnt2 == dd) break;
            }
        }
        cout << res << endl;
    }
    return 0;
}





