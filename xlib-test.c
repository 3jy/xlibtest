#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main(void) {
    Display *d;
    Window w;
    XEvent event;
    int screen;
    
    if ((d = XOpenDisplay (getenv("DISPLAY"))) == NULL) {
        printf("Can't connect X server:%s\n", strerror(errno));
        exit(1);
    }

    screen = XDefaultScreen(d);
    w = XDefaultRootWindow(d);

    Window rootReturn, parentReturn, childrenReturn;
    unsigned int nchildrenReturn;

    while (1) {
//        XQueryTree(d, w, &rootReturn, &parentReturn
//               &childrenReturn, &nchildrenReturn);
        XWindowAttributes winAttrs;
        XGetWindowAttributes(d, parentReturn, &winAttrs);
        fprintf(stderr, "x: %d, y: %d\n", winAttrs.x, winAttrs.y);
        usleep(1000000);
    }

    return 0;
}
