class Vector
{
    int *p_data;
    int num;
    public:
        Vector(int n)
        {
            if(n < 0)
            {
                std::cout << "The data is error!" << std::endl;
                exit(-1);
            }
            else
            {
                num = n;
                p_data = new int[num];
            }
        }
        ~Vector()
        {
            delete []p_data;
        }
        int &element(int i)
        {
            if(i < 0 || i >= num)
            {
                std::cout << "The data is error!" << std::endl;
                exit(-1);
            }
            else
            {
                return *(p_data+i);
            }
        }
        int element(int i) const
        {
            if(i < 0 || i >= num)
            {
                std::cout << "The data is error!" << std::endl;
                exit(-1);
            }
            else
            {
                return *(p_data+i);
            }
        }
        int get() const
        {
            return num;
        }
        void display() const
        {
            int *p = p_data;
            for(int i = 0; i < num; i++)
            {
                std::cout << *p << " ";
            }
            std::cout << std::endl;
        }
};
