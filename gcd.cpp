#include <iostream>
#include <vector>
#include <algorithm>

int maxProfit(std::vector<int>& prices) {
    int n = prices.size();
    if (n <= 1) {
        return 0;
    }
    
    int maxProfit = 0;
    int minPrice = prices[0];
    
    for (int i = 1; i < n; i++) {
        maxProfit = std::max(maxProfit, prices[i] - minPrice);
        minPrice = std::min(minPrice, prices[i]);
    }
    
    return maxProfit;
}

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        std::cin >> prices[i];
    }
    
    int result = maxProfit(prices);
    std::cout << result << std::endl;
    
    return 0;
}
