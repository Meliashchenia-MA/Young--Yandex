#include <iostream>
#include <cmath>

using namespace std;

long int find_del(long int x, long int n){
    for (int i = 0; i < 10; i++){
        if ((x * 10 + i) % n == 0){
            return x * 10 + i;
        }
    }
    return 0;
}

int main(){
    long n, k, d;
    cin >> n >> k >> d;
    long int x = find_del(n, k);
    if (x){
        cout << x;
        for (int i = 0; i < d - 1; i++)
            cout << 0;
    }
    else
        cout << -1;
    return 0;
}