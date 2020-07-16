bin/ColaTDA: obj/main.o obj/queueTDA.o
	gcc -Wall -fsanitize=address $^ -o $@
obj/main.o: src/main.c
	gcc -Wall -fsanitize=address -I include/ -c src/main.c -o $@
obj/queueTDA.o: src/queueTDA.c
	gcc -Wall -fsanitize=address -I include/ -c src/queueTDA.c -o $@
clean:
	rm bin/ColaTDA obj/*
