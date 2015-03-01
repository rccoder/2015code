class Employee
{
    String name;
    int salary;
    public:
        Employee(const char *s, int n = 0):name(s)
        {
            salary = n;
        }
        void set_salary(int n)
        {
            salary = n;
        }
        int get_salary() const
        {
            return salary;
        }
        String get_name() const
        {
            return name;
        }
};
