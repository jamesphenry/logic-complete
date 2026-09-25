from pathlib import Path
import re
import sys

README_FILE = Path("README.md")
STATUS_FILE = Path("build/test_status")


def read_status():
    status = {}

    for line in STATUS_FILE.read_text().splitlines():
        key, value = line.split("=", 1)
        status[key] = value

    return status


def main():
    if not STATUS_FILE.exists():
        print("❌ Test status file not found.")
        sys.exit(1)

    status = read_status()

    required = [
        "tests",
        "failures",
        "ignored",
        "warnings",
    ]

    for key in required:
        if key not in status:
            print(f"❌ Missing '{key}' from test status.")
            sys.exit(1)

    tests = status["tests"]
    failures = status["failures"]
    ignored = status["ignored"]
    warnings = status["warnings"]

    readme = README_FILE.read_text()

    replacement = (
        "<!-- TEST_STATUS_START -->\n"
        "| 🧪 Tests | ❌ Failures | ⚪ Ignored | ⚠️ Warnings |\n"
        "|---:|---:|---:|---:|\n"
        f"| **{tests}** | **{failures}** | "
        f"**{ignored}** | **{warnings}** |\n"
        "<!-- TEST_STATUS_END -->"
    )

    pattern = (
        r"<!-- TEST_STATUS_START -->"
        r".*?"
        r"<!-- TEST_STATUS_END -->"
    )

    readme, count = re.subn(
        pattern,
        replacement,
        readme,
        flags=re.DOTALL
    )

    if count != 1:
        print("❌ Could not find README test status markers.")
        sys.exit(1)

    README_FILE.write_text(readme)

    print(
        f"README updated: "
        f"{tests} tests, "
        f"{failures} failures, "
        f"{ignored} ignored, "
        f"{warnings} warnings."
    )


if __name__ == "__main__":
    main()
