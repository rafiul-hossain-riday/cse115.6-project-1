
#include <gtk/gtk.h>
#include <string.h>

GtkWidget *stack;
int login_as;
char login_username[100];
char login_password[100];

#include "headers/login.h"
#include "headers/admin.h"
#include "headers/student.h"
#include "headers/teacher.h"

static void activate(GtkApplication *app, gpointer user_data);

int main(int argc, char **argv)
{
    GtkApplication *app;
    int status;

    app = gtk_application_new("org.closers.project1", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}

static void activate(GtkApplication *app, gpointer user_data)
{
    GtkWidget *window, *scroll_window, *login_page, *admin_launch_page, *student_launch_page, *teacher_launch_page;

    // styling
    // GtkCssProvider *css_all = gtk_css_provider_new();
    // gtk_css_provider_load_from_path(css_all, "style.css");
    // gtk_style_context_add_provider_for_display(gdk_display_get_default(), GTK_STYLE_PROVIDER(css_all), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "RDS 4.0");
    gtk_window_set_default_size(GTK_WINDOW(window), 450, 350);

    scroll_window = gtk_scrolled_window_new();

    stack = gtk_stack_new();
    gtk_widget_set_halign(stack, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(stack, GTK_ALIGN_CENTER);

    // Create the pages
    login_page = f_login_page();
    admin_launch_page = f_admin_launch_page();
    student_launch_page = f_student_launch_page();
    teacher_launch_page = f_teacher_launch_page();

    // Add the pages to the stack
    gtk_stack_add_named(GTK_STACK(stack), login_page, "login-page");
    gtk_stack_add_named(GTK_STACK(stack), admin_launch_page, "admin-launch-page");
    gtk_stack_add_named(GTK_STACK(stack), student_launch_page, "student-launch-page");
    gtk_stack_add_named(GTK_STACK(stack), teacher_launch_page, "teacher-launch-page");

    // Set the initial page
    gtk_stack_set_visible_child_name(GTK_STACK(stack), "login-page");

    gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(scroll_window), stack);
    gtk_window_set_child(GTK_WINDOW(window), scroll_window);
    gtk_window_present(GTK_WINDOW(window));

    // g_object_unref(css_all);
}
