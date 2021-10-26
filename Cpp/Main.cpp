#include <iostream>
#include <vector>
using namespace std;

#include "CountTriplets.cpp"

int main()
{
  Solution* s = new Solution();
  vector<long> input = { 1, 5, 5, 25, 125 };
  long r = 5;
  cout << "answer = " << s->countTriplets(input, r);
  cout << "\n";
}