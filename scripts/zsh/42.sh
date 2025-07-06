if [ "$(whoami)" = "alebedev" ]; then
  eval "$(perl -I$HOME/perl5/lib/perl5 -Mlocal::lib=$HOME/perl5)"
  export PATH=$HOME/local/bin:$PATH
  export PATH=$PATH:/home/alebedev/.local/share/soar/bin
  eval "$(zoxide init zsh)"
  eval "$(~/homebrew/bin/brew shellenv)"
  export PATH=$HOME/bin:$PATH
  xset r rate 250 80
fi

if [[ -n $WAYLAND_DISPLAY ]]; then
else
  alias wl-copy='xclip -selection clipboard'
  alias wl-paste='xclip -selection clipboard -o'
fi



if [ "$HOST" = "ls" ]; then
  eval "$(direnv hook zsh)"


  export PATH="$PATH:/home/ari/.local/bin"
  [ -s "$NVM_DIR/bash_completion" ] && \. "$NVM_DIR/bash_completion"  # This loads nvm bash_completion

fi

if [[ "$(uname)" == "Darwin" ]]; then
  defaults write -g InitialKeyRepeat -int 15
  defaults write -g KeyRepeat -int 1
  defaults write NSGlobalDomain ApplePressAndHoldEnabled -bool false
  defaults write -g NSWindowShouldDragOnGesture -bool true

  export NVM_DIR="$HOME/.nvm"
  [ -s "/opt/homebrew/opt/nvm/nvm.sh" ] && \. "/opt/homebrew/opt/nvm/nvm.sh"  # This loads nvm
  [ -s "/opt/homebrew/opt/nvm/etc/bash_completion.d/nvm" ] && \. "/opt/homebrew/opt/nvm/etc/bash_completion.d/nvm"  # This loads nvm bash_completion
fi
