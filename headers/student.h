
GtkWidget *f_student_launch_page()
{
    GtkWidget *page = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_box_append(GTK_BOX(page), gtk_label_new("student launch page"));

    return page;
}
