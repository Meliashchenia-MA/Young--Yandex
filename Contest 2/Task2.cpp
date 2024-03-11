#include <iostream>
#include <vector>

using namespace std;

int main() {
    int k, n, max = 0, ind = 0;
    cin >> n >> k;
    vector <int> a(n);
    cin >> a[0];
    if (n == 1){
        cout << 0;
        return 0;
    }
    for (int i = 1; i < n; i++){
        cin >> a[i];
    }
    int i = 0;
    while(i < n){
        while(i - ind < k){
            i++;
            if(i >= n)
                break;
            if (a[i] - a[ind] > max){
                max = a[i] - a[ind];
            }
        }
        ind++;
        if (ind >= n)
            break;
        i = ind;
    }
    cout << max;
    return 0;
}
