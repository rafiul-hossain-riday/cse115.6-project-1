#include "global-iup.h"

// functions
int on_select_login_option(Ihandle *self, char *text, int item, int state);
int on_submit(Ihandle *self);
Ihandle *create_launch_window();

// static global variables
int selected_option = 0;
Ihandle *launch_window;

int main(int argc, char **argv)
{
    IupOpen(&argc, &argv);

    launch_window = create_launch_window();

    IupShowXY(launch_window, IUP_CENTER, IUP_CENTER);

    IupMainLoop();
    IupClose();

    return EXIT_SUCCESS;
}

int on_select_login_option(Ihandle *self, char *text, int item, int state)
{
    if (state == 1)
    {
        selected_option = item;
    }
    return IUP_DEFAULT;
}

int on_submit(Ihandle *self)
{
    if (0)
        IupMessagef("Error", "Pass not right", "");
    else
    {
        // system("dir");
        system("student_window.exe \"id id\" \"pass pass\"");
        IupHide(launch_window);
        return IUP_CLOSE;
    }
}

Ihandle *create_launch_window()
{
    Ihandle *launch_window,
        *user_id = IupText(""),
        *user_passwd = IupText(""),
        *container,
        *login_option = IupList(NULL),
        *submit = IupButton("Log In", NULL);

    IupSetCallback(submit, "ACTION", (Icallback)on_submit);

    IupSetAttribute(login_option, "SIZE", "50x18");
    IupSetAttribute(user_id, "SIZE", "80");
    IupSetAttribute(user_passwd, "SIZE", "80");

    IupSetAttribute(login_option, "1", "Student");
    IupSetAttribute(login_option, "2", "Teacher");
    IupSetAttribute(login_option, "DROPDOWN", "NO");
    IupSetCallback(login_option, "ACTION", (Icallback)on_select_login_option);

    container = IupVbox(
        IupHbox(IupLabel("Login as     :  "), login_option, NULL),
        IupHbox(IupLabel("ID               :  "), user_id, NULL),
        IupHbox(IupLabel("Password  :  "), user_passwd, NULL),
        submit,
        NULL);

    IupSetAttribute(container, "MARGIN", "10x3");

    launch_window = IupDialog(container);

    IupSetAttribute(launch_window, "TITLE", "Log In");
    IupSetAttribute(launch_window, "SIZE", "200x100");
    IupSetAttribute(launch_window, "FONT", "Arial, 11");

    return launch_window;
}
