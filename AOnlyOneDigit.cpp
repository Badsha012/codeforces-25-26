
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        int ans=9;
        while(x>0){
            int digit =x%10;
            ans =min(ans,digit);
            x/=10;
            
        }
        cout<<ans<<endl;
      
     
    }


    return 0;
}