#!/bin/sh

set -e

echo "================================"
echo "       Logic Complete"
echo "       Project Bootstrap"
echo "================================"
echo

echo "Checking dependencies..."

command -v gcc >/dev/null 2>&1 ||
{
    echo "ERROR: gcc not found."
    exit 1
}

command -v python3 >/dev/null 2>&1 ||
{
    echo "ERROR: python3 not found."
    exit 1
}

command -v make >/dev/null 2>&1 ||
{
    echo "ERROR: make not found."
    exit 1
}

command -v git >/dev/null 2>&1 ||
{
    echo "ERROR: git not found."
    exit 1
}

echo "✓ Dependencies found."
echo

./scripts/install_hooks.sh

echo
echo "Running initial test suite..."
echo

make test

echo
echo "================================"
echo "       Logic Complete"
echo "       Ready to build."
echo "================================"