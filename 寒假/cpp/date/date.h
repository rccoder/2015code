class date
{
    public:
        void set(int y, int m, int d);
        bool is_leap_year();
        void print();
    private:
        int year, month, day;
};
void date::set(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
}
bool date::is_leap_year()
{
    return (year%4 == 0 && year%100 != 0) || year%400 == 0;
}
void date::print()
{
    cout << year << "." << month << "." << day <<endl;
}
