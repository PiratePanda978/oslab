#include <iostream>
using namespace std;
void processArr(int **a)
{
    int i;
    int j;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
// When calling:
int main()
{
    int i;
    int **array;
    array = new int *[10];
    for (i = 0; i < 10; i++)
        array[i] = new int[10];
    int j;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            array[i][j] = 1;
        }
    }
    processArr(array);
}
