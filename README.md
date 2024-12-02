# Advent of Code Solutions

Welcome to my solutions repository for the [Advent of Code](https://adventofcode.com)! This repository contains my implementations of the daily programming challenges from Advent of Code. Each day in December brings a new problem to solve, and this repository showcases how I tackled each challenge.

## Setup Project Script

The `setup.sh` script automates the creation of the project structure for Advent of Code. It manages yearly directories, daily challenges, and updates configuration files like `CMakeLists.txt` and `main.cpp`. Additionally, it provides an option to clean up the build directory.

### Usage

```bash
./setup.sh --year <year> [--day <day>] [--set-year] [--set-day] [--delete-build]
```

### Arguments

- **`--year <year>`**: Specifies the year to set up (required).
- **`--day <day>`**: Specifies the day to set up (optional, *the day should be between 1 and 25.*).
- **`--set-year`**: Updates the year in `CMakeLists.txt`  (optional, *this is required if `--set-day` is used.*).
- **`--set-day`**: Updates the day in `CMakeLists.txt` (optional).
- **`--delete-build`**: Deletes the `build/` directory (optional).

### Features

1. **Year Creation**:
   - Creates a directory structure for the specified year under `src/` and `data/`.
   - Copies a `main.cpp` template to the year's directory if it doesn't already exist.

2. **Day Creation**:
   - Creates a directory structure for the specified day under `src/<year>/day<day>`.
   - Copies and processes template files from `.template/.day/`, replacing placeholders (`##` for the day, `&&&&` for the year).
   - Updates the year's `main.cpp`:
     - Uncomments the `#include` line for the day.
     - Uncomments and activates the `case` statement for the day in the factory function.
     - Appends the day to the `daysToRun` vector if it isn't already present.

3. **CMakeLists.txt Updates**:
   - Updates the project version in the format `YY.DD.00`.
   - Updates `YEAR_TO_BUILD_MODE` with the specified year if `--set-year` is used.
   - Updates `DAY_TO_BUILD_MODE` with the specified day if `--set-day` is used.

4. **Build Directory Deletion**:
   - If the `--delete-build` flag is specified, the script removes the `build/` directory and its contents.

### Examples

#### Create a New Year Structure
```bash
./setup.sh --year 2024
```
- Creates `src/2024/` and `data/2024/` directories.
- Copies the `main.cpp` template into `src/2024/`.

#### Add a New Day
```bash
./setup.sh --year 2024 --day 2
```
- Creates `src/2024/day02/` directory.
- Copies template files for day 2.
- Updates `src/2024/main.cpp` with the `#include`, `case`, and `daysToRun` updates.

#### Update `CMakeLists.txt`
```bash
./setup.sh --year 2024 --day 3 --set-year --set-day
```
- Updates the project version to `24.03.00` in `CMakeLists.txt`.
- Updates `YEAR_TO_BUILD_MODE` to `2024`.
- Updates `DAY_TO_BUILD_MODE` to `03`.

#### Delete the Build Directory
```bash
./setup.sh --year 2024 --day 3 --set-year --set-day --delete-build
```
- Deletes the `build/` directory and its contents.
- Can be combined with other flags to clean the project while setting up structures.

### Notes

- If a year or day already exists, the script will skip creating them.
- The script ensures all configurations are properly updated and avoids duplicate entries.
