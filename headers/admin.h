
GtkWidget *f_admin_launch_page()
{
    GtkWidget *page = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_box_append(GTK_BOX(page), gtk_label_new("admin launch page"));

    return page;
}
