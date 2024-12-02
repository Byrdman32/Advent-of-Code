#ifndef DAY_H
#define DAY_H

#include <string>
#include <vector>
#include <utility>
#include <chrono>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <fstream>
#include <functional>

class Day {
public:
    // Constructor
    explicit Day(const std::string& inputFilePath);
    explicit Day(const std::vector<std::string>& inputData);

    // Virtual destructor for proper cleanup in derived classes
    virtual ~Day() = default;

    // Functions to solve parts 1 and 2
    virtual std::string SolvePart1() = 0;
    virtual std::string SolvePart2() = 0;

    // Timing functions
    void TimePart1();
    void TimePart2();

    // Run all parts and display results
    void RunAllParts();

    // Add test data
    void AddTestForPart1(const std::vector<std::string>& input, const std::string& expectedAnswer);
    void AddTestForPart2(const std::vector<std::string>& input, const std::string& expectedAnswer);

    // Run tests for Part 1, Part 2, or both
    void RunTestsForPart1();
    void RunTestsForPart2();
    void RunAllTests();

protected:
    // Member to hold the input for the day
    std::vector<std::string> Input;

    // Utility function to read and load the input file
    void LoadInput(const std::string& filePath);

    // Utility function to split a string into words
    std::vector<std::string> SplitString(const std::string& input, const char delimiter = ' ');

    // Hook for derived classes to initialize additional resources
    virtual void Initialize();

    // Utility function to measure and print execution time
    template<typename Func>
    void MeasureExecutionTime(const std::string& partName, Func func) {
        try {
            auto start = std::chrono::high_resolution_clock::now();
            std::string result = func();
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = end - start;
            std::cout << partName << " Result: " << result << "\n";
            std::cout << partName << " Execution Time: " << elapsed.count() << " seconds\n";
        } catch (const std::exception& e) {
            std::cerr << partName << " encountered an error: " << e.what() << "\n";
        }
    }

    // Optional logger
    virtual void Log(const std::string& message) const {
        std::cerr << "[LOG]: " << message << "\n";
    }

private:
    // Cached results to avoid recomputation
    std::optional<std::string> CachedPart1Result;
    std::optional<std::string> CachedPart2Result;

    // Helper for caching logic
    template<typename Func>
    std::string CacheSolution(std::optional<std::string>& cache, Func func) {
        if (!cache.has_value()) {
            cache = func();
        }
        return *cache;
    }

    // Helper for validating input
    void ValidateInput();

    // Test datasets and expected solutions
    struct TestCase {
        std::vector<std::string> Input;
        std::string ExpectedAnswer;
    };

    std::vector<TestCase> Part1Tests;
    std::vector<TestCase> Part2Tests;

    // Helper to run a single test case
    bool RunSingleTest(const TestCase& testCase, const std::function<std::string()>& solveFunc);
};

#endif // DAY_H
