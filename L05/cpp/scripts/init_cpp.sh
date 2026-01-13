#!/bin/bash

# Check if a project name is provided
if [ -z "$1" ]; then
  echo "Usage: $0 <project_name>"
  exit 1
fi

# Set up project directory
PROJECT_NAME="$1"

# Try to find a template directory that contains a Makefile (case-insensitive)
TEMPLATE_DIR=""
MAKEFILE_PATH=""
for d in "/home/minoka/dev/cursus/L05/cpp05/scripts" "/home/mkakizak/cursus/L05/cpp05/scripts" "/home/mkakizak/cursus/L05/cpp/scripts"; do
  if [ -f "$d/Makefile" ]; then
    TEMPLATE_DIR="$d"
    MAKEFILE_PATH="$d/Makefile"
    break
  elif [ -f "$d/makefile" ]; then
    TEMPLATE_DIR="$d"
    MAKEFILE_PATH="$d/makefile"
    break
  fi
done

if [ -z "$MAKEFILE_PATH" ]; then
  echo "Error: Could not find a template Makefile in known directories."
  exit 1
else
  echo "Using template Makefile at: $MAKEFILE_PATH"
fi


# Create project directory under current working directory
PROJECT_DIR="$(pwd)/"

# Create project structure
mkdir -p "$PROJECT_DIR/src" "$PROJECT_DIR/includes"
# Create project source and header files with the project name
touch "$PROJECT_DIR/src/${PROJECT_NAME}.c"
touch "$PROJECT_DIR/includes/${PROJECT_NAME}.h"

# Create main.cpp with a basic template
cat > "$PROJECT_DIR/src/main.cpp" << EOF
#include <iostream>
#include "../includes/${PROJECT_NAME}.h"
#include "../src/${PROJECT_NAME}.c"

int main() {
  std::cout << "Hello from ${PROJECT_NAME}" << std::endl;
  return 0;
}
EOF

# Copy the template Makefile
cp "$TEMPLATE_DIR/Makefile" "$PROJECT_DIR/Makefile"

echo "C++ project '$PROJECT_NAME' initialized at $PROJECT_DIR"