#!/bin/bash

# Constants
TEMPLATE_DAY_PATH=".template/.day"
TEMPLATE_MAIN=".template/main.cpp"
SRC_PATH="src"
DATA_PATH="data"
CMAKE_FILE="CMakeLists.txt"
BUILD_DIR="build"

# Functions
create_year() {
  local year=$1
  local year_src_path="${SRC_PATH}/${year}"
  local year_data_path="${DATA_PATH}/${year}"

  # Check if the year directory already exists
  if [[ -d "${year_src_path}" && -d "${year_data_path}" ]]; then
    echo "Year ${year} structure already exists. Skipping year creation."
    return
  fi

  # Create year directories
  mkdir -p "${year_src_path}"
  mkdir -p "${year_data_path}"

  # Copy main template
  if [[ -f "${TEMPLATE_MAIN}" ]]; then
    cp "${TEMPLATE_MAIN}" "${year_src_path}/main.cpp"
    echo "Created year structure for ${year}"
  else
    echo "Error: ${TEMPLATE_MAIN} not found."
    exit 1
  fi
}

update_cmake() {
  local year=$1
  local day=$(printf "%02d" $2) # Ensure the day is formatted as two digits
  local set_year=$3
  local set_day=$4

  if [[ -f "${CMAKE_FILE}" ]]; then
    # Update project version: Replace the major version with the 2-digit year and minor version with the 2-digit day
    sed -i -E "s|^(project\(AoC VERSION )[0-9]{2}\.[0-9]{2}\.[0-9]{2}|\1${year:2:2}.${day}.00|" "${CMAKE_FILE}"

    # Update YEAR_TO_BUILD_MODE if --set-year is provided
    if [[ "$set_year" == "true" ]]; then
      sed -i -E "s|^(set\(YEAR_TO_BUILD_MODE )\"[0-9]{4}\"|\1\"${year}\"|" "${CMAKE_FILE}"
    fi

    # Update DAY_TO_BUILD_MODE only if --set-day is provided or it's not currently "all"
    if [[ "$set_day" == "true" ]]; then
      sed -i -E "s|^(set\(DAY_TO_BUILD_MODE )\"[0-9]{2}\"|\1\"${day}\"|" "${CMAKE_FILE}"
    fi

    echo "Updated CMakeLists.txt with year ${year} and day ${day}."
  else
    echo "Error: ${CMAKE_FILE} not found."
    exit 1
  fi
}

create_day() {
  local year=$1
  local day=$(printf "%02d" $2) # Format day as 2 digits
  local day_single_digit=$((10#$2)) # Single digit for days 1–9
  local day_src_path="${SRC_PATH}/${year}/day${day}"
  local year_main_path="${SRC_PATH}/${year}/main.cpp"

  # Check if the day directory already exists
  if [[ -d "${day_src_path}" ]]; then
    echo "Day ${day} structure for year ${year} already exists. Skipping day creation."
    return
  fi

  # Create day directories
  mkdir -p "${day_src_path}"

  # Copy and replace placeholders in day template
  if [[ -d "${TEMPLATE_DAY_PATH}" ]]; then
    for file in "${TEMPLATE_DAY_PATH}"/*; do
      local filename=$(basename "$file")
      local new_filename="${filename//##/${day}}" # Replace ## with day number
      cp "$file" "${day_src_path}/${new_filename}"

      # Replace placeholders in the copied file
      sed -i "s/##/${day}/g" "${day_src_path}/${new_filename}"
      sed -i "s/&&&&/${year}/g" "${day_src_path}/${new_filename}"
    done
    echo "Created day structure for year ${year}, day ${day}"
  else
    echo "Error: ${TEMPLATE_DAY_PATH} not found."
    exit 1
  fi

  # Update the year's main.cpp
  if [[ -f "${year_main_path}" ]]; then
    # Uncomment the #include line
    sed -i "s|// #include \"day${day}/day${day}.h\"|#include \"day${day}/day${day}.h\"|" "${year_main_path}"

    # Uncomment the case line
    sed -i "s|// case ${day_single_digit}: return std::make_unique<Day${day}>(inputFilePath);|case ${day_single_digit}: return std::make_unique<Day${day}>(inputFilePath);|" "${year_main_path}"

    # Handle appending the day to the daysToRun vector
    if grep -q "std::vector<int> daysToRun" "${year_main_path}"; then
      # Extract existing vector content
      local vector_content
      vector_content=$(grep "std::vector<int> daysToRun" "${year_main_path}" | sed -E 's/.*\{(.*)\}.*/\1/')

      # Check if the day is already in the vector
      if [[ ! $vector_content =~ (^|,)[[:space:]]*${day_single_digit}($|,) ]]; then
        # Handle cases where the vector is empty or non-empty
        if [[ -z "$vector_content" || "$vector_content" =~ ^[[:space:]]*$ ]]; then
          # Empty vector
          sed -i "s|std::vector<int> daysToRun = {.*}|std::vector<int> daysToRun = {${day_single_digit}};|" "${year_main_path}"
        else
          # Non-empty vector
          sed -i "s|std::vector<int> daysToRun = {${vector_content}}|std::vector<int> daysToRun = {${vector_content}, ${day_single_digit}}|" "${year_main_path}"
        fi
        echo "Successfully appended day ${day_single_digit} to daysToRun in main.cpp"
      else
        echo "Day ${day_single_digit} is already in daysToRun."
      fi
    else
      echo "Error: daysToRun vector not found in main.cpp"
      exit 1
    fi

    # Verify the changes
    if grep -q "case ${day_single_digit}: return std::make_unique<Day${day}>(inputFilePath);" "${year_main_path}"; then
      echo "Successfully updated case ${day_single_digit} in main.cpp"
    else
      echo "Failed to update case ${day_single_digit} in main.cpp. Please check the format."
    fi
  else
    echo "Error: main.cpp for year ${year} not found."
    exit 1
  fi
}

delete_build() {
  if [[ -d "${BUILD_DIR}" ]]; then
    echo "Deleting build directory..."
    rm -rf "${BUILD_DIR}"
    echo "Build directory deleted."
  else
    echo "Build directory does not exist. Skipping deletion."
  fi
}

# Main script
if [[ $# -lt 1 ]]; then
  echo "Usage: $0 --year <year> [--day <day>] [--set-year] [--set-day] [--delete-build]"
  exit 1
fi

# Parse arguments
YEAR=""
DAY=""
SET_YEAR="false"
SET_DAY="false"
DELETE_BUILD="false"

while [[ $# -gt 0 ]]; do
  case $1 in
    --year)
      YEAR=$2
      shift 2
      ;;
    --day)
      DAY=$2
      shift 2
      ;;
    --set-year)
      SET_YEAR="true"
      shift 1
      ;;
    --set-day)
      SET_DAY="true"
      shift 1
      ;;
    --delete-build)
      DELETE_BUILD="true"
      shift 1
      ;;
    *)
      echo "Unknown option: $1"
      exit 1
      ;;
  esac
done

# Validation checks
if [[ "$SET_DAY" == "true" && "$SET_YEAR" != "true" ]]; then
  echo "Error: --set-day requires --set-year to be specified."
  exit 1
fi

if [[ -z "${YEAR}" && "$SET_YEAR" == "true" ]]; then
  echo "Error: --set-year requires a valid year to be specified."
  exit 1
fi

if [[ -z "${DAY}" && "$SET_DAY" == "true" ]]; then
  echo "Error: --set-day requires a valid day to be specified."
  exit 1
fi

# Delete the build directory if the flag is set
if [[ "$DELETE_BUILD" == "true" ]]; then
  delete_build
fi

# Create year structure only if it doesn't exist
create_year "${YEAR}"

# Create day structure if specified
if [[ -n "${DAY}" ]]; then
  create_day "${YEAR}" "${DAY}"
fi

# Update CMakeLists.txt
update_cmake "${YEAR}" "${DAY}" "${SET_YEAR}" "${SET_DAY}"
