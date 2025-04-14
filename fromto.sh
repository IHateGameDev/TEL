#!/bin/sh

if [ $# -ne 2 ]; then
  echo "Syntax: ./fromto.sh [src branch] [dst branch]"
  exit 1
fi

git checkout "$2"

if [ "$1" = "docs" ]; then
  git restore --source "$1" -- License assets TEM
  git restore --staged assets/Doxyfile
  
  mv assets/* docs
  rm -r assets
else
  git restore --source "$1" -- License docs TEM
  
  if [ "$2" = "docs" ]; then
    mv docs/* assets
    rm -r docs
  fi
fi

echo "Don't forget to add and commit changes and build docs if needed!"

exit 0

