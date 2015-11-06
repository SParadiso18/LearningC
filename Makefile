all: fibonacci complex

run:
	echo "Running: fibonacci and complex"
	./fibonacci 
	./complex

clean:
	rm -f fibonacci fibonacci.o
	rm -f complex complex.o
