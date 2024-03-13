#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, max, sum = 0;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    max = 0;
    for (int i = 0; i < n; i++){
        if (a[i] > max){
            sum += max;
            max = a[i];
        }
        else{
            sum += a[i];
        }
    }
    if (max > sum)
        cout << max - sum;
    else
        cout << max + sum;
    return 0;
}