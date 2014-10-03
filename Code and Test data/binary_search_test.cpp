#include <iostream>

using namespace std;

int array [] = {6,5,4,2,1};
int num = 3;




int find_position (int num, int * sorted_array, int right) //here array will be sorted in reverse order
{
    int left, pivot;
    left = 0;
    if (num < sorted_array[right])
    {
           return right+1;
    }
    else if (num > sorted_array[0])
    {
        return 0;
    }

    for (;;)
    {
        pivot = int (long(right + left )/2);

        if (sorted_array[pivot] == num)
        {
            return pivot;
        }
        else if ((right - left) == 1)
        {
            return right;
        }
        else if (num < sorted_array[pivot])
        {
            left = pivot;
        }
        else if (num > sorted_array[pivot])
        {
            right = pivot;
        }
    }


}

int main ()
{
    cin >> num;
    cout << find_position(num,array,4);
    return 0;
}
