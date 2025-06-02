#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
#include <iomanip>

using namespace std;

const float PI = acos(-1);

void FFT(vector<complex<float>>& X) {
    int n = X.size();
    if(n <= 1) return;

    //분할
    vector<complex<float>> even(n/2), odd(n/2);
    for(int i = 0; i < n/2; ++i) {
        even[i] = X[i*2];
        odd[i] = X[i*2+1];
    }

    //재귀
    FFT(even);
    FFT(odd);

    //병합
    for(int k = 0; k < n/2; ++k) {
        complex<float> t = polar(1.0f, -2*PI*k/n)*odd[k];
        X[k] = even[k]+t;
        X[k+n/2] = even[k]-t;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //입력
    vector<float> samples(256);
    for (float& input : samples)
        cin >> input;

    //복소수로 변환
    vector<complex<float>> complex_samples(256);
    for (int i = 0; i < 256; ++i)
        complex_samples[i] = complex<float>(samples[i], 0.0f);

    FFT(complex_samples);

    //출력
    cout << fixed << setprecision(4);
    for (const auto& output : complex_samples)
        cout << abs(output) << ' ';

    return 0;
}
