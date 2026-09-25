import re
import sys
from pathlib import Path


README = Path("README.md")

START = "<!-- TEST_STATUS_START -->"
END = "<!-- TEST_STATUS_END -->"


if len(sys.argv) != 2:
    print("Usage: update_readme.py <test_count>")
    sys.exit(1)


test_count = sys.argv[1]

text = README.read_text()


replacement = (
    f"{START}\n"
    f"**Test Status:** 🟢 {test_count} tests passing\n"
    f"{END}"
)


pattern = re.escape(START) + r".*?" + re.escape(END)

updated, count = re.subn(
    pattern,
    replacement,
    text,
    flags=re.DOTALL
)


if count != 1:
    print("Could not find test status markers in README.md")
    sys.exit(1)


README.write_text(updated)

print(f"README updated: {test_count} tests passing")