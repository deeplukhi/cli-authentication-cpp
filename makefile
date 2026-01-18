.PHONY: all auth run test build_tests clean

CXX = g++
CXXFLAGS = -std=c++17 -Wall

AUTH_DIR = Authentication
VALIDATOR_DIR = InputValidators
UTILS_DIR = Utils
TEST_DIR = Tests
BUILD_DIR = build

AUTH_BIN = $(BUILD_DIR)/auth.exe
TEST_BIN = $(BUILD_DIR)/validator_tests.exe

AUTH_SRC = $(filter-out $(AUTH_DIR)/Main.cpp, $(wildcard $(AUTH_DIR)/*.cpp))
MAIN_SRC = $(AUTH_DIR)/Main.cpp
VALIDATOR_SRC = $(wildcard $(VALIDATOR_DIR)/*.cpp)
UTILS_SRC = $(wildcard $(UTILS_DIR)/*.cpp)
TEST_SRC = $(TEST_DIR)/ValidatorTests.cpp

all: auth

# ---- create build directory ----
$(BUILD_DIR):
	if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)

# ---- main app ----
auth: $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(MAIN_SRC) $(AUTH_SRC) $(VALIDATOR_SRC) $(UTILS_SRC) -o $(AUTH_BIN)

# ---- build test executable ----
build_tests: $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(TEST_SRC) $(VALIDATOR_SRC) -o $(TEST_BIN)

# ---- run test ----
test: build_tests
	$(TEST_BIN)

# ---- run app ----
run: auth
	$(AUTH_BIN)

# ---- clean ----
clean:
	if exist $(BUILD_DIR) rmdir /S /Q $(BUILD_DIR)
