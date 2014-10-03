#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main ()
{
    int counter = 0;
    int no_of_books = 0, input;
    std::vector<int> list_of_books;
    for (int i = 0; i < 3 ; ++i)
    {
        cin >> input;
        no_of_books += input;
    }
    for (int i = 0; i < no_of_books; ++i)
    {
        cin >> input;
        list_of_books.push_back (input);
    }
    std::sort (list_of_books.begin(),list_of_books.end() );
    /*for (int i = 0; i < list_of_books.size(); ++i)
    {
        cout << list_of_books[i] << endl;
    }*/

    for (int i = 1; i < list_of_books.size(); ++i)
    {
        if (list_of_books[i] == list_of_books[i-1] ||list_of_books[i] == -list_of_books[i-1] )
        {
            list_of_books[i] = -list_of_books[i];
        }

    }

   // cout << "here1\n";
    /*for (int i = 0; i < list_of_books.size(); ++i)
    {
        cout << list_of_books[i] << endl;
    }*/
    for (int i = 0; i < list_of_books.size(); ++i)
    {
        if (list_of_books[i] >= 0)
        {
            ++counter;
        }
    }
    cout << counter << endl;

    return 0;




}
