#!/bin/bash

current_dir=$(pwd)

cd ../

cp node-express/scripts/pre-commit.txt .git/hooks/pre-commit
chmod +x .git/hooks/pre-commit
