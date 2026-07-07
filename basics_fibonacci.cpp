#include <iostream>
using namespace std;
int fib_old(int n ){
    if(n==0 || n==1) return n;
    return fib_old(n-1) + fib_old(n-2);
}
int fib(int n ,int *arr)
{
    if(n==0||n==1) return n;
    if(arr[n]) return arr[n];
    int output = fib(n-1,arr) + fib(n-2,arr);
    arr[n] = output;
return output;
}
// iterative approach 
int fib2(int n)
{
    int *arr = new int[n+1];
        arr[0] =0 ;
        arr[1] =1;
        for(int i =2;i<=n;i++) {
            arr[i] = arr[i-1] + arr[i-2];
        }
        // we have allcated dynamic memory so we have to free it 
        int output = arr[n];
        delete []arr;
        return output;

}
int main() {
    // creating the array
    int n ;
    cin>>n;
        int *arr = new int[n+1];
    for(int i =0;i<=n;i++) arr[i]=0;
cout<<"output from recursive sol  "<<fib(n,arr);
cout<<"\noutput from iterative sol "<<fib2(n)<<"\n";
cout<<"solution from old fibonacci number is "<<fib_old(n);
    return 0;
}