#include "global-iup.h"

char selected[10];

int login_option_select(Ihandle *self, char *text, int item, int state)
{
    if (state == 1)
    {
        strcpy(selected, text);
    }
    return IUP_DEFAULT;
}

int main(int argc, char **argv)
{
    IupOpen(&argc, &argv);

    // Create the main page
    Ihandle *window,
        *user_id = IupText(NULL),
        *user_passwd = IupText(NULL),
        *container,
        *login_option = IupList(NULL);

    IupSetAttribute(user_id, "SIZE", "70");
    IupSetAttribute(user_passwd, "SIZE", "70");
    IupSetAttribute(login_option, "SIZE", "70");

    IupSetAttribute(login_option, "1", "Student");
    IupSetAttribute(login_option, "2", "Teacher");
    IupSetAttribute(login_option, "DROPDOWN", "YES");
    IupSetCallback(login_option, "ACTION", (Icallback)login_option_select); // Set the callback function

    container = IupVbox(
        IupHbox(IupLabel("Login as   : "), login_option, NULL),
        IupHbox(IupLabel("ID              : "), user_id, NULL),
        IupHbox(IupLabel("Password : "), user_passwd, NULL),
        NULL);

    IupSetAttribute(container, "MARGIN", "10x5");

    // Create the window for the main page
    window = IupDialog(container);

    IupSetAttribute(window, "TITLE", "Main Page");
    IupSetAttribute(window, "SIZE", "200x100");

    IupShowXY(window, IUP_CENTER, IUP_CENTER);

    IupMainLoop();
    IupClose();

    return 0;
}
