

FILES=exam1_sol.pdf\
  exam2_sol.pdf\
  exam3_sol.pdf

all: $(FILES)

%.pdf: %.tex
	pdflatex $<
%.ps: %.dvi
	dvips $<
	