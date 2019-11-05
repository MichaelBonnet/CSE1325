#include "mainwin.h"

int main (int argc, char *argv[]) 
{
    auto app = Gtk::Application::create(argc, argv, APP_NAME);

    Mainwin win;

    app->run(win);
}
