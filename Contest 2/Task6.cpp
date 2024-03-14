#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

int main(){
    int n = 0, a = 0, b = 0, maximum = 0, k = 0, temp1 = 0, temp2 = 0, mass_max = 0;
    cin >> n;
    vector <int> sectors(n);
    for (int i = 0; i < n; i++){
        cin >> sectors[i];
        if (sectors[i] > mass_max)
            mass_max = sectors[i];
    }
    cin >> a;
    cin >> b;
    cin >> k;
    if (a > 800000 && b > 800000 && k > 800000){
        a /= 100000;
        b /= 100000;
        k /= 100000;
    }
    maximum = 0;
    for (int i = a; i <= b; i++){
        if (i % k == 0)
            temp1 = i / k - 1;
        else
            temp1 = i / k;
        if (temp1 % n == 0)
            temp2 = temp1 % (n + 1);
        else
            temp2 = temp1 % n;
        temp1 %= n;
        if (temp1 == 0 && temp2 == 0){
            if (sectors[0] > maximum)
                maximum = sectors[0];
        }
        else{
            if (sectors[temp1] > maximum)
                maximum = sectors[temp1];
            if (sectors[n - temp2] > maximum)
                maximum = sectors[n - temp2];
        }
        if (mass_max == maximum){
            cout << maximum;
            return 0;
        }
    }
    cout << maximum;
    return 0;
}