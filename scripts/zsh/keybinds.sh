bindkey "^E" forward-word
bindkey "^[[1;5C" forward-word
bindkey "^[[1;5D" backward-word

# Control + Backspace Setting
bindkey '^H' backward-kill-word
bindkey '^B' backward-kill-word

# Shift-Tab
bindkey '^[[Z' autosuggest-accept
bindkey '^[[27;2;9~' autosuggest-accept

# interupt sig
stty intr ^P
# stty intr '^C'

# map ctrl+c  copy_to_clipboard # in kitty.conf
bindkey '^K' clear-screen
bindkey '^U' clear-screen

cmd_to_clip() {
  if command -v pbcopy >/dev/null 2>&1; then
    # macOS
    print -rn -- "$BUFFER" | pbcopy
  elif command -v wl-copy >/dev/null 2>&1; then
    # Linux with Wayland
    print -rn -- "$BUFFER" | wl-copy
  elif command -v xclip >/dev/null 2>&1; then
    # Linux with X11
    print -rn -- "$BUFFER" | xclip -selection clipboard
  elif command -v xsel >/dev/null 2>&1; then
    # Alternative for X11
    print -rn -- "$BUFFER" | xsel --clipboard --input
  else
    print "No clipboard utility found!" >&2
    return 1
  fi
}
zle -N cmd_to_clip
bindkey '^Y' cmd_to_clip
