#include <iostream>
#include <iomanip>
#include <random>

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(-1.0f, 1.0f);

    std::cout << std::fixed << std::setprecision(4);
    for (int i = 0; i < 256; ++i)
        std::cout << dist(gen) << ' ';
    std::cout << endl;

    return 0;
}