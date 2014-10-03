#include <iostream>
#include <queue>
#include <vector>
#include <heap>
using namespace std;

int number;

priority_queue<int> list;

int main() {
  priority_queue<int> Q;
  Q.push(1);
  Q.push(4);
  Q.push(2);
  Q.push(8);
  Q.push(5);
  Q.push(7);

  //Q.size() == 6);

  cout << Q.top() << endl;
  Q.pop();
  cin >> number;
  Q.push(number);
  cout << Q.top();
}

