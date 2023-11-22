#include "global-iup.h"

int main(int argc, char **argv)
{
    IupOpen(&argc, &argv);

    // Create the main page
    Ihandle *dlg, *user_id, *user_passwd, *container;

    char tmp[150];
    sprintf(tmp, "Name       : %s", argv[1]);
    user_id = IupLabel(tmp);

    sprintf(tmp, "Password : %s", argv[2]);
    user_passwd = IupLabel(tmp);

    container = IupVbox(user_id, user_passwd, NULL);
    IupSetAttribute(container, "GAP", "5");
    IupSetAttribute(container, "MARGIN", "10x10");

    // Create the dialog for the main page
    dlg = IupDialog(container);

    IupSetAttribute(dlg, "TITLE", "Main Page");
    IupSetAttribute(dlg, "SIZE", "200x100");

    IupShowXY(dlg, IUP_CENTER, IUP_CENTER);

    IupMainLoop();
    IupClose();

    return 0;
}
