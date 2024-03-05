#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    int sum = 0;
    char a[7][7];
    char b[8][8];
    for (int i = 0; i < 8; i++){
        cin >> s;
        for (int j = 0; j < 8; j++){
            b[i][j] = s[j];
        }
    }
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if (b[i][j] == 'R'){
                int k = j;
                while (k > 0){
                    k--;
                    if (b[i][k] == 'R' || b[i][k] == 'B')
                        break;
                    b[i][k] = '1'; 
                }
                k = j;
                while (k < 7){
                    k++;
                    if (b[i][k] == 'R' || b[i][k] == 'B')
                        break;
                    b[i][k] = '1';
                }
                k = i;
                while (k > 0){
                    k--;
                    if (b[k][j] == 'R' || b[k][j] == 'B')
                        break;
                    b[k][j] = '1';
                }
                k = i;
                while (k < 7){
                    k++;
                    if (b[k][j] == 'R' || b[k][j] == 'B')
                        break;
                    b[k][j] = '1';
                }
            }
            else if (b[i][j] == 'B'){
                int x = i, y = j;
                while (x > 0 && y > 0){
                    x--;
                    y--;
                    if (b[x][y] == 'R' || b[x][y] == 'B')
                        break;
                    b[x][y] = '1';
                }
                x = i, y = j;
                while (x > 0 && y < 7){
                    x--;
                    y++;
                    if (b[x][y] == 'R' || b[x][y] == 'B')
                        break;
                    b[x][y] = '1';
                }
                x = i, y = j;
                while (x < 7 && y > 0){
                    x++;
                    y--;
                    if (b[x][y] == 'R' || b[x][y] == 'B')
                        break;
                    b[x][y] = '1';
                }
                x = i, y = j;
                while(x < 7 && y < 7){
                    x++;
                    y++;
                    if (b[x][y] == 'R' || b[x][y] == 'B')
                        break;
                    b[x][y] = '1';
                }
            }
        }
    }
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            //cout << b[i][j];
            if (b[i][j] == '*')
                sum++;
        }
        //cout << endl;
    }
    cout << sum;
    return 0;
}