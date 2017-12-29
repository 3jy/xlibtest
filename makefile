LIBS=-lX11
xlib-test: xlib-test.c
	cc -o bin/xtest xlib-test.c $(LIBS)
