SHELL:=/bin/bash -O globstar
CXXFLAGS += --std=c++17

# Command line options
TAGS:=
PUML:=
RST:=
MAN?=-o manual.pdf

all: document.pdf

debug: CXXFLAGS += -g
debug: tags

# Document generation
document.pdf: document.rst 
	@ echo "Processing intermediate files:"
	@ for f in *.uml ; do echo "  $$f"; plantuml $(PUML) $$f ; done
	@ for f in *.rst ; do echo "  $$f"; rst2pdf $(RST) $$f >> rst2pdf.log ; done

document.rst: template.tags
	@ echo "Generating intermediate files (*.uml and *.rst) using tags"
	tags $(TAGS)

manual.pdf: README.TXT
	@ echo "Rebuilding TAGS manual"
	rst2pdf $(MAN) README.TXT


# Cleaners
docclean:
	-rm -f *.log *.png *.rst *.pdf 
clean:
	-rm -f *.o *.gch a.out tags test_tstring *.log *.uml *.png *.rst *.pdf
