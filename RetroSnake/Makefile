object = rs_main.o Snake.o
main.out : $(object)
	g++ -o main.out $(object)
	
rs_main.o : rs_main.cpp
Snake.o : Snake.o Snake.h

.PHONY: clean
clean: 
	-rm -f *.o