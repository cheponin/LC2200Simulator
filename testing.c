#include <gtk/gtk.h>

typedef struct {
	GtkWidget *window1;
	GtkWidget *entry1;
	GtkWidget *entry2;
	GtkWidget *label1;
} AppWidgets;

int main( int    argc,
      char **argv )
{
    GtkBuilder *builder;
    GtkWidget  *window;
    GError     *error = NULL;

    /* Init GTK+ */
    gtk_init( &argc, &argv );

    /* Create new GtkBuilder object */
    builder = gtk_builder_new();
    /* Load UI from file. If error occurs, report it and quit application.
     * Replace "tut.glade" with your saved project. */
    if( ! gtk_builder_add_from_file( builder, "testing.glade", &error ) )
    {
        g_warning( "%s", error->message );
        g_free( error );
        return( 1 );
    }

    /* Get main window pointer from UI */
    window = GTK_WIDGET( gtk_builder_get_object( builder, "LC2200" ) );

    /* Connect signals */
    gtk_builder_connect_signals( builder, NULL );

    /* Destroy builder, since we don't need it anymore */
    g_object_unref( G_OBJECT( builder ) );

    /* Show window. All other widgets are automatically shown by GtkBuilder */
    gtk_widget_show( window );

    /* Start main loop */
    gtk_main();

    return( 0 );
}

/* Show the About box */
void help_about(GtkWidget *widget){
	gtk_dialog_run(GTK_DIALOG(widget));
	gtk_widget_hide(widget);
}

void file_open(GtkWidget *widget){
}
