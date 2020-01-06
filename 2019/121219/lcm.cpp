#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

// Returns LCM of array elements
int lcm(int arr[], int n){
    // Initialize result
    int ans = arr[0];

    // ans contains LCM of arr[0], ..arr[i]
    // after i'th iteration,
    for(int i=1; i<n; i++)
        ans = (((arr[i] * ans)) / (gcd(arr[i], ans)));

    return ans;
}

int main(){
    int arr[3] = {4, 5, 6};

    cout << lcm(arr, 3);

    return 0;
}