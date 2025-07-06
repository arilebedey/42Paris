#!/bin/bash

# Script to set up Ghostty configuration based on environment

# Default config directory (where the symlink will be placed)
CONFIG_DIR="$HOME/.config/ghostty"
GHOSTTY_CONFIG_PATH="$CONFIG_DIR/config"

# Source directory (where the actual config files are located)
SOURCE_DIR="$HOME/System/dotfiles/.config/ghostty"

# Default environment for Mac Mini M1
DEFAULT_ENVIRONMENT="m1mini"

# Check if an environment was provided
if [ -z "$1" ]; then
    echo "No environment provided. Using default: $DEFAULT_ENVIRONMENT"
    ENVIRONMENT="$DEFAULT_ENVIRONMENT"
else
    ENVIRONMENT="$1"
fi

# Create config directory if it doesn't exist
mkdir -p "$CONFIG_DIR"

# Function to set up the configuration
setup_config() {
    local source_config="$SOURCE_DIR/ghostty-$ENVIRONMENT-config"
    
    # Check if the source config exists
    if [ ! -f "$source_config" ]; then
        echo "Error: Configuration file for environment '$ENVIRONMENT' not found at $source_config"
        exit 1
    fi
    
    # Handle existing config file or symlink
    if [ -e "$GHOSTTY_CONFIG_PATH" ]; then
        if [ -L "$GHOSTTY_CONFIG_PATH" ]; then
            # It's a symlink, remove it
            echo "Removing existing symlink..."
            rm "$GHOSTTY_CONFIG_PATH"
        else
            # It's a regular file, back it up
            echo "Backing up existing config file..."
            backup_name="$GHOSTTY_CONFIG_PATH.backup.$(date +%Y%m%d%H%M%S)"
            mv "$GHOSTTY_CONFIG_PATH" "$backup_name"
            echo "Existing config backed up to $backup_name"
        fi
    fi
    
    # Create the symlink
    echo "Creating symlink for '$ENVIRONMENT' configuration..."
    ln -s "$source_config" "$GHOSTTY_CONFIG_PATH"
    
    echo "Ghostty configured for '$ENVIRONMENT' environment."
}

# Set up based on the provided environment
case "$ENVIRONMENT" in
    "42-dell")
        setup_config
        ;;
    "home")
        setup_config
        ;;
    "m1mini")
        setup_config
        ;;
    *)
        echo "Unknown environment: $ENVIRONMENT"
        echo "Available environments: 42-dell, home, m1mini"
        exit 1
        ;;
esac

exit 0
