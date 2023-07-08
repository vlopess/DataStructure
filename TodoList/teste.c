#include <gtk/gtk.h>

// Função de callback chamada quando a janela é fechada
void on_window_closed(GtkWidget *widget, gpointer data) {
    gtk_main_quit();
}

int main(int argc, char *argv[]) {
    GtkWidget *window;

    gtk_init(&argc, &argv);

    // Cria a janela
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Minha Janela");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);

    // Conecta o sinal "destroy" à função de callback
    g_signal_connect(window, "destroy", G_CALLBACK(on_window_closed), NULL);

    // Exibe a janela
    gtk_widget_show_all(window);

    // Inicia o loop principal da GTK
    gtk_main();

    return 0;
}
