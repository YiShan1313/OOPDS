#include <iostream>
using namespace std;

static const int row = 20;
static const int col = 20;

class field
{
    char grid[row][col];

    public:
        field()
        {
            for (int i = 0; i < row; i++)
            {

                for (int j = 0; j < col; j++)
                {
                    grid[i][j] = ' ';
                }
            }
        }

        void place(string name, int posx, int posy)
        {
            if (posx >= 0 && posx < row && posy >= 0 && posy < col && !name.empty())
            {
                char test = name[0];
                grid[posx][posy] = test;
            }
        }

        void display()
        {
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    if (grid[i][j] == ' ')
                    {
                        cout << " * ";
                    }

                    else
                    {
                        cout << " " << grid[i][j] << " ";
                    }
                }
                cout << endl;
            }
        }
};

class movement
{
    
};

int main()
{
    field test;
    test.place("zeno", 5, 5);
    test.place("ali", 7, 5);
    test.display();
    return 0;
}
