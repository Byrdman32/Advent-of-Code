#ifndef DAY04_H
#define DAY04_H

#include "../../day.h"

class Day04 : public Day {
public:
    // Constructor
    explicit Day04(const std::string& inputFilePath);
    explicit Day04(const std::vector<std::string>& inputData);

    // Implementations of the required methods
    std::string SolvePart1() override;
    std::string SolvePart2() override;

protected:
    // Optional initialization specific to Day04
    void Initialize() override;
private:
    // Day 04 specific methods
    bool CheckDirection(std::vector<std::string> grid, long long x, long long y, int xStep, int yStep, std::string checksum);
};

#endif // DAY04_H
