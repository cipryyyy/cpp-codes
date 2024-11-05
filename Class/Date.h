#ifndef Date_h
#define Date_h

namespace DateNamespace {
    enum Months {
        gen=1, feb, mar, apr, mag, giu, lug, ago, set, ott, nov, dic
    };
    class Date {
        int y{1970};
        int m{gen};
        int d{1};
    public:
        Date() {}
        Date(int yy) : y{yy} {}
        Date(int yy, int mm, int dd) :  y{yy}, m{mm}, d{dd} {}
        
        friend inline void addDay(Date& date, int n);
        friend std::ostream& operator<<(std::ostream& os, const Date& date);
        int day() {return d;}
        int month() {return m;}
        int year() {return y;}
    };

    inline void addDay(Date& date, int n) {
        date.d += n;
    }
    std::ostream& operator<<(std::ostream& os, const Date& date) {
        os << date.y << "/" << date.m << "/" << date.d;
        return os;
    }
}
#endif /* Date_h */
