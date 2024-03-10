#include <iostream>
#include <vector>
#include <map>

using namespace std;

int vis(int n){
    if (n % 4 == 0){
        if (n % 400 == 0){
            return 1;
        }
        else{
            if (n % 100 == 0)
                return 0;
            return 1;
        }
    }
    return 0;
}

int main() {
    int n, year, h_day, date, first_day, max, min;
    string s, date_month;
    cin >> n;
    cin >> year; 
    map <string, int> months;
    map <string, int> holidays;
    map <string, int> days;
    vector <pair <int, string>> holiday_dates;
    vector <string> week_days = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    vector <string> months_order = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    months["January"] = 31;
    months["February"] = 28 + vis(year);
    months["March"] = 31;
    months["April"] = 30;
    months["May"] = 31;
    months["June"] = 30;
    months["July"] = 31;
    months["August"] = 31;
    months["September"] = 30;
    months["October"] = 31;
    months["November"] = 30;
    months["December"] = 31;
    for (auto c : week_days){
        holidays[c] = 0;
        days[c] = 0;
    }
    for (int i = 0; i < n; i++){
        cin >> date;
        cin >> date_month;
        pair <int, string> p;
        p.first = date;
        p.second = date_month;
        holiday_dates.push_back(p);
    }
    cin >> s;
    for (int i = 0; i < 7; i++){
        if (s == week_days[i]){
            first_day = i;
            break;
        }
    }
    for (int i = 0; i < 7; i++){
        if (days[week_days[i]] == 53)
            continue;
        if (week_days[i] == s){
            if (!vis(year)){
                days[week_days[i]] = 53;
                continue;
            }
            else{
                days[week_days[i]] = 53;
                if (i == 6){
                    days[week_days[0]] = 53;
                }
                else{
                    days[week_days[i + 1]] = 53;
                }
                continue;
            }
        }
        days[week_days[i]] = 52;
    }
    for (auto c : holiday_dates){
            int j = 0, days_sum = 0;;
            date = c.first;
            date_month = c.second;
            while(months_order[j] != date_month){
                days_sum += months[months_order[j]];
                j++;
            }
            days_sum += date - 1;
            days_sum = days_sum % 7;
            int l = first_day + days_sum;
            if (l > 6)
                l -= 7;
            holidays[week_days[l]] += 1;
        }
    for (auto d : days){
        for (auto k : holidays){
            if (d.first != k.first){
                days[d.first] += k.second;
            }
        }
    }
    min = days["Monday"];
    max = days["Monday"];
    string best, worst;
    best = "Monday";
    worst = "Monday";
    for (auto d : days){
        if (d.second < min){
            worst = d.first;
            min = d.second;
        }
        if (d.second > max){
            best = d.first;
            max = d.second;
        }
    }
    cout << best << ' ' << worst;
    return 0;
}