#ifndef __CppOptions__RandomWalkGenerator__
#define __CppOptions__RandomWalkGenerator__
// The class uses a vector to hold the elements
// of the random walk, so they can be later plotted.
#include <vector>
//
// Simple random walk generating class. This class can be
// used for price simulation purposes.
//
class RandomWalkGenerator {
public:
    //
    // Class constructors
    RandomWalkGenerator(int size, double start, double step);
    RandomWalkGenerator(const RandomWalkGenerator &p);
    // Destructor
    ~RandomWalkGenerator();
    // Assignment operator
    RandomWalkGenerator &operator=(const RandomWalkGenerator &p);
    // Main method that returns a vector with
    // values of the random walk
    std::vector<double> generateWalk();
    // Returns a single step of the random walk
    double computeRandomStep(double currentPrice);
private:
    int m_numSteps;     // the number of steps
    double m_stepSize;  // size of each step (in percentage points)
    double m_initialPrice; // starting price
};
#endif /* defined(__CppOptions__RandomWalkGenerator__) */