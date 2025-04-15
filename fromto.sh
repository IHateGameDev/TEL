#!/bin/sh

srcBranch="$1"
dstBranch="$2"

if ! command -v git >/dev/null 2>&1; then
  echo "Git is not installed or not available in the command line."
  exit 1
fi

if [ -z "$srcBranch" ] || [ -z "$dstBranch" ]; then
  echo "Syntax: ./fromto.sh [src branch] [dst branch]"
  exit 1
fi

if ! git checkout "$dstBranch"; then
  echo "Error switching to branch $dstBranch."
  exit 1
fi

if ! git restore --source "$srcBranch" -- fromto.sh fromto.ps1 fromto.sh License TEM; then
  echo "Error copying files."
  exit 1
fi

if [ "$srcBranch" = "docs" ]; then
  if ! git restore --source "$srcBranch" -- Pages; then
    echo "Error restoring Pages."
    exit 1
  fi

  mv -f "Pages" "docs"

else
  if ! git restore --source "$srcBranch" -- docs; then
    echo "Error restoring docs."
    exit 1
  fi

  if [ "$dstBranch" = "docs" ]; then
    mv -f "docs" "Pages"
  fi
fi

echo "Don't forget to add and commit changes, and build docs if needed!"

exit 0

