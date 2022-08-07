FROM alpine

RUN apk add texlive-full font-noto-cjk ttf-inconsolata

ENV DIRECTORY=codebook FILENAME=codebook.tex
CMD cd $DIRECTORY && xelatex $FILENAME && xelatex $FILENAME
