FROM alpine

RUN apk add texlive-full font-noto-cjk ttf-inconsolata

ENV FILENAME=codebook.tex
CMD xelatex $FILENAME && xelatex $FILENAME
