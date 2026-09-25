#!/bin/sh

set -e

REPO_ROOT="$(git rev-parse --show-toplevel)"

echo "Installing Git hooks..."

mkdir -p "$REPO_ROOT/.git/hooks"

cp "$REPO_ROOT/.githooks/pre-commit" \
   "$REPO_ROOT/.git/hooks/pre-commit"

chmod +x "$REPO_ROOT/.git/hooks/pre-commit"

echo "✓ pre-commit hook installed."