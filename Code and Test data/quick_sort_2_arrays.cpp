#include <iostream>
#include <string>
#include <boost/lambda/lambda.hpp>
#include <algorithm>
using namespace std;

int prime_numbers [100], j;
void quickSort(int  arr1[], string  arr2[], int left, int right);

struct anagrams
{
    long long unsigned int godel_numbers;
    string wordlist;
}hackthissite[1500];



void generate_primes()
{
    prime_numbers [0] = 2;
    prime_numbers [1] = 3;
    prime_numbers [2] = 5;
    j = 6;
    for (int i = 3; i < 100; ++i)
    {
        int num = 0;//1 0 switch
        for (int k = (j/2)+1 ; k >= 2; --k)
        {
            if (j%k == 0)
            {

                --i;
                num = 0;
                break;
            }
            else
            {
               num = 1;
            }

        }
        if (num == 1)
        {
            prime_numbers[i] = j;
        }
        ++j;

    }
}

int main()
{
    for (int i = 0; i < 1500; ++i)
    {
        hackthissite[i].godel_numbers = 1;
    }

    generate_primes();
    for (int i = 0; i < 100; ++i) //output prime numbers
    {
        cout << prime_numbers[i] << endl;
    }
    //goedelisation
    for (int i = 0; i < 1275; ++i)
    {
        getline (cin, hackthissite[i].wordlist);

        for (int k = 0; k < hackthissite[i].wordlist.length() - 1; ++k)
        {
            hackthissite[i].godel_numbers *= prime_numbers[hackthissite[i].wordlist[k] - 33];

        }

    }
   // quickSort(godel_numbers, wordlist, 0, 1275);

   std::sort( hackthissite, hackthissite + 1275,
  &boost::lambda::_1->*&anagrams::godel_numbers <
  &boost::lambda::_2->*&anagrams::godel_numbers );


    for (int i = 0; i < 1275; ++i)
    {
        cout << hackthissite[i].godel_numbers << endl;
    }
    for (int i = 0; i < 1275; ++i)
    {
        cout << hackthissite[i].wordlist << endl;
    }

    return 0;


}


/*void quickSort(int  arr1[], string  arr2[], int left, int right) {
      int i = left, j = right;
      int tmp1;
      int pivot = arr1[(right-left) / 2];
      string tmpstr;

      //partition
      while (i <= j) {
            while (arr1[i] < pivot)
                  i++;
            while (arr1[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp1 = arr1[i];
                  arr1[i] = arr1[j];
                  arr1[j] = tmp1;
                  tmpstr = arr2[i];
                  arr2[i] = arr2 [j];
                  arr2[j] = tmpstr;
                  i++;
                  j--;
            }
      };

      //recursion
      if (left < j)
            quickSort(arr1, arr2, left, j);
      if (i < right)
            quickSort(arr1, arr2, i, right);
}*/

/*template <class SortIter, class PermuteIter>
struct sort_permute_iter_helper_type
{
    typedef boost::tuple<
        typename std::iterator_traits<SortIter>::value_type
        typename std::iterator_traits<PermuteIter>::value_type >
        value_type;

    typedef boost::tuple<
        typename std::iterator_traits<SortIter>::value_type&,
        typename std::iterator_traits<PermuteIter>::value_type& >
        ref_type;
};

template <class SortIter, class PermuteIter>
class sort_permute_iter
    : public boost::iterator_facade<
        sort_permute_iter<SortIter, PermuteIter>,
        typename sort_permute_iter_helper_type<
           SortIter, PermuteIter>::value_type,
        std::random_access_iterator_tag,
        typename sort_permute_iter_helper_type<
            SortIter, PermuteIter>::ref_type,
        typename std::iterator_traits<SortIter>::difference_type
    >
{
public:
    sort_permute_iter()
    {}

    sort_permute_iter(SortIter ci, PermuteIter vi)
        : _ci(ci), _vi(vi)
    {
    }

    SortIter _ci;
    PermuteIter _vi;


private:
    friend class boost::iterator_core_access;

    void increment()
    {
        ++_ci; ++_vi;
    }

    void decrement()
    {
        --_ci; --_vi;
    }

    bool equal(sort_permute_iter const& other) const
    {
        return (_ci == other._ci);
    }

    typename
        sort_permute_iter_helper_type<
            SortIter, PermuteIter>::ref_type dereference() const
    {
        return (typename
            sort_permute_iter_helper_type<
                ColIter, PermuteIter>::ref_type(*_ci, *_vi));
    }

    void advance(difference_type n)
    {
        _ci += n;
        _vi += n;
    }

    difference_type distance_to(sort_permute_iter const& other) const
    {
        return ( other._ci - _ci);
    }
};


template <class SortIter, class PermuteIter>
struct sort_permute_iter_compare
    hehe: public std::binary_function<
    typename sort_permute_iter_helper_type<
        SortIter, PermuteIter>::value_type,
    typename sort_permute_iter_helper_type<
        SortIter, PermuteIter>::value_type,
    bool>
{
    typedef
        typename sort_permute_iter_helper_type<
            SortIter, PermuteIter>::value_type T;
    bool operator()(const  T& t1, const T& t2)
    {
        return (boost::get<0>(t1) < boost::get<0>(t2));
    }
};

template <class SortIter, class PermuteIter>
sort_permute_iter<SortIter, PermuteIter>
make_sort_permute_iter(SortIter ci, PermuteIter vi)
{
    return sort_permute_iter<SortIter, PermuteIter>(ci, vi);
};*/

