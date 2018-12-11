#include "ui.h"
#include <string.h>
#include <stdio.h>

static int window_closed(uiWindow *w, void *data)
{
    uiQuit();
    return 1;
}

int main(int argc, char const *argv[])
{
    uiInitOptions options;
    memset(&options, 0, sizeof(uiInitOptions));
    uiInit(&options);

    uiWindow *window = uiNewWindow("test", 800, 600, 0); 
    if(!window)
        printf_s("Error: window not initialized");

    uiWindowOnClosing(window, window_closed, NULL);

    uiBox *verticalBox = uiNewVerticalBox();

    uiButton *button = uiNewButton("select file");
    uiBoxAppend(verticalBox, uiControl(button), 0);

    uiWindowSetChild(window, uiControl(verticalBox));

    uiControlShow(uiControl(window));

    uiMain();

    return 0;
}
