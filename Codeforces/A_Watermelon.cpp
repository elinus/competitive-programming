#include <iostream>

int main (int argc, char *argv[]) {
    int w;
    std::cin >> w;
    if (w%2 || w/2 == 1) {
        std::cout << "NO\n";
        return 0;
    }
    std::cout << "YES\n";
 
    return 0;
}

