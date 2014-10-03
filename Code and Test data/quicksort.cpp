#include <iostream>
#include <cstdlib>
using namespace std;

int A[] = {5, 6, 54, 45, 18, 12, 91};

void quicksort (int l, int u)
{
    cout << "Quick sort " << l << " " << u << endl;
    int pivot, b;
    if (u-l <= 1)
    {
        return;
    }
    else
    {
        pivot = l;
        b = pivot+1;
        for (int i = l+1; i < b;)
        {
            if (A[i] <= A[l])
            {
                swap (A[i], A[b]);
                ++b;
            }
            ++i;
        }
        swap (A[l], A[b-1]);
        quicksort(b, u);
        quicksort (l, b-1);

    }

}


int main ()
{
    quicksort(0, 6);

    //swap (A[0], A[6]);

    for (int i = 0; i < 7; ++i)
    {
        cout << A[i] << endl;
    }

    return 0;
}
