#include <iostream>
using namespace std;
int min_staircase(int n )
{
    if(n==0) return 1;
    return min_staircase(n-1)+min_staircase(n-2);
}
// iterative solution
int min_st2(int n )

{
    int *dp = new int[n+1];
        dp[0] =1; //means there is only way do not do anything
        dp[1] =1;
        for(int i =2;i<=n;i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        int ans  = dp[n];
        delete []dp;
        return ans;
}
int main() {
int n ;
cin>>n;
cout<<min_staircase(n)<<"\n";
    return 0;
}