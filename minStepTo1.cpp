#include <iostream>
using namespace std;
// Implementing bottom up dp
int min_step3(int n )
{
    int *dp = new int[n+1];
    dp[0] = 0;
    dp[1] =0;
for(int i =2;i<=n;i++)
{
    int x = dp[i-1];
      int y, z;
    z = y = INT_MAX;
    if (i % 2 == 0)
       y = dp[i/2];
    if (i% 3 == 0)
      z =  dp[i/3];
    dp[i] = min(x, min(y, z)) + 1;

}
int ans = dp[n];
delete []dp;
return ans;
}
int helper(int n, int *a)
{
    if (n <= 1)
        return 0;
    if (a[n] != -1)
        return a[n];
    int x = helper(n - 1, a);
    int y, z;
    z = y = INT_MAX;
    if (n % 2 == 0)
       y = helper(n / 2, a);
    if (n % 3 == 0)
      z =  helper(n / 3, a);
    int ans = min(x, min(y, z)) + 1;
    a[n] = ans;
    return ans;
}
int min_steps2(int n)
{
    int *a = new int[n + 1];
    for (int i = 0; i <= n; i++)
        a[i] = -1;

    int ans = helper(n, a);
    return ans;
}

int min_steps(int n)
{
    if (n <= 1)
        return 0;
    int x = min_steps(n - 1);
    int y, z;
    y = z = INT_MAX;
    if (n % 2 == 0)
        y = min_steps(n / 2);
    if (n % 3 == 0)
        z = min_steps(n / 3);
    int ans = min(x, min(y, z)) + 1;
    return ans;
}
int main()
{
    int n;
    cin >> n;
    cout << min_steps2(n) << "\n";
    cout << min_steps(n) << "\n";
cout<<min_step3(n)<<"\n";
    return 0;
}