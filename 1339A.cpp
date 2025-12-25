#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[55];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        bool k=true;
        for(int i=1;i<n;i++){
            if(a[i]-a[i-1]>1){
                k=false;
                break;
            }

        }
        if(k)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}