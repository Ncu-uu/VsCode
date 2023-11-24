#include <iostream>

int findExtraNumber(int N) {
    int result = 0;
    for (int i = 1; i <= N + 1; i++) {
        int num;
        std::cin >> num;
        result ^= num;
    }
    return result;
}

int main() {
    int N;
    std::cin >> N;

    int extraNumber = findExtraNumber(N);
    std::cout << extraNumber << std::endl;

    return 0;
}
