# zinit light zsh-users/zsh-syntax-highlighting
zinit light zsh-users/zsh-autosuggestions
zinit light Aloxaf/fzf-tab
# zinit snippet OMZP::sudo


# zsh-you-should-use
if [[ "$(uname)" == "Darwin" ]]; then
  # Source from Homebrew location for Mac systems
  source /opt/homebrew/share/zsh-you-should-use/you-should-use.plugin.zsh
elif [ "$(whoami)" = "alebedev" ]; then
  # Source from home directory for alebedev user
  source $HOME/.zsh/plugins/zsh-you-should-use/you-should-use.plugin.zsh
else
  # Source from system location for other users
  source /usr/share/zsh/plugins/zsh-you-should-use/you-should-use.plugin.zsh
fi

# fast-syntax-highlighting
zinit light zdharma-continuum/fast-syntax-highlighting
# zinit light zsh-users/zsh-completions
# zsh-fzf-history-search
zinit ice lucid wait'0'
zinit light joshskidmore/zsh-fzf-history-search
# zsh-history-substring-search
zinit snippet OMZ::plugins/git/git.plugin.zsh
zinit load 'zsh-users/zsh-history-substring-search'
zinit ice wait atload '_history_substring_search_config'
