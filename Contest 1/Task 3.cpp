#include <iostream>
#include <string>

using namespace std;

long long int prob(long int n){
    long long int temp = n / 4;
    if (n - temp * 4 == 0)
        return temp;
    else if (n - temp * 4 == 3)
        return temp + 2;
    else 
        return n - temp * 4 + temp;
}

int main(){
    long long int n, temp, sum;
    sum = 0;
    n = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> temp;
        sum += prob(temp);
    }
    cout << sum;
    return 0;
}