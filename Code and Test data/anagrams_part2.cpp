#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void * pointer;
long long unsigned int * pointer_convert;
int number_of_anagrams;



long long unsigned int godel_numbers [1500];
string wordlist [1500];

string inputstr;
long long unsigned int input_godels [100];


int prime_numbers [100];

int compare (const void * a, const void * b)
{
  //return ( *(int*)a - *(int*)b );
  if (*(int*)a > *(int*)b)
  {
      return 1;
  }
  else if (*(int*)b > *(int*)a)
  {
      return -1;
  }
  else
  {
      return 0;
  }
}

int main ()
{
    for (int i = 0; i < 50; ++i)
    {
        input_godels[i] = 1;
    }
    for (int i = 0; i < 100;++i)
    {
        cin >> prime_numbers[i];
    }
    for (int i = 0; i < 1275; ++i)
    {
        cin >> godel_numbers[i];
    }
    for (int i = 0; i < 1275; ++i)
    {
        cin >> wordlist [i];
    }
    //cin >> number_of_anagrams;
    //cout << "here1\n";

    for (int k = 0; k < 10; ++k)
    {
        //cout << "here1\n";
        cin >> inputstr;
        //cout << "here1\n";
        for (int j = 0; j < inputstr.length() - 1; ++j) //godelisation of inputs
        {
            input_godels[k] *= prime_numbers[inputstr[j] - 33];

        }
        inputstr.clear();
        //cout << "here1\n";


    }
    //cout << "here1\n";
    for (int i = 0; i < 10; ++i)
    {
        cout << input_godels[i] << endl;
    }
    cout << "here1\n";
    cout << "here1\n";
    for (int l = 0; l < 10; ++l)
    {
        int l, r, centre, result;
        result = -1;
        l = 0;
        r = 1274;
        //insert bsearch here
        for (;;)
        {

            centre = (r+l)/2;
            if (input_godels[l] == godel_numbers[centre])
            {
                result = centre;

            }
            else if (input_godels[l] > godel_numbers[centre])
            {
                l = centre;
            }
            else
            {
                r = centre;
            }
            if ((l-r) == 0)
            {
                break;
            }


        }
        cout << wordlist [result] << ",";
    }
    return 0;


}
