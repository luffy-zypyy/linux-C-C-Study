.PHONY:clean
hello:main.o
	gcc -o hello main.o -L./ -ldll
main.o:main.c
	gcc -o $@ -c -fPIC $^

clean:
	rm -f  main.o hello
