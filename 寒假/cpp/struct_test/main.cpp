#include <iostream>
#include <cstring>
/*
*The cpp is easy, for practice the some struct in cpp
*/
using namespace std;
const int N = 20, M = 40;
const int MAX_NUM_OF_STUDENTS = 1000;
enum Sex {MAIL, FEMAIL};
struct Date
{
    int year;
    int month;
    int day;
};
enum Major {MATHEMATICS, PHYSICS, CHEMISTRY, COMPUTER, GEOGRAPHY, ASTRONOMY, ENGLISH, CHINESE, PHILOSOPHY};
struct Student
{
    int no;
    char name[N];
    Sex sex;
    Date birth_day;
    char birth_place[M];
    Major major;
};
Student students[MAX_NUM_OF_STUDENTS];
void display_student_info(Student s)
{
    cout << "学号：" << s.no << endl;
    cout << "姓名：" << s.name << endl;
    cout << "性别：" << s.sex << endl;
    cout << "生日：" << s.birth_day.year << s.birth_day.month << s.birth_day.day << endl;
    cout << "出生地:" << s.birth_place << endl;
    cout << "专业：";
    switch(s.major)
    {
        case MATHEMATICS: cout << "Mathematics"; break;
        /*
        *else switch
        */
        default: cout << "Error!"; break;
    }
    cout << endl;
}
int find_substr(char sub_str[], char str[])
{
    int len = strlen(str), sub_len = strlen(sub_str);
    for(int i = 0; i < len-sub_len; i++)
    {
        int j = 0;
        while(j < sub_len && sub_str[j] == str[i+j])
        {
            j++;
        }
        if(j == sub_len)
        {
            return i;
        }
    }
    return -1;
}
void bubble_sort(Student s[], int num)
{
    bool exchange;
    while(num > 1)
    {
        exchange = false;
        for(int i = 0; i < num-1; i++)
        {
            if(s[i].no > s[i+1].no)
            {
                Student tep = s[i];
                s[i] = s[i+1];
                s[i+1] = tep;
                exchange = true;
            }
        }
        if(!exchange)
        {
            break;
        }
        num--;
    }
}
int main()
{
    int num_of_students, count, i;
    /*
    *get the database from the keybord
    */
    cout << "Please the number of students" << endl;
    cin >> num_of_students;
    for(i = 0; i < num_of_students; i++)
    {
        cout << "No:";
        cin >> students[i].no;
        cout << "Name:";
        cin >> students[i].name;

    }
    count = 0;
    for(i = 0; i < num_of_students; i++)
    {
        if(students[i].major == COMPUTER && students[i].sex == MAIL)
        {
            count ++;
        }
    }
    cout << "the sum of MAIL in COMPUTER is:" << count << endl;
    count = 0;
    for(i = 0; i < num_of_students; i++)
    {
        if(find_substr("哈尔滨", students[i].birth_place) != -1)
        {
            count ++;
        }
    }
    cout << "the sum of student who was located in Harbin is:" << count << endl;
    bubble_sort(students, num_of_students);
    for(i = 0; i < num_of_students; i++)
    {
        display_student_info(students[i]);
    }
}
