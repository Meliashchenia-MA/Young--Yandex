#include <iostream>

using namespace std;

int main() {
    int k, x, y, minx, maxx, miny, maxy;
    cin >> k;
    if (k == 1){
        cin >> x >> y;
        cout << x << ' ' << y << ' ' << x << ' ' << y;
        return 0;
    }
    cin >> x >> y;
    minx = x;
    maxx = x;
    miny = y;
    maxy = y;
    for (int i = 1; i < k; i++){
        cin >> x >> y;
        if (x > maxx)
            maxx = x;
        if (x < minx)
            minx = x;
        if (y > maxy)
            maxy = y;
        if (y < miny)
            miny = y;
    }
    cout << minx << ' ' << miny << ' ' << maxx << ' ' << maxy;
    return 0;
}
