#include <iostream>

using namespace std;

int main(){
    int prev, temp, n;
    cin >> n;
    cin >> prev;
    if (abs(prev) % 2 == 1)
        prev = 1;
    else
        prev = 0;
    for (int i = 0; i < n - 1; i++){
        cin >> temp;
        if (abs(temp) % 2 == 1){
            temp = 1;
            if (prev){
                cout << 'x';
                temp = 1;
            }
            else{
                cout << '+';
                temp = 1;
            }
        }
        else{
            temp = 0;
            if (prev){
                cout << '+';
                temp = 1;
            }
            else{
                cout << 'x';
                temp = 0;
            }
        }
        prev = temp;
    }
    return 0;
}