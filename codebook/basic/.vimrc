set nocp nu rnu cul ai ci cin si sta
set sc si ts=4 sw=4 sts=4 bs=2 et
set hls sm is ic scs bg=dark
set ru stal=2 ls=2 so=5 wrap lbr
filetype plugin indent on
syntax enable
colo delek
no ; :
no <C-l> :nohl<CR>
au filetype c,cpp ino <F9> <ESC>:w<CR>:!~/r.sh '%'<CR>
au filetype c,cpp  no <F9> <ESC>:w<CR>:!~/r.sh '%'<CR>
let leader = '\'
function! Tg()
    s,^\(\s*\)\?,\1// ,e
    s,^\(\s*\)\(// \?\)\{2},\1,e
endfunc
au filetype c,cpp no <leader><leader> :call Tg()<CR>
