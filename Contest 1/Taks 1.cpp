#include <iostream>

using namespace std;

int main(){
    int p, v, q, m, a_l, a_r, b_l, b_r, sum;
    sum = 0;
    cin >> p >> v >> q >> m;
    v = abs(v);
    m = abs(m);
    a_l = p - v;
    a_r = p + v;
    b_l = q - m;
    b_r = q + m;
    if (b_l < a_l){
        swap(a_l, b_l);
        swap(a_r, b_r);
        swap(p, q);
        swap(v, m);
    }
    if (a_r < b_l){
        sum = v*2 + m*2 + 2;
    }
    else if (b_r > a_r){
        sum = v*2 + m*2 + 2 - abs(b_l - a_r) - 1;
    }
    else{
        sum = v*2 + 1;
    }
    cout << sum;
    return 0;
}