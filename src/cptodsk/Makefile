# dsktools (C) 2005,2022 Tatsuhiko Shoji
# The sources for dsktools are distributed under the MIT open source license

OBJDIR = ../obj
BINDIR = ../bin

cptodsk : cptodsk.c dskFile.o fatFs.o
	if [ ! -d $(BINDIR) ]; then mkdir $(BINDIR) ;	fi
	gcc -c cptodsk.c -o $(OBJDIR)/cptodsk.o
	gcc -o $(BINDIR)/cptodsk $(OBJDIR)/dskFile.o $(OBJDIR)/fatFs.o $(OBJDIR)/cptodsk.o 

dskFile.o : ../lib/dskFile.c ../lib/dskFile.h
	if [ ! -d ../obj ]; then mkdir ../obj ;	fi
	gcc -c ../lib/dskFile.c -o $(OBJDIR)/dskFile.o

fatFs.o : ../lib/fatFs.c ../lib/fatFs.h
	if [ ! -d ../obj ]; then mkdir ../obj ;	fi
	gcc -c ../lib/fatFs.c -o $(OBJDIR)/fatFs.o
