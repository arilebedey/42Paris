#!/usr/bin/env bash

# Exclude patterns (relative to cwd)
exclude_dirs=("node_modules" ".git" "obsidian-notes")

# Build the find exclusion pattern
prune_expr=""
for dir in "${exclude_dirs[@]}"; do
  prune_expr+=" -name \"$dir\" -o"
done
prune_expr=${prune_expr::-2} # Remove trailing -o

# Use find to list directories, exclude specified ones, and use fzf for selection
selected_dir=$(eval "find . -type d \\( $prune_expr \\) -prune -false -o -type d -print" | fzf)

if [ -n "$selected_dir" ]; then
  selected_dir="$(realpath "$selected_dir")"
  if cd "$selected_dir"; then
    export SELECTED_DIR="$selected_dir"
    echo "Changed to: $selected_dir"
  else
    echo "Failed to change directory to $selected_dir"
    return 1
  fi
else
  echo "No directory selected."
fi
