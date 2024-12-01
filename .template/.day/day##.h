#ifndef DAY##_H
#define DAY##_H

#include "../../day.h"

class Day## : public Day {
public:
    // Constructor
    explicit Day##(const std::string& inputFilePath);
    explicit Day##(const std::vector<std::string>& inputData);

    // Implementations of the required methods
    std::string SolvePart1() override;
    std::string SolvePart2() override;

protected:
    // Optional initialization specific to Day##
    void Initialize() override;
private:

};

#endif // DAY##_H
