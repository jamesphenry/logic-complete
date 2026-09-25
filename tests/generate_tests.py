import glob
import re


TEST_DIR = "tests"
OUTPUT = "tests/generated_test_main.c"


test_functions = []

for filename in glob.glob(f"{TEST_DIR}/**/*.c", recursive=True):

    if filename.endswith("generated_test_main.c"):
        continue

    with open(filename, "r") as file:
        source = file.read()

    matches = re.findall(
        r"\bvoid\s+(test_[a-zA-Z0-9_]+)\s*\(\s*void\s*\)",
        source
    )

    test_functions.extend(matches)


test_functions.sort()


with open(OUTPUT, "w") as file:

    file.write('#include "unity.h"\n\n')

    for test in test_functions:
        file.write(f"void {test}(void);\n")

    file.write("\n")

    file.write("void setUp(void)\n")
    file.write("{\n")
    file.write("}\n\n")

    file.write("void tearDown(void)\n")
    file.write("{\n")
    file.write("}\n\n")

    file.write("int main(void)\n")
    file.write("{\n")
    file.write("    UNITY_BEGIN();\n\n")

    for test in test_functions:
        file.write(f"    RUN_TEST({test});\n")

    file.write("\n")
    file.write("    return UNITY_END();\n")
    file.write("}\n")