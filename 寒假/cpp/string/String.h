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
        ~String()
        {
            delete []str;
            str = NULL;
        }
        int length()
        {
            return strlen(str);
        }
        char &char_at(int i)
        {
            if(i < 0 || i > strlen(str))
            {
                std::cout << "Is overflowing!" << std::endl;
                exit(-1);
            }
            return str[i];
        }
        const char *get_str()
        {
            return str;
        }
        String &copy(const char *p)
        {
            char *p1 = new char[strlen(p)+1];
            strcpy(p1, p);
            delete []str;
            str = p1;
            return *this;
        }
        String &copy(const String &s)
        {
            return copy(s.str);
        }
        String &append(const char *p)
        {
            char *p1 = new char[strlen(str)+strlen(p)+1];
            strcpy(p1, str);
            strcat(p1, p);
            delete []str;
            str = p1;
            return *this;
        }
        String &append(const String &s)
        {
            return append(s.str);
        }
        int compare(const char *p)
        {
            return strcmp(str, p);
        }
        int compare(const String &s)
        {
            return strcmp(str, s.str);
        }
};
