#include "global-iup.h"

int data_arr[] = {12, 34, 56, 69, 23, 54, 67, 34, 86, 4, 6};
int data_arr_size = sizeof(data_arr) / sizeof(int);

int index_extract(char *str, int len)
{
    char buff[10] = "";
    int i, j;

    for (i = 0; i < len; ++i)
    {
        if (str[i] == 'L' && str[i + 1] == 'O' && str[i + 2] == 'O' && str[i + 3] == 'P' && str[i + 4] == '_' && str[i + 5] == 'D' && str[i + 6] == 'A' && str[i + 7] == 'T' && str[i + 8] == 'A' && str[i + 9] == '[')
        {
            j = i + 10;
            while (j < len)
            {
                if (str[j] == ']')
                    return atoi(buff);
                else
                {
                    buff[strlen(buff)] = str[j];
                    buff[strlen(buff) + 1] = '\0';
                }

                j++;
            }
        }
    }
    return -1;
}

int increment_func(Ihandle *self)
{
    Ihandle *parent = IupGetParent(self);
    Ihandle *text = IupGetChild(parent, 1);
    int value = IupGetInt(text, "VALUE");
    IupSetInt(text, "VALUE", ++value);

    char *attr_list = IupGetAttributes(self);
    int idx = index_extract(attr_list, strlen(attr_list));
    printf("%d\n", idx);

    return IUP_DEFAULT;
}

int decrement_func(Ihandle *self)
{
    Ihandle *parent = IupGetParent(self);
    Ihandle *text = IupGetChild(parent, 1);
    int value = IupGetInt(text, "VALUE");
    IupSetInt(text, "VALUE", --value);

    char *attr_list = IupGetAttributes(self);
    int idx = index_extract(attr_list, strlen(attr_list));
    printf("%d\n", idx);

    return IUP_DEFAULT;
}

int main(int argc, char **argv)
{
    IupOpen(&argc, &argv);
    int i;

    Ihandle *take_attendance_window, *vbox;
    vbox = IupVbox(NULL);

    for (i = 0; i < data_arr_size; ++i)
    {
        char i_str[10];
        sprintf(i_str, "%d", i);

        Ihandle *increment_btn, *decrement_btn, *text, *hbox = IupHbox(NULL);
        IupSetHandle(i_str, hbox);

        increment_btn = IupButton("+", NULL);
        decrement_btn = IupButton("-", NULL);
        IupSetAttribute(increment_btn, "SIZE", "30");
        IupSetAttribute(decrement_btn, "SIZE", "30");

        IupSetCallback(increment_btn, "ACTION", (Icallback)increment_func);
        IupSetCallback(decrement_btn, "ACTION", (Icallback)decrement_func);

        char index_attr_name[10];
        sprintf(index_attr_name, "LOOP_DATA[%d]", i);

        IupSetAttribute(increment_btn, index_attr_name, "IGNORE");
        IupSetAttribute(decrement_btn, index_attr_name, "IGNORE");

        text = IupText(NULL);
        IupSetInt(text, "VALUE", data_arr[i]);
        IupSetAttribute(text, "INDEX", i_str);
        IupSetAttribute(text, "SIZE", "30");
        IupSetAttribute(text, "READONLY", "NO");

        hbox = IupHbox(
            IupVbox(IupLabel("Name : Random Name Here   "),
                    IupLabel("ID     : 2320000   "), NULL),
            text,
            increment_btn,
            decrement_btn,
            NULL);
        IupSetAttribute(hbox, "MARGIN", "10x10");
        IupSetAttribute(hbox, "GAP", "5");
        IupSetAttribute(hbox, "ALIGNMENT", "ACENTER");

        IupAppend(vbox, hbox);
    }

    take_attendance_window = IupDialog(IupScrollBox(vbox));
    IupSetAttribute(take_attendance_window, "TITLE", "Counter");
    IupSetAttribute(take_attendance_window, "SIZE", "300x400");
    IupShowXY(take_attendance_window, IUP_CENTER, IUP_CENTER);

    IupMainLoop();

    IupClose();
    return EXIT_SUCCESS;
}
