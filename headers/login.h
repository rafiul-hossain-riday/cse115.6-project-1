GtkWidget *dropdown, *username, *password;

static void on_dropdown_changed(GtkDropDown *dropdown, gpointer user_data)
{
    login_as = gtk_drop_down_get_selected(dropdown);
}

static void on_username_change(GtkEditable *inp, gpointer data)
{
    strcpy(login_username, gtk_editable_get_text(inp));
}

static void on_password_change(GtkEditable *inp, gpointer data)
{
    strcpy(login_password, gtk_editable_get_text(inp));
}

static void on_click_reset(GtkWidget *btn, gpointer data)
{
    gtk_drop_down_set_selected(GTK_DROP_DOWN(dropdown), 0);
    gtk_editable_set_text(GTK_EDITABLE(username), "");
    gtk_editable_set_text(GTK_EDITABLE(password), "");
}

static void on_click_login(GtkWidget *btn, gpointer data)
{
    if (login_as == 1)
    {
        if (strcmp(login_username, "admin") == 0 && strcmp(login_password, "pass") == 0)
        {
            gtk_stack_set_visible_child_name(GTK_STACK(stack), "admin-launch-page");
        }
    }
}

GtkWidget *f_login_page()
{
    GtkWidget *page, *grid, *reset, *login;
    GtkStringList *list;
    GtkExpression *expression;

    // dropdown
    list = gtk_string_list_new(NULL);

    gtk_string_list_append(list, "Select");
    gtk_string_list_append(list, "Admin");
    gtk_string_list_append(list, "Teacher");
    gtk_string_list_append(list, "Student");

    dropdown = gtk_drop_down_new(G_LIST_MODEL(list), NULL);
    g_signal_connect(dropdown, "notify::selected", G_CALLBACK(on_dropdown_changed), NULL);

    // input
    username = gtk_entry_new();
    g_signal_connect(username, "changed", G_CALLBACK(on_username_change), NULL);
    gtk_entry_set_placeholder_text(GTK_ENTRY(username), "username");

    password = gtk_entry_new();
    g_signal_connect(password, "changed", G_CALLBACK(on_password_change), NULL);
    gtk_entry_set_placeholder_text(GTK_ENTRY(password), "password");

    reset = gtk_button_new_with_label("Reset");
    g_signal_connect(reset, "clicked", G_CALLBACK(on_click_reset), NULL);
    login = gtk_button_new_with_label("Login");
    g_signal_connect(login, "clicked", G_CALLBACK(on_click_login), NULL);

    // grid
    grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 5);
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);

    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Login as"), 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), dropdown, 1, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Username"), 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), username, 1, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Password"), 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), password, 1, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), reset, 0, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), login, 1, 3, 1, 1);

    page = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_widget_set_halign(page, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(page, GTK_ALIGN_CENTER);

    gtk_box_append(GTK_BOX(page), grid);

    return page;
}
