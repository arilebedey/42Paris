#!/usr/bin/env bash

SESSION_NAME="home"
tmux="/opt/homebrew/bin/tmux"

# Check if the session exists
if $tmux has-session -t "$SESSION_NAME" 2>/dev/null; then
  # Source the configuration file for the existing session
  $tmux source-file $HOME/System/dotfiles/.config/tmux/startup-appendix.conf
  # Attach to the existing session
  $tmux attach-session -t "$SESSION_NAME"
else
  # Create a new session with the specified name and run the configuration file
  $tmux new-session -d -s "$SESSION_NAME" \; source-file $HOME/System/dotfiles/.config/tmux/startup-appendix.conf \; attach-session -t "$SESSION_NAME"
fi
