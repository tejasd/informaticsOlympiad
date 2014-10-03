/*INOI 2007 Problem 1 - SMS Dictionary */


#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int return_number (char alphabet)
{
    if (alphabet == 'a' || alphabet == 'b' || alphabet == 'c' )
    {
        return 2;
    }
    if (alphabet == 'd' || alphabet == 'e' || alphabet == 'f')
    {
        return 3;
    }
    if (alphabet == 'g' || alphabet == 'h' || alphabet == 'i')
    {
        return 4;
    }
    if (alphabet == 'j' || alphabet == 'k' || alphabet == 'l')
    {
        return 5;
    }
    if (alphabet == 'm' || alphabet == 'n' || alphabet == 'o')
    {
        return 6;
    }
    if (alphabet == 'p' || alphabet == 'q' || alphabet == 'r' || alphabet == 's')
    {
        return 7;
    }
    if (alphabet == 't' || alphabet == 'u' || alphabet == 'v')
    {
        return 8;
    }
    if (alphabet == 'w' || alphabet == 'x' || alphabet == 'y' || alphabet == 'z')
    {
        return 9;
    }
}

int main ()
{
    string input;
    int dict_length, word_length, total_number = 0, counter, maxint, max_counter;
    int array_of_numbers [100001];
    cin >> dict_length;
    for (int i = 0; i < dict_length; ++i)
    {

        cin >> input;
        word_length = input.length();
        for (int j = 0; j < word_length; ++j)
        {
            total_number += return_number(input[word_length-(j+1)])*pow(10,j);
        }
        array_of_numbers [i] = total_number;
        input.clear();
        total_number = 0;

    }
   sort (array_of_numbers, array_of_numbers+dict_length);
    //output debug
    /*for (int k = 0; k < dict_length; ++k)
    {
        cout << array_of_numbers[k] << endl;
    }*/

    counter = 1;
    max_counter = 1;
    maxint = array_of_numbers[0];

    for (int i = 1; i < dict_length; ++i)
    {
        if (array_of_numbers[i] == array_of_numbers[i-1])
        {
            ++counter;
            if (counter > max_counter)
            {
                max_counter = counter;
                maxint = array_of_numbers[i-1];
            }

        }Mozilla Firefox running on Windows XP, Windows Server 2003, Windows Vista, Windows 7 or Mac OS X 10.2.x and later. You can download Firefox from the Firefox download page.

        else
        {

            counter = 1;


        }


    }

    cout << maxint << endl;
    return 0;



}
