set clipboard=unnamedplus
set shiftwidth=4
set tabstop=4
set noexpandtab
set cindent
set number
set mouse=a
set timeoutlen=300
syntax on
let mapleader = "."

inoremap <leader><leader> <ESC>:w<CR>i
inoremap <leader>, <ESC>:wq<CR>
nnoremap <leader><leader> :w<CR>
nnoremap <leader>, :wq<CR>

call plug#begin()

Plug 'junegunn/fzf.vim'
Plug 'preservim/nerdtree'
Plug 'jiangmiao/auto-pairs'
Plug 'joshdick/onedark.vim'

call plug#end()

colorscheme onedark
