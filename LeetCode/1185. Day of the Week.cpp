class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        int x[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        string w[] = {"Wednesday", "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday"};
        int d = (year - 1969)*365 + (year - 1969)/4 + day - 1; 
        for(int i = 0; i < month - 1; i++)
            d += x[i];
        if(month >= 3 && year % 4 == 0 && year != 2100)
            d++;
        d = d%7;
        return w[d];
    }
};