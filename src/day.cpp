#include "day.h"

// Constructor to load input from file
Day::Day(const std::string& inputFilePath) {
    LoadInput(std::string(DATA_DIR) + inputFilePath);
    Initialize();
}

// Constructor to use direct input data
Day::Day(const std::vector<std::string>& inputData) : Input(inputData) {
    Initialize();
}

// Load input from a file
void Day::LoadInput(const std::string& filePath) {
    std::ifstream inputFile(filePath);
    if (!inputFile.is_open()) {
        throw std::runtime_error("Failed to open input file: " + filePath);
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        Input.push_back(line);
    }

    if (Input.empty()) {
        throw std::runtime_error("Input file is empty: " + filePath);
    }
}

// Split a string into words
std::vector<std::string> Day::SplitString(const std::string& input, const char delimiter) {
    std::vector<std::string> result;
    std::istringstream stream(input);
    std::string word;

    // Split the string into words separated by spaces
    while (std::getline(stream, word, delimiter)) {
        result.push_back(word);
    }

    return result;
}

// Hook for derived classes to initialize resources
void Day::Initialize() {
    // Default implementation: Do nothing.
    // Derived classes can override this method to set up specific data structures.
}

// Validate input (optional implementation for derived classes)
void Day::ValidateInput() {
    if (Input.empty()) {
        throw std::runtime_error("Input is empty. Validation failed.");
    }
}

// Measure execution time for Part 1
void Day::TimePart1() {
    MeasureExecutionTime("Part 1", [this]() { 
        return CacheSolution(CachedPart1Result, [this]() { return SolvePart1(); }); 
    });
}

// Measure execution time for Part 2
void Day::TimePart2() {
    MeasureExecutionTime("Part 2", [this]() { 
        return CacheSolution(CachedPart2Result, [this]() { return SolvePart2(); }); 
    });
}

// Run all parts and display results
void Day::RunAllParts() {
    std::cout << "Running all parts:\n";
    TimePart1();
    TimePart2();
}

// Add a test case for Part 1
void Day::AddTestForPart1(const std::vector<std::string>& input, const std::string& expectedAnswer) {
    Part1Tests.push_back({input, expectedAnswer});
}

// Add a test case for Part 2
void Day::AddTestForPart2(const std::vector<std::string>& input, const std::string& expectedAnswer) {
    Part2Tests.push_back({input, expectedAnswer});
}

// Run all tests for Part 1
void Day::RunTestsForPart1() {
    std::cout << "Running tests for Part 1...\n";
    for (const auto& testCase : Part1Tests) {
        bool passed = RunSingleTest(testCase, [this]() { return SolvePart1(); });
        std::cout << (passed ? "PASSED" : "FAILED") << "\n";
    }
}

// Run all tests for Part 2
void Day::RunTestsForPart2() {
    std::cout << "Running tests for Part 2...\n";
    for (const auto& testCase : Part2Tests) {
        bool passed = RunSingleTest(testCase, [this]() { return SolvePart2(); });
        std::cout << (passed ? "PASSED" : "FAILED") << "\n";
    }
}

// Run all tests
void Day::RunAllTests() {
    RunTestsForPart1();
    RunTestsForPart2();
}

// Run a single test case
bool Day::RunSingleTest(const TestCase& testCase, const std::function<std::string()>& solveFunc) {
    Input = testCase.Input; // Set input to the test case
    Initialize();           // Reinitialize for the new input

    std::string result = solveFunc();
    if (result != testCase.ExpectedAnswer) {
        std::cout << "  Expected: " << testCase.ExpectedAnswer << "\n";
        std::cout << "  Got:      " << result << "\n";
        return false;
    }

    return true;
}
