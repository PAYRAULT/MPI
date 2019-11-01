

FILES=exo_2_1_1.pdf\
  exo_2_2_1.pdf\
  exo_2_3_1.pdf\
  exo_3_1_2.pdf\
  exo_3_1_5.pdf\
  exo_2_1_2.pdf\
  exo_2_2_2.pdf\
  exo_3_1_1.pdf\
  exo_3_1_3.pdf\
  exo_3_3_1.pdf\
  exo_3_2_1.pdf

all: $(FILES)

%.pdf: %.tex
	pdflatex $<
%.ps: %.dvi
	dvips $<
	