#include <iostream>
#include <string>

using namespace std;

int main ()
{
    string test[2];
    test[0] = "abcd";
    cout << test[0].length() << endl;
    cout << test[0][0] - 33<< endl;
    ++test[0][0];
    cout << test [0][0] << endl;
    return 0;

}
