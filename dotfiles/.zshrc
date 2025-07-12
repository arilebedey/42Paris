if [ -f "$HOME/.system-envs" ]; then
  source "$HOME/.system-envs"
fi

### PATHS
source $HOME/System/scripts/zsh/paths.sh

### 42 Configs
source $HOME/System/scripts/zsh/42.sh

## STARSHIP
eval "$(starship init zsh)"

## ZINIT
source $HOME/System/scripts/zsh/zinit.sh

## NVM
source $HOME/System/scripts/zsh/nvm.sh

## PLUGINS
source $HOME/System/scripts/zsh/plugins.sh

## ZSH OPTS
source $HOME/System/scripts/zsh/zshopts.sh

## OTHER CONFIG IMPORTS
# Aliases
source $HOME/.zshaliases
source $HOME/.keys.sh
source $HOME/System/scripts/zsh/function_aliases.sh
source $HOME/System/scripts/zsh/scripts.sh
# Functions
source $HOME/System/scripts/zsh/functions_to_order.sh
source $HOME/System/scripts/zsh/functions.sh
# Scripts
source $HOME/System/scripts/zsh/fzf2nvim.sh
source $HOME/System/scripts/zsh/tmux_choose.sh
source $HOME/System/scripts/zsh/yazi.sh
# Keybindings
source $HOME/System/scripts/zsh/keybinds.sh

## PLUGIN (keep at the end!)
source $HOME/System/scripts/zsh/plugins-end.sh

## SECRETS
source $HOME/.config/keys/secrets.sh
