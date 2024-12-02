#ifndef DAY02_H
#define DAY02_H

#include "../../day.h"

class Day02 : public Day {
public:
    // Constructor
    explicit Day02(const std::string& inputFilePath);
    explicit Day02(const std::vector<std::string>& inputData);

    // Implementations of the required methods
    std::string SolvePart1() override;
    std::string SolvePart2() override;

protected:
    // Optional initialization specific to Day02
    void Initialize() override;
private:
    // Day 02 specific methods
    bool ValidateLevels(const std::vector<long long>& levels);
    bool ValidateLevelsWithRemoval(const std::vector<long long>& levels);
};

#endif // DAY02_H
