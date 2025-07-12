#!/usr/bin/env bash

SESSION_NAME="home"

# Default to 'tmux' in PATH
tmux="tmux"

# If on macOS and Homebrew tmux exists, use it
if [[ "$(uname)" == "Darwin" ]] && [[ -x "/opt/homebrew/bin/tmux" ]]; then
  tmux="/opt/homebrew/bin/tmux"
fi

if $tmux has-session -t "$SESSION_NAME" 2>/dev/null; then
  exec $tmux attach -t "$SESSION_NAME"
else
  exec $tmux new -s "$SESSION_NAME"
fi
