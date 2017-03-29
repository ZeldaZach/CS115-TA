FLAGS = -g -std=c++14
USER = $(shell echo Assignment6_*.zip | cut -d '_' -f2 | cut -d "." -f1)
DIR = ~/Desktop/assignment6_student
MY_DIR = ~/Desktop/assignment6
PKG_CONFIG = `pkg-config --cflags --libs opencv`

all: student
student: unzip compile run
studentre: compile run

run: compile
	$(DIR)/Viewer

clean:
	rm -r $(DIR)

unzip: ~/Downloads/Assignment6_$(USER).zip
	rm -rf $(DIR)
	unzip ~/Downloads/Assignment6_$(USER).zip -d $(DIR)

compile: $(DIR)/Viewer.cpp $(DIR)/Viewer.h $(MY_DIR)/main.cpp
	g++ $(PKG_CONFIG) $(DIR)/Viewer.cpp $(MY_DIR)/main.cpp -o $(DIR)/Viewer ${FLAGS}