# dsktools (C) 2005,2022 Tatsuhiko Shoji
# The sources for dsktools are distributed under the MIT open source license

SETUP_DESTINATION := ~/bin
EXECUTABLE_DIR := bin
OBJECT_DIR := obj
MAKEFILE_DIR := $(dir $(lastword $(MAKEFILE_LIST)))

ALL : clean bin/cptodsk
	cp bin/* $(SETUP_DESTINATION)

bin/cptodsk:
	cd $(MAKEFILE_DIR)cptodsk ; make

clean :
	if [ -d $(EXECUTABLE_DIR) ]; then rm -r $(EXECUTABLE_DIR) ;	fi
	if [ -d $(OBJECT_DIR) ]; then rm -r $(OBJECT_DIR) ;	fi
	if [ -f $(SETUP_DESTINATION)/cptodsk ]; then rm $(SETUP_DESTINATION)/cptodsk ;	fi
