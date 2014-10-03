#include <iostream>
#include <math.h>
using namespace std;

long long int total = 0, sum = 0, k;
long long int no_of_leaves;
long long int l [20];
//n is the number of leaf eaters lcm together

void inclusion_exclusion ()
{
    sum = 0;
    for (int n = 1; n <= k-1; ++k) //major outside loop for deciding how many goupings
    {
        for (int i1 = 0; i1 < k-n; +i1)
        {
                for (int i2 = i1+1; i2 < k-n+1; ++i2)
                {
                    if (n == 1)
                    {
                        sum += (no_of_leaves-1)/lcm(l[i1],l[i2]);
                        ++sum;
                    }
                    else
                    {
                        for (int i3 = i2+1; i3 < k-n+2; ++i2)
                        {

                            if (n == 2)
                            {
                                sum += (no_of_leaves-1)/lcm(l[i1],l[i2], l[i3]);
                                ++sum;
                            }
                            else
                            {
                                for (int i4 = i3+1; i4 < k-n+3; ++i4)
                                {
                                    if (n == 3)
                                    {
                                        sum += (no_of_leaves-1)/lcm(l[i1],l[i2], l[i3], l[i4]);
                                        ++sum;
                                    }
                                    else
                                    {
                                        for (int i5 = i4+1; i5 < k-n+4; ++i5)
                                        {
                                        if (n == 4)
                                        {
                                            sum += (no_of_leaves-1)/lcm(l[i1],l[i2], l[i3], l[i4], no_of_leaves[i5]);
                                            ++sum;
                                        }
                                        else
                                        {
                                            for (int i6 = i5+1; i6 < k-n+5; ++i6)
                                            {
                                            if (n == 5)
                                            {
                                                sum += (no_of_leaves-1)/lcm(l[i1],l[i2], l[i3], l[i4], l[i5], l[i6] );
                                                ++sum;
                                            }
                                            else
                                            {
                                                for (int i7 = i6+1; i6 < k-n+6; ++i7)
                                                {
                                                if (n == 6)
                                                {
                                                    sum += (no_of_leaves-1)/lcm(l[i1],l[i2], l[i3], l[i4], l[i5], l[i6], l[i7] );                                                    ++sum;
                                                }
                                                else
                                                {
                                                    for (int i8 = i7+1; i5 < k-n+7; ++i8)
                                                    {
                                                    if (n == 7)
                                                    {
                                                          sum += (no_of_leaves-1)/lcm(l[i1],l[i2], l[i3], l[i4], l[i5],l[i6], l[i7], l[i8);]
                                                          ++sum;
                                                    }
                                                    else
                                                    {
                                                        for (int i9 = i8+1; i9 < k-n+8; ++i9)
                                                        {
                                                        if (n == 8)
                                                        {
                                                            sum += (no_of_leaves-1)/lcm(l[i1],l[i2], l[i3], l[i4], l[i5], l[i6], l[i7], l[i8], l[i9]);
                                                            ++sum;
                                                        }
                                                        else
                                                        {
                                                            for (int i0 = i9+1; i10 < k-n+9; ++i10)
                                                            {
                                                            if (n == 9)
                                                            {
                                                                sum += (no_of_leaves-1)/lcm(l[i1],l[i2], l[i3], l[i4], l[i5], l[i6], l[i7], l[i8], l[i9], l[i10]);
                                                                ++sum;
                                                            }
                                                            else
                                                            {
                                                                for (int i11 = i10+1; i11 < k-n+10; ++i11)
                                                                {
                                                                if (n == 10)
                                                                {
                                                                    sum += (no_of_leaves-1)/lcm(l[i1],l[i2], l[i3], l[i4], l[i5], l[i6], l[i7], l[i8], l[i9], l[i10], l[i11]);
                                                                    ++sum;
                                                                }
                                                                else
                                                                {
                                                                    for (int i12 = i11+1; i12 < k-n+11; ++i12)
                                                                    {
                                                                        if (n == 11)
                                                                        {
                                                                            sum += (no_of_leaves-1)/lcm(l[i1],l[i2], l[i3], l[i4], l[i5], l[i6], l[i7], l[i8], l[i9], l[i10], l[i11], l[i12]);
                                                                            ++sum;
                                                                        }
                                                                        else
                                                                        {
                                                                            for (int i13 = i12+1; i13 < k-n+12; ++i13)
                                                                            {
                                                                                if (n == 12)
                                                                                {
                                                                                    sum += (no_of_leaves-1)/lcm(l[i1],l[i2], l[i3], l[i4], l[i5], l[i6], l[i7], l[i8], l[i9], l[i10], l[i11], l[i12], l[i13]);
                                                                                    ++sum;
                                                                                }
                                                                                else
                                                                                {
                                                                                    for (int i14 = i13+1; i14 < k-n+13; ++i14)
                                                                                    {
                                                                                        if (n == 13)
                                                                                        {
                                                                                            sum += (no_of_leaves-1)/lcm(l[i1],l[i2], l[i3], l[i4], l[i5], l[i6], l[i7], l[i8], l[i9], l[i10], l[i11], l[i12], l[i13], l[i14]);
                                                                                            ++sum;
                                                                                        }
                                                                                        else
                                                                                        {

                                                                                            for (int i15 = i14+1; i15 < k-n+14; ++i15)
                                                                                            {
                                                                                                if (n == 14)
                                                                                                {
                                                                                                    sum += (no_of_leaves-1)/lcm(l[i1],l[i2], l[i3], l[i4], l[i5], l[i6], l[i7], l[i8], l[i9], l[i10], l[i11], l[i12], l[i13], l[i14], l[i15]);
                                                                                                    ++sum;
                                                                                                }
                                                                                                else
                                                                                                {
                                                                                                    for (int i16 = i15+1; i16 < k-n+15; ++i16)
                                                                                                    {
                                                                                                        if (n == 15)
                                                                                                        {
                                                                                                            sum += (no_of_leaves-1)/lcm(l[i1],l[i2], l[i3], l[i4], l[i5], l[i6], l[i7], l[i8], l[i9], l[i10], l[i11], l[i12], l[i13], l[i14], l[i15], l[i16]);
                                                                                                            ++sum;
                                                                                                        }
                                                                                                        else
                                                                                                        {

                                                                                                            for (int i17 = i16+1; i17 < k-n+16; ++i17)
                                                                                                            {
                                                                                                                if (n == 16)
                                                                                                                {
                                                                                                                    sum += (no_of_leaves-1)/lcm(l[i1],l[i2], l[i3], l[i4], l[i5], l[i6], l[i7], l[i8], l[i9], l[i10], l[i11], l[i12], l[i13], l[i14], l[i15], l[i16], l[i17]);
                                                                                                                    ++sum;
                                                                                                                }
                                                                                                                else
                                                                                                                {
                                                                                                                    for (int i18 = i17+1; i18 < k-n+17; ++i18)
                                                                                                                    {
                                                                                                                        if (n == 17)
                                                                                                                        {
                                                                                                                            sum += (no_of_leaves-1)/lcm(l[i1],l[i2], l[i3], l[i4], l[i5], l[i6], l[i7], l[i8], l[i9], l[i10], l[i11], l[i12], l[i13], l[i14], l[i15], l[i16], l[i17], l[i8]);
                                                                                                                            ++sum;
                                                                                                                        }
                                                                                                                        else
                                                                                                                        {

                                                                                                                            for (int i19 = i18+1; i19 < k-n+18; ++i19)
                                                                                                                            {
                                                                                                                                if (n == 18)
                                                                                                                                {
                                                                                                                                    sum += (no_of_leaves-1)/lcm(l[i1],l[i2], l[i3], l[i4], l[i5], l[i6], l[i7], l[i8], l[i9], l[i10], l[i11], l[i12], l[i13], l[i14], l[i15], l[i16], l[i17], l[i18]. l[i19]);
                                                                                                                                    ++sum;
                                                                                                                                }
                                                                                                                                else
                                                                                                                                {
                                                                                                                                    for (int i20 = i19+1; i20 < k-n+19; ++i20)
                                                                                                                                    {


                                                                                                                                            sum += (no_of_leaves-1)/lcm(l[i1],l[i2], l[i3], l[i4], l[i5]);
                                                                                                                                            ++sum;


                                                                                                                                    }

                                                                                                                                }

                                                                                                                            }

                                                                                                            }

                                                                                                                }

                                                                                                            }


                                                                                                    }

                                                                                                }

                                                                                            }

                                                                                        }

                                                                                    }

                                                                        }

                                                            }

                                                        }

                                                    }

                                                }

                                            }

                                        }

                                    }
                                }

                            }
                        }
                    }
                }

        }
    }
    if ((n%2) == 0)
    {
        total + sum;
    }
    else
    {
        total - sum;
    }

}

int main ()
{
    cin >> no_of_leaves >> k;
    for (int i = 0; i < k; ++i)
    {
        cin >> l[i];
    }
    for (int i = 0; i < k; ++i)
    {
        total += (no_of_leaves-1)/l[i];
        ++total;
    }
    inclusion_exclusion();
    cout << total << endl;
    return 0;
}

