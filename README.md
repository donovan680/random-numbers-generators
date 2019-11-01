# random-numbers-generators
Pseudo-random number generators (PRNG), which generate numbers that look random, but are actually deterministic, and can be reproduced if the state of the PRNG is known.
The random number library provides classes that generate random and pseudo-random numbers. These classes include:
Uniform random bit generators (URBGs), which include both random number engines, which are pseudo-random number generators that generate integer sequences with a uniform distribution, and true random number generators if available;
Random number distributions (e.g. uniform, normal, or poisson distributions) which convert the output of URBGs into various statistical distributions.URBGs and distributions are designed to be used together to produce random values. All of the random number engines may be specifically seeded, serialized, and deserialized for use with repeatable simulators. 

     Example :
     
#include <<iostream>>
    
#include <<iomanip>>
    
#include <string>
    
#include <map>
#include <random>
#include <cmath>
 
int main()
{
    // Seed with a real random value, if available
    std::random_device r;
 
    // Choose a random mean between 1 and 6
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(1, 6);
    int mean = uniform_dist(e1);
    std::cout << "Randomly-chosen mean: " << mean << '\n';
 
    // Generate a normal distribution around that mean
    std::seed_seq seed2{r(), r(), r(), r(), r(), r(), r(), r()}; 
    std::mt19937 e2(seed2);
    std::normal_distribution<> normal_dist(mean, 2);
 
    std::map<int, int> hist;
    for (int n = 0; n < 10000; ++n) {
        ++hist[std::round(normal_dist(e2))];
    }
    std::cout << "Normal distribution around " << mean << ":\n";
    for (auto p : hist) {
        std::cout << std::fixed << std::setprecision(1) << std::setw(2)
                  << p.first << ' ' << std::string(p.second/200, '*') << '\n';
    }
}
