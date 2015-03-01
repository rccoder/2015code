class Matrix
{
    int *p_data;
    int row, col;
    public:
        Matrix(int r, int c)
        {
            if(r <= 0 || c <= 0)
            {
                std::cout << "The data is error!" << std::endl;
                exit(-1);
            }
            row = r;
            col = c;
            p_data = new int[row*col];
        }
        ~Matrix()
        {
            delete []p_data;
        }
        int &element(int i, int j)
        {
            if(i < 0 || i >= row || j < 0 || j >= col)
            {
                std::cout << "The data is error!" << std::endl;
                exit(-1);
            }
            else
            {
                return *(p_data+i*col+j);
            }
        }
        int element(int i, int j) const
        {
            if(i < 0 || i >= row || j < 0 || j >= col)
            {
                std::cout << "The data is error!" << std::endl;
                exit(-1);
            }
            else
            {
                return *(p_data+i*col+j);
            }
        }
        int get_row() const
        {
            return row;
        }
        int get_col() const
        {
            return col;
        }
        void display() const
        {
        int *p = p_data;
            for(int i = 0; i < row; i++)
            {
                for(int j = 0; j < col; j++)
                {
                    std::cout << *p << " ";
                }
                std::cout << std::endl;
            }
        }
};
