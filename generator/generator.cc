#include <iostream>
#include <iomanip>
#include <random>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(4);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> Samplerate(1, 786000);
    std::uniform_int_distribution<int> BufferSize(0, 10);
    std::uniform_real_distribution<double> Sample(-1.0, 1.0);

    int SR = Samplerate(gen);
    std::cout << SR << std::endl;
    std::cout << (1<<BufferSize(gen)) << std::endl;
    for(int i = 0; i < SR; ++i)
        std::cout << Sample(gen) << (i+1 == SR ? "" : " ");
    std::cout << std::endl;

    return 0;
}