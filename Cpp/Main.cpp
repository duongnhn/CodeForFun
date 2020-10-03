#include <iostream>
#include "BestTimeStockWithCoolDown.cpp"

int main()
{
    cout << "Hello World!\n";
    BestTimeToBuyAndSellStockWithCoolDown s;
    vector<int> prices = { 1,2,3,0,2 };
    cout << s.maxProfit(prices) << "\n";
}