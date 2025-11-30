#include "testlib.h"
#include <cmath>

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    
    int samplerate = inf. readInt(1, 768000, "samplerate");
    inf.readEoln();
    
    int buffersize = inf.readInt(1, 1024, "buffersize");
    inf.readEoln();
    
    bool isPowerOfTwo = (buffersize > 0) && ((buffersize & (buffersize - 1)) == 0);
    ensuref(isPowerOfTwo, "buffersize must be a power of 2");
    
    int numSamples = 1000 * samplerate;
    
    for (int i = 0; i < numSamples; i++) {
        double sample = inf.readDouble(-1. 0, 1.0, "sample");
        
        double rounded = round(sample * 10000. 0) / 10000.0;
        ensuref(fabs(sample - rounded) < 1e-9, 
                "sample must have at most 4 decimal places");
        
        if (i < numSamples - 1) {
            inf. readSpace();
        }
    }
    inf.readEoln();
    
    inf.readEof();
    
    return 0;
}