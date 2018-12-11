#include "ui.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "file_manipulator.h"

struct data
{
    uiWindow *window;
    uiMultilineEntry *multiline;
};

static void init_data(struct data* data, uiWindow *window, uiMultilineEntry *multiline)
{
    data->window = window;
    data->multiline = multiline;
}

static int window_closed(uiWindow *w, void *data)
{
    uiQuit();
    return 1;
}

static void button_clicked(uiButton *uiButton, void *data)
{
    struct data *_data = (struct data *)data;

    char *filename = uiOpenFile((uiWindow *)_data->window);
    FILE *stream;

    if(exists(&stream, filename) == 0)
    {

        int size = get_file_length(stream);
        char *filedata = malloc(sizeof(char) * size);

        read_file(filename, filedata, size);

        uiMultilineEntry *multiline = _data->multiline;
        uiMultilineEntrySetText(multiline, filedata);
    }
}

int main(int argc, char const *argv[])
{
    uiInitOptions options;
    memset(&options, 0, sizeof(uiInitOptions));
    uiInit(&options);

    //window
    uiWindow *window = uiNewWindow("test", 800, 600, 0); 
    if(!window)
        printf_s("Error: window not initialized");

    uiWindowOnClosing(window, window_closed, NULL);

    uiBox *verticalBox = uiNewVerticalBox();

    //button
    uiButton *button = uiNewButton("select file");
    uiBoxAppend(verticalBox, uiControl(button), 0);

    //multiline
    uiMultilineEntry *multiline = uiNewMultilineEntry();
    uiBoxAppend(verticalBox, uiControl(multiline), 0);
    uiMultilineEntrySetReadOnly(multiline, 1);
    
    //set button on click event
    struct data *data = malloc(sizeof(struct data));
    init_data(data, window, multiline);
    uiButtonOnClicked(button, button_clicked, (void *)data);

    uiWindowSetChild(window, uiControl(verticalBox));

    uiControlShow(uiControl(window));

    uiMain();

    return 0;
}
