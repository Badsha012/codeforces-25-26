#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
int t;
cin>>t;
while(t--){
     long long  x,y,z;
    
    cin>>x>>y>>z;
    if(x==y){
        cout<<0<<endl;
        continue;
    }
    
    long long diff=llabs(x-y);
    //long long ans=(diff/2);
    long long result=(diff + 2*z -1) / (2*z);
    cout<<result<<endl;
 
    
   
    
}

    return 0;
}
