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
        "memory_errors",
        "allocs",
        "frees",
        "bytes_allocated",
        "leaked_bytes",
        "leaked_blocks",
    ]

    for key in required:
        if key not in status:
            print(f"❌ Missing '{key}' from test status.")
            sys.exit(1)

    tests = status["tests"]
    failures = status["failures"]
    ignored = status["ignored"]
    warnings = status["warnings"]

    memory_errors = status["memory_errors"]
    allocs = status["allocs"]
    frees = status["frees"]
    bytes_allocated = status["bytes_allocated"]
    leaked_bytes = status["leaked_bytes"]
    leaked_blocks = status["leaked_blocks"]

    readme = README_FILE.read_text()

    test_replacement = (
        "<!-- TEST_STATUS_START -->\n"
        "| 🧪 Tests | ❌ Failures | ⚪ Ignored | ⚠️ Warnings | 🧠 Memory Errors |\n"
        "|---:|---:|---:|---:|---:|\n"
        f"| **{tests}** | **{failures}** | **{ignored}** | "
        f"**{warnings}** | **{memory_errors}** |\n"
        "<!-- TEST_STATUS_END -->"
    )

    test_pattern = (
        r"<!-- TEST_STATUS_START -->"
        r".*?"
        r"<!-- TEST_STATUS_END -->"
    )

    readme, test_count = re.subn(
        test_pattern,
        test_replacement,
        readme,
        flags=re.DOTALL
    )

    if test_count != 1:
        print("❌ Could not find README test status markers.")
        sys.exit(1)

    memory_replacement = (
        "<!-- MEMORY_STATUS_START -->\n"
        "| 📦 Allocs | 🗑️ Frees | 💾 Bytes Allocated | "
        "💧 Leaked Bytes | 🧱 Leaked Blocks |\n"
        "|---:|---:|---:|---:|---:|\n"
        f"| **{allocs}** | **{frees}** | **{bytes_allocated}** | "
        f"**{leaked_bytes}** | **{leaked_blocks}** |\n"
        "<!-- MEMORY_STATUS_END -->"
    )

    memory_pattern = (
        r"<!-- MEMORY_STATUS_START -->"
        r".*?"
        r"<!-- MEMORY_STATUS_END -->"
    )

    readme, memory_count = re.subn(
        memory_pattern,
        memory_replacement,
        readme,
        flags=re.DOTALL
    )

    if memory_count != 1:
        print("❌ Could not find README memory status markers.")
        sys.exit(1)

    README_FILE.write_text(readme)

    print(
        f"README updated: "
        f"{tests} tests, "
        f"{failures} failures, "
        f"{ignored} ignored, "
        f"{warnings} warnings, "
        f"{memory_errors} memory errors, "
        f"{leaked_bytes} leaked bytes."
    )


if __name__ == "__main__":
    main()
