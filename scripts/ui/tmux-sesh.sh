#!/usr/bin/env bash

# This script connects to a sesh session using fzf-tmux for interactive selection
# Save this script as something like `sesh-connect.sh` and make it executable with `chmod +x sesh-connect.sh`

sesh connect "$(
    sesh list | fzf-tmux -p 75%,60% \
        --no-sort --ansi --border-label ' sesh ' --prompt '⚡  ' \
        --header '       a:all⚡  r:restore🪟  c:configs🏵️  zx:zoxide💫  d:delete🚚  f:find🔎' \
        --bind 'tab:down,btab:up' \
        --bind 'ctrl-a:change-prompt(⚡  )+reload(sesh list)' \
        --bind 'ctrl-r:change-prompt(🪟  )+reload(sesh list -t)' \
        --bind 'ctrl-c:change-prompt(🏵️  )+reload(sesh list -c)' \
        --bind 'ctrl-x:change-prompt(💫  )+reload(sesh list -z)' \
        --bind 'ctrl-f:change-prompt(🔎  )+reload(fd -H -d 2 -t d -E .Trash . ~)' \
        --bind 'ctrl-d:execute(tmux kill-session -t {})+change-prompt(⚡  )+reload(sesh list)'
)"
