import re
import sys
from pathlib import Path

REPORT_FILE = Path("docs/tests.md")

def read_valgrind_status(path):
    output = Path(path).read_text()

    heap_match = re.search(
        r"total heap usage:\s+"
        r"(\d+) allocs,\s+"
        r"(\d+) frees,\s+"
        r"([\d,]+) bytes allocated",
        output
    )

    leak_match = re.search(
        r"in use at exit:\s+"
        r"([\d,]+) bytes in\s+"
        r"(\d+) blocks",
        output
    )

    error_match = re.search(
        r"ERROR SUMMARY:\s+"
        r"(\d+) errors",
        output
    )

    if not heap_match:
        print("❌ Could not parse Valgrind heap summary.")
        sys.exit(1)

    if not leak_match:
        print("❌ Could not parse Valgrind leak summary.")
        sys.exit(1)

    if not error_match:
        print("❌ Could not parse Valgrind error summary.")
        sys.exit(1)

    return {
        "allocs": heap_match.group(1),
        "frees": heap_match.group(2),
        "bytes_allocated": heap_match.group(3).replace(",", ""),
        "leaked_bytes": leak_match.group(1).replace(",", ""),
        "leaked_blocks": leak_match.group(2),
        "memory_errors": error_match.group(1),
    }

def main():
    if len(sys.argv) != 5:
        print(
            "Usage: generate_test_status.py "
            "<test_output> <status_file> "
            "<compiler_output> <valgrind_output>"
        )
        sys.exit(1)

    output_file = Path(sys.argv[1])
    status_file = Path(sys.argv[2])
    compiler_file = Path(sys.argv[3])
    valgrind_output = sys.argv[4]

    output = output_file.read_text()
    compiler_output = compiler_file.read_text()
    memory = read_valgrind_status(valgrind_output)

    tests = re.search(r"(\d+) Tests", output)
    failures = re.search(r"(\d+) Failures", output)
    ignored = re.search(r"(\d+) Ignored", output)
    warnings = len(
    re.findall(
        r"\bwarning:",
        compiler_output
    )
)
    
    if not tests or not failures or not ignored:
        print("Could not parse Unity test results.")
        sys.exit(1)

    status_file.write_text(
        f"tests={tests.group(1)}\n"
        f"failures={failures.group(1)}\n"
        f"ignored={ignored.group(1)}\n"
        f"warnings={warnings}\n"
        f"memory_errors={memory['memory_errors']}\n"
        f"allocs={memory['allocs']}\n"
        f"frees={memory['frees']}\n"
        f"bytes_allocated={memory['bytes_allocated']}\n"
        f"leaked_bytes={memory['leaked_bytes']}\n"
        f"leaked_blocks={memory['leaked_blocks']}\n"
    )

    print(f"Test status written to {status_file}")

    report = REPORT_FILE.read_text()

    replacement = (
        "<!-- TEST_SUMMARY_START -->\n"
        "| Tests | Failures | Ignored | Warnings |\n"
        "|---:|---:|---:|---:|\n"
        f"| {tests.group(1)} | "
        f"{failures.group(1)} | "
        f"{ignored.group(1)} | — |\n"
        "<!-- TEST_SUMMARY_END -->"
    )

    pattern = (
        r"<!-- TEST_SUMMARY_START -->"
        r".*?"
        r"<!-- TEST_SUMMARY_END -->"
    )

    report, count = re.subn(
        pattern,
        replacement,
        report,
        flags=re.DOTALL
    )

    if count != 1:
        print("Could not find test summary markers in docs/tests.md.")
        sys.exit(1)

    REPORT_FILE.write_text(report)


if __name__ == "__main__":
    main()