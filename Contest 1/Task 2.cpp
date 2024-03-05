#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    int g1, g2, t1, t2, k, v1, v2;
    cin >> s;
    g1 = s[0] - '0';
    g2 = s[2] - '0';
    cin >> s;
    t1 = s[0] - '0';
    t2 = s[2] - '0';
    cin >> k;
    if (k == 1){
        v1 = t1;
        v2 = g2;
        if (g1 + t1 > g2 + t2 || (g1 + t1 == g2 + t2) && v1 > v2)
            cout << 0;
        else if (g1 + t1 == g2 + t2){
            cout << 1;
        }
        else{
            if (v2 - v1 < g2 + t2 - g1 - t1){
                cout << g2 + t2 - g1 - t1;
            }
            else{
                cout << g2 + t2 - g1 - t1 + 1;
            }
        }
    }
    else{
        v1 = g1;
        v2 = t2;
        if (g1 + t1 > g2 + t2 || (g1 + t1 == g2 + t2) && v1 > v2)
            cout << 0;
        else if (g1 + t1 == g2 + t2){
            cout << 1;
        }
        else{
            if (v2 >= v1){
                cout << g2 + t2 - g1 - t1 + 1;
            }
            else 
                cout << g2 + t2 - g1 - t1;
        }
    }
    return 0;
}