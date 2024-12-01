#ifndef DAY01_H
#define DAY01_H

#include "../../day.h"

class Day01 : public Day {
public:
    // Constructor
    explicit Day01(const std::string& inputFilePath);
    explicit Day01(const std::vector<std::string>& inputData);

    // Implementations of the required methods
    std::string SolvePart1() override;
    std::string SolvePart2() override;

protected:
    // Optional initialization specific to Day01
    void Initialize() override;
private:

};

#endif // DAY01_H
