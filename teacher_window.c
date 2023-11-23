#include "global-iup.h"

// global variables
Ihandle *teacher_window;

Ihandle *create_teacher_window()
{
    Ihandle *user_id, *user_passwd, *container;

    char tmp[150];
    sprintf(tmp, "Name       : %s", "argv[1]");
    user_id = IupLabel(tmp);

    sprintf(tmp, "Password : %s", "argv[2]");
    user_passwd = IupLabel(tmp);

    container = IupVbox(user_id, user_passwd, NULL);
    IupSetAttribute(container, "GAP", "5");
    IupSetAttribute(container, "MARGIN", "10x10");

    // Create the dialog for the main page
    teacher_window = IupDialog(container);

    IupSetAttribute(teacher_window, "TITLE", "Main Page");
    IupSetAttribute(teacher_window, "SIZE", "200x100");
    IupSetAttribute(teacher_window, "FONT", "Arial, 11");

    return teacher_window;
}

int main(int argc, char **argv)
{
    IupOpen(&argc, &argv);

    teacher_window = create_teacher_window();
    IupShowXY(teacher_window, IUP_CENTER, IUP_CENTER);

    IupMainLoop();
    IupClose();

    return EXIT_SUCCESS;
}
