#include "testlib.h"
#include <iostream>
#include <iomanip>
#include <random>

using namespace std;

int main(int argc, char** argv) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(-1.0f, 1.0f);
    std::cout << std::fixed << std::setprecision(4);
    for (int i = 0; i < 256; ++i)
        cout << dist(gen) << " ";
    cout << endl;

    return 0;
}
