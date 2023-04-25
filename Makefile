PRJ = $(shell basename $(CURDIR))

all: $(PRJ)

$(PRJ): *.c
	-@gcc $(file).c -Wall -std=c17 -o ./build/$(PRJ)

run:
	-@clear
	-@gcc ./libs/*/*.c  main.c -Wall -std=c17  -lm -o ./build/$(PRJ)
	-@./build/$(PRJ) $(st) $(fl)

runner:
	-@clear
	-@gcc ./libs/*/*.c $(code) -Wall -std=c17  -lm -o ./build/$(PRJ)
	-@./build/$(PRJ)

testa:
	-@clear
	-@gcc ./libs/*/*.c test/$(code)/*.c -lm -Wall -std=c17 -o $(code).n

.PHONY: clean

clean:
	echo "Limpando.."
	-@rm -f $(PRJ) *.o *~
	-@rm *.n
	-@rm S*.md
	-@rm D*.md
	-@rm *.html

