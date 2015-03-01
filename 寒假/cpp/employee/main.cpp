#include <iostream>
#include <cstdlib>
#include <cstring>
#include "String.h"
#include "Employee.h"

using namespace std;

const int MAX_NUM_OF_EMPS = 20;

class Manager: public Employee
{
    Employee *group[MAX_NUM_OF_EMPS];
    int num_of_emps;
public:
    Manager(const char *s, int n = 0):Employee(s, n)
    {
        num_of_emps = 0;
    }
    Employee *add_employee(Employee *e)
    {
        if(num_of_emps > MAX_NUM_OF_EMPS)
        {
            return NULL;
        }
        group[num_of_emps] = e;
        num_of_emps++;
        return e;
    }
    Employee *remove_employee(Employee *e)
    {
        for(int i = 0; i < num_of_emps; i++)
        {
            if(e->get_name() == group[i]->get_name())
                break;
            if(i < num_of_emps)
            {
                for(int j = i+1; j < num_of_emps; j++)
                {
                    group[j-1] = group[j];
                    num_of_emps--;
                    return e;
                }
            }
            else
                return NULL;
        }
    }
};
int main()
{
    Employee e1("Jack", 1000), e2("rccoder", "2000");
    Manager m("Mark", 1000);
    m.add_employee(&e1);
    m.add_employee(&e2);
    return 0;
}
