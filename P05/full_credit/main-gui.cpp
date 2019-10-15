#include "mainwin.h"

int main( int argc, char* argv[] )
{
    auto app = Gtk::Application::create(argc, argv, "sweetshop.app");
    Mainwin win;
    app->run(win);
}

