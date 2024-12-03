#ifndef DAY03_H
#define DAY03_H

#include "../../day.h"

class Day03 : public Day {
public:
    // Constructor
    explicit Day03(const std::string& inputFilePath);
    explicit Day03(const std::vector<std::string>& inputData);

    // Implementations of the required methods
    std::string SolvePart1() override;
    std::string SolvePart2() override;

protected:
    // Optional initialization specific to Day03
    void Initialize() override;
private:

};

#endif // DAY03_H
