#bin/bash

#!/bin/bash

# Check if a project name is provided
if [ -z "$1" ]; then
  echo "Usage: $0 <project_name>"
  exit 1
fi

# Set up project directory
PROJECT_NAME=$1
TEMPLATE_DIR="/home/minoka/dev/cursus/L04/cpp/scripts" # Adjust this path to your template location
PROJECT_DIR=$(pwd)/

# Create project structure
mkdir -p "$PROJECT_DIR/src" "$PROJECT_DIR/includes"

# Create main.cpp with a basic template
cat <<EOF > "$PROJECT_DIR/src/main.cpp"
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
EOF

# Copy the template Makefile
cp "$TEMPLATE_DIR/Makefile" "$PROJECT_DIR/Makefile"

echo "C++ project '$PROJECT_NAME' initialized at $PROJECT_DIR"