#include "global-iup.h"

Ihandle *student_window;

Ihandle *create_student_window()
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
    student_window = IupDialog(container);

    IupSetAttribute(student_window, "TITLE", "Student");
    IupSetAttribute(student_window, "SIZE", "200x100");
    IupSetAttribute(student_window, "FONT", "Arial, 11");

    return student_window;
}

int main(int argc, char **argv)
{
    IupOpen(&argc, &argv);

    student_window = create_student_window();
    IupShowXY(student_window, IUP_CENTER, IUP_CENTER);

    IupMainLoop();
    IupClose();

    return EXIT_SUCCESS;
}
