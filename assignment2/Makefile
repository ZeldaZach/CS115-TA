DIR = ~/Desktop/assignment2
USER = $(shell echo assignment2_*.zip | cut -d '_' -f2 | cut -d "." -f1)

all: unzip compile run finish
rerun: compile run finish
run: run_maximum run_guessingGame run_identityMatrixPrint

unzip: $(shell pwd)/assignment2_$(USER).zip
	rm -rf $(DIR)
	unzip $(shell pwd)/assignment2_$(USER).zip -d $(DIR)

compile: $(DIR)/maximum.cpp $(DIR)/guessingGame.cpp $(DIR)/identityMatrixPrint.cpp
	g++ $(DIR)/maximum.cpp -o $(DIR)/maximum
	
	perl -pi -e 's/rand\(\)/49/g' $(DIR)/guessingGame.cpp
	g++ $(DIR)/guessingGame.cpp -o $(DIR)/guessingGame
	
	g++ $(DIR)/identityMatrixPrint.cpp -o $(DIR)/identityMatrixPrint

run_maximum: $(DIR)/maximum
	echo "\nInputs: 100 2 33" >> $(DIR)/output.log
	$(DIR)/maximum <<< """100 2 33""" >> $(DIR)/output.log
	
	echo "\nInputs: 33 3 33" >> $(DIR)/output.log
	$(DIR)/maximum <<< """33 3 33""" >> $(DIR)/output.log
	
	echo "\nInputs: 33 33 33" >> $(DIR)/output.log
	$(DIR)/maximum <<< """33 33 33""" >> $(DIR)/output.log
	
	echo "\nInputs: -1 -1000 -33" >> $(DIR)/output.log
	$(DIR)/maximum <<< """-1 -1000 -33""" >> $(DIR)/output.log
	
	echo "\nInputs: -1 0 44" >> $(DIR)/output.log
	$(DIR)/maximum <<< """-1 0 44""" >> $(DIR)/output.log
	
	echo "\nInputs: -1 1044 44" >> $(DIR)/output.log
	$(DIR)/maximum <<< """-1 1044 44""" >> $(DIR)/output.log
	

run_guessingGame: $(DIR)/guessingGame
	echo "\nInputs: 10 30 49 51 100" >> $(DIR)/output.log
	$(DIR)/guessingGame <<< """10 30 49 51 100""" >> $(DIR)/output.log
	sleep 1
	
	echo "\nInputs: 15 25 34 45 80" >> $(DIR)/output.log
	$(DIR)/guessingGame <<< """15 25 34 45 80""" >> $(DIR)/output.log
	sleep 1
	
	echo "\nInputs: 12 24 100 50" >> $(DIR)/output.log
	$(DIR)/guessingGame <<< """12 24 100 50""" >> $(DIR)/output.log

run_identityMatrixPrint: $(DIR)/identityMatrixPrint
	echo "\nInput: 3" >> $(DIR)/output.log
	$(DIR)/identityMatrixPrint <<< """3""" >> $(DIR)/output.log
	
	echo "\nInput: 10" >> $(DIR)/output.log
	$(DIR)/identityMatrixPrint <<< """10""" >> $(DIR)/output.log
	
	echo "\nInput: 15" >> $(DIR)/output.log
	$(DIR)/identityMatrixPrint <<< """15""" >> $(DIR)/output.log
	
finish:
	$(shell mate $(DIR)/output.log $(DIR)/maximum.cpp $(DIR)/guessingGame.cpp $(DIR)/identityMatrixPrint.cpp)
	echo "$(USER) log files done"
	