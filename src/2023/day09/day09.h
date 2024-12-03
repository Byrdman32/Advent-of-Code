#ifndef DAY09_H
#define DAY09_H

#include "../../day.h"

class Day09 : public Day {
public:
    // Constructor
    explicit Day09(const std::string& inputFilePath);
    explicit Day09(const std::vector<std::string>& inputData);

    // Implementations of the required methods
    std::string SolvePart1() override;
    std::string SolvePart2() override;

protected:
    // Optional initialization specific to Day09
    void Initialize() override;
private:
    // Day 09 specific methods
    std::vector<long long> CreateDifferenceVector(const std::vector<long long>& history);
};

#endif // DAY09_H
