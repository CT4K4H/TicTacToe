#include "RandomGen.hpp"
#include <random>

int randomInt(int a, int b) {
    std::random_device myRandomDevice;
    unsigned seed = myRandomDevice();
    
    std::default_random_engine myRandomEngine(seed);
    std::uniform_int_distribution<int> myUnifIntDist(a, b);

    return myUnifIntDist(myRandomEngine);
}