class String
{
    char *str;
    public:
        String()
        {
            str = NULL;
        }
        String(const char *p)
        {
            str = new char[strlen(p)+1];
            strcpy(str, p);
        }
        String (const String &s)
        {
            str = new char[strlen(s.str)+1];
            strcpy(str, s.str);
        }
        ~String()
        {
            delete []str;
            str =  NULL;
        }
        int length() const
        {
            return strlen(str);
        }
        char& operator [](int i)
        {
            if(i < 0 || i >= strlen(str))
            {
                std::cout << "Error!(yuejie)" << std::endl;
                exit(-1);
            }
            else
                return str[i];
        }
        char operator [](int i) const
        {
            if(i < 0 || i >= strlen(str))
            {
                std::cout << "Error!(yuejie)" << std::endl;
                exit(-1);
            }
            else
                return str[i];
        }
        operator const char*() const
        {
            return str;
        }
        String &operator = (const char *p)
        {
            char *p1 = new char[strlen(p)+1];
            strcpy(p1, p);
            delete []str;
            str = p1;
            return *this;
        }
        String &operator = (const String &s)
        {
            if(&s != this)
                *this = s.str;
            return *this;
        }
        String &operator += (const char *p)
        {
            char *p1 = new char[strlen(p)+1];
            strcpy(p1, str);
            strcat(p1, p);
            delete []str;
            str = p1;
            return *this;
        }
        String &operator += (const String &s)
        {
            *this += s.str;
            return *this;
        }

        /*
        String &operator + (const char *p1, const char *p2)
        {
            char *p3 = new char[strlen(p1)+strlen(p2)+2];
            strcpy(p3, p1);
            strcat(p3, p2);
            str = p3;
            return *this;
        }
        String &operator + (const String &s1, const String &s2)
        {
            *this = s1.str+s2.str;
            return *this;
        }
        */
    friend bool operator == (const String &s1, const String &s2);
    friend bool operator == (const String &s, const char *p);
    friend bool operator == (const char *p, const String &s);

};
