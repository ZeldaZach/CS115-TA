FLAGS = -g -std=c++11
USER = $(shell echo Assignment5_*.zip | cut -d '_' -f2 | cut -d "." -f1)
DIR = ~/Desktop/assignment5_student
MY_DIR = ~/Desktop/assignment5

all: Vector3D
student: unzip compile compare
studentre: compile compare

run: Vector3D
	./Vector3D

Vector3D: Vector3D.o main.o
	g++ Vector3D.o main.o -o Vector3D ${FLAGS}

Vector3D.o: Vector3D.cpp Vector3D.h
	g++ Vector3D.cpp -o Vector3D.o -c ${FLAGS}

main.o: main.cpp
	g++ main.cpp -o main.o -c ${FLAGS}

clean:
	rm -f *.o Vector3D

unzip: ~/Downloads/Assignment5_$(USER).zip
	rm -rf $(DIR)
	unzip ~/Downloads/Assignment5_$(USER).zip -d $(DIR)

compile: $(DIR)/Vector3D.cpp $(DIR)/Vector3D.h $(MY_DIR)/main.cpp
	g++ $(DIR)/Vector3D.cpp $(MY_DIR)/main.cpp -o $(DIR)/Vector3D ${FLAGS}

compare: $(DIR)/Vector3D $(MY_DIR)/answers.log
	rm -f $(DIR)/student.log
	$(DIR)/Vector3D >> $(DIR)/student.log
	md5sum $(DIR)/student.log $(MY_DIR)/answers.log
	mate $(DIR)/student.log $(MY_DIR)/answers.log
