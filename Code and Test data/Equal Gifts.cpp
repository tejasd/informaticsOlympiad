#include <iostream>
#include <algorithm>
using namespace std;

class pair_of_books
{
    public:
    int book1, book2, difference;
};

bool compare (pair_of_books one, pair_of_books two)
{
    if (one.difference > two.difference)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main ()
{
    pair_of_books books[150];
    int no_of_pairs, nikhil = 0, lavanya = 0, difference = 0; //difference = nikhil-lavanya
    cin >> no_of_pairs;
    for (int i = 0; i < no_of_pairs; ++i)
    {
        cin >> books[i].book1;
        cin >> books[i].book2;
        books[i].difference = books[i].book1-books[i].book2;
        if (books[i].difference < 0)
        {
            books[i].difference *= -1;
        }
    }
    sort (books, books+no_of_pairs, compare);
    for (int i = 0; i < no_of_pairs; ++i)
    {
        if (difference > 0)
        {
            if (books[i].book1 > books[i].book2)
            {
                nikhil += books[i].book2;
                lavanya += books[i].book1;
            }
            else if (books[i].book1 < books[i].book2)
            {
                nikhil += books[i].book1;
                lavanya += books[i].book2;
            }
            else
            {
                nikhil += books[i].book1;
                lavanya += books[i].book2;
            }
        }
        else if (difference < 0)
        {
            if (books[i].book1 < books[i].book2)
            {
                nikhil += books[i].book2;
                lavanya += books[i].book1;
            }
            else if (books[i].book1 > books[i].book2)
            {
                nikhil += books[i].book1;
                lavanya += books[i].book2;
            }
            else
            {
                nikhil += books[i].book1;
                lavanya += books[i].book2;
            }
        }
        else
        {
            nikhil += books[i].book1;
            lavanya += books[i].book2;
        }
        difference = (nikhil-lavanya);
        //cout << i << " " << difference << " " << nikhil << " " << lavanya << endl;


    }
    difference = nikhil - lavanya;
    if (difference < 0)
    {
        difference *= -1;
    }
    cout << difference << endl;
    return 0;



}
