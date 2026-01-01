
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        if(n%2==0)cout<<"YES"<<endl;
    
        else if(k%2==1 && n>=k)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }


    return 0;
}