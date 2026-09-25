# Compiler and Flags
CC       := gcc
CFLAGS   := -Wall -Wextra -std=c11 -pedantic -g -Iinclude
LDFLAGS  :=

# Target Executable Names
TARGET      := build/cpu_sim
TEST_TARGET := build/test_runner

# Directories
SRC_DIR   := src
INC_DIR   := include
TEST_DIR  := tests
BUILD_DIR := build
OBJ_DIR   := $(BUILD_DIR)/obj

# Find all C source files recursively under src/
ALL_SRCS  := $(shell find $(SRC_DIR) -name '*.c')

# Separate main.c from component source files
MAIN_SRC  := $(SRC_DIR)/main.c
COMP_SRCS := $(filter-out $(MAIN_SRC), $(ALL_SRCS))

# Map source files to object files in build/obj/
ALL_OBJS  := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(ALL_SRCS))
COMP_OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(COMP_SRCS))

# Test sources and framework
TEST_SRCS := $(shell find $(TEST_DIR) -name '*.c' ! -name 'generated_test_main.c')
TEST_OBJS := $(patsubst $(TEST_DIR)/%.c, $(OBJ_DIR)/tests/%.o, $(TEST_SRCS))

# Generated test harness
GENERATED_TEST_MAIN := $(TEST_DIR)/generated_test_main.c
GENERATED_TEST_OBJ  := $(OBJ_DIR)/tests/generated_test_main.o

# Dependencies (.d)
DEPS := \
	$(ALL_OBJS:.o=.d) \
	$(TEST_OBJS:.o=.d) \
	$(GENERATED_TEST_OBJ:.o=.d)

.PHONY: all clean run test

all: $(TARGET)

# ------------------------------------------------------------
# Main CPU executable
# ------------------------------------------------------------

$(TARGET): $(ALL_OBJS)
	@mkdir -p $(dir $@)
	$(CC) $(ALL_OBJS) -o $@ $(LDFLAGS)
	@echo "Build successful: $@"

# ------------------------------------------------------------
# Test generation
# ------------------------------------------------------------

$(GENERATED_TEST_MAIN): $(TEST_SRCS) $(TEST_DIR)/generate_tests.py
	@echo "Generating test runner..."
	python3 $(TEST_DIR)/generate_tests.py

# ------------------------------------------------------------
# Test runner
# ------------------------------------------------------------

$(TEST_TARGET): $(COMP_OBJS) $(TEST_OBJS) $(GENERATED_TEST_OBJ)
	@mkdir -p $(dir $@)
	$(CC) $(COMP_OBJS) $(TEST_OBJS) $(GENERATED_TEST_OBJ) -o $@ $(LDFLAGS)
	@echo "Test runner built: $@"

# ------------------------------------------------------------
# Compile simulator source files
# ------------------------------------------------------------

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

# ------------------------------------------------------------
# Compile test source files
# ------------------------------------------------------------

$(OBJ_DIR)/tests/%.o: $(TEST_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(TEST_DIR)/vendor -MMD -MP -c $< -o $@

# ------------------------------------------------------------
# Compile generated test runner
# ------------------------------------------------------------

$(GENERATED_TEST_OBJ): $(GENERATED_TEST_MAIN)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(TEST_DIR)/vendor -MMD -MP -c $< -o $@

# ------------------------------------------------------------
# Include dependency files
# ------------------------------------------------------------

-include $(DEPS)

# ------------------------------------------------------------
# Run unit tests
# ------------------------------------------------------------

test: $(TEST_TARGET)
	@echo "Running unit tests..."
	@./$(TEST_TARGET)

# ------------------------------------------------------------
# Run main simulator
# ------------------------------------------------------------

run: $(TARGET)
	./$(TARGET)

# ------------------------------------------------------------
# Clean build artifacts
# ------------------------------------------------------------

clean:
	rm -rf $(BUILD_DIR)
	@echo "Cleaned build output."