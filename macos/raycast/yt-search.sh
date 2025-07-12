#!/bin/bash

# Required parameters:
# @raycast.schemaVersion 1
# @raycast.title YouTube Search
# @raycast.mode silent

# Optional parameters:
# @raycast.icon 🎥
# @raycast.argument1 { "type": "text", "placeholder": "Search query" }

# Documentation:
# @raycast.description Search YouTube for a given query
# @raycast.author Your Name
# @raycast.authorURL https://yourwebsite.com

open "https://www.youtube.com/results?search_query=${1}"
