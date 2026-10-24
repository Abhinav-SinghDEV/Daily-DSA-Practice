class Solution {
public:
    int countDaysTogether(string a, string b, string c, string d) {
        int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};

        int x = stoi(a.substr(0,2)), y = stoi(a.substr(3,2));
        int p = stoi(b.substr(0,2)), q = stoi(b.substr(3,2));
        int r = stoi(c.substr(0,2)), s = stoi(c.substr(3,2));
        int t = stoi(d.substr(0,2)), u = stoi(d.substr(3,2));

        for(int i = 0; i < x-1; i++) y += days[i];
        for(int i = 0; i < p-1; i++) q += days[i];
        for(int i = 0; i < r-1; i++) s += days[i];
        for(int i = 0; i < t-1; i++) u += days[i];

        int start = max(y, s);
        int end = min(q, u);

        return max(0, end - start + 1);
    }
};
