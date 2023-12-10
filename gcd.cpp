#include <iostream>

int find_z(int x, int y) {
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x - 1;
}

int main() {
    int x, y;
    std::cin >> x >> y;
    int z = find_z(x, y);
    std::cout << z << std::endl;
    return 0;
}
