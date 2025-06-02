#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
#include <iomanip>

using namespace std;

const double PI = acos(-1);

void FFT(vector<complex<float>>& X) {
    int n = X.size();
    if(n <= 1) return;

    //역비트
    int log_n = log2(n);
    for(int i = 0; i < n; ++i) {
        int rev = 0;
        for(int j = 0; j < log_n; ++j)
            if(i&(1<<j))
                rev |= 1<<(log_n-1-j);
        if(i < rev)
            swap(X[i], X[rev]);
    }

    //FFT
    for(int len = 2; len <= n; len <<= 1) {
        float angle = -2*PI/len;
        complex<float> wlen(cos(angle), sin(angle));
        for(int i = 0; i < n; i += len) {
            complex<float> w(1);
            for(int j = 0; j < len/2; ++j) {
                complex<float> u = X[i+j];
                complex<float> v = X[i+j+len/2]*w;
                X[i+j] = u+v;
                X[i+j+len/2] = u-v;
                w *= wlen;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //입력
    vector<float> samples(256);
    for(float& input : samples)
        cin >> input;

    //복소수로 변환
    vector<complex<float>> complex_samples(256);
    for(int i = 0; i < 256; ++i)
        complex_samples[i] = complex<float>(samples[i], 0.0);

    FFT(complex_samples);

    //출력
    cout << fixed << setprecision(4);
    for(const auto& output : complex_samples)
        cout << abs(output) << ' ';

    return 0;
}
