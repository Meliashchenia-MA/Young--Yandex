#include <iostream>
#include <vector>

using namespace std;

pair <int, int> maximums(vector <vector <int>> a, int x, int y){
    int max1 = 0, max2 = 0;
    int n = a.size();
    int m = a[0].size();
    for (int i = 0; i < n; i++){
        if (i == x)
            continue;
        for (int j = 0; j < m; j++){
            if (j == y)
                continue;
            if (a[i][j] > max1){
                max2 = max1;
                max1 = a[i][j];
                continue;
            }
            if (a[i][j] > max2){
                max2 = a[i][j];
            }
        }
    }
    pair <int, int> p = make_pair(max1, max2);
    return p;
}

int main(){
    int n, m, temp, maxi, maxj, max1i, max1j;
    cin >> n >> m;
    vector <vector <int>> a(n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> temp;
            a[i].push_back(temp);
        }
    }
    maxi = 0;
    maxj = 0;
    max1i = -1;
    max1j = -1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (a[i][j] > a[maxi][maxj]){
                max1i = maxi;
                max1j = maxj;
                maxi = i;
                maxj = j;
            }
            else if (max1i == -1){
                if (i != 0 || j != 0){
                    max1i = i;
                    max1j = j;
                }
            }
            else{
                if (a[max1i][max1j] < a[i][j]){
                    max1i = i;
                    max1j = j;
                }
            }
        }
    }
    int x = 0, y = 0;
    if (maxi == max1i){
        x = maxi;
        temp = 0;
        for (int i = 0; i < n; i++){
            if (i == x)
                continue;
            for (int j = 0; j < m; j++){
                if (a[i][j] > temp){
                    temp = a[i][j];
                    y = j;
                }
            }
        } 
    }
    else if (maxj == max1j){
        y = maxj;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (j == y)
                    continue;
                if (a[i][j] > temp){
                    temp = a[i][j];
                    x = i;
                }
            }
        }
    }
    else{
        pair <int, int> p1, p2;
        p1 = maximums(a, maxi, max1j);
        p2 = maximums(a, max1i, maxj);
        if (p1.first <= p2.first){
            x = maxi;
            y = max1j;
        }
        else{
            x = max1i;
            y = maxj;
        }
    }
    cout << x + 1 << ' ' << y + 1;
    return 0;
}
