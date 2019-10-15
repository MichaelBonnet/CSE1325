#ifndef MAINWIN_H
#define MAINWIN_H

#include <gtkmm.h>
#include <stdlib.h>
#include <string>
#include "store.h"
#include "sweet.h"
#include "entrydialog.h"

class Mainwin : public Gtk::Window
{
    public:
        Mainwin();
        Mainwin(Store& store);
        virtual ~Mainwin();

    private:
        Store *_store;

        // Stuff having to do with sweets
        Gtk::MenuItem* menuitem_add_sweets;
        Gtk::MenuItem* menuitem_list_sweets;
        Gtk::ToolButton* add_sweet_button;
        Gtk::ToolButton* list_sweets_button;

        // Stuff having to do with orders
        Gtk::MenuItem* menuitem_place_order;
        Gtk::MenuItem* menuitem_list_orders;
        Gtk::ToolButton* place_order_button;
        Gtk::ToolButton* list_orders_button;

        Gtk::Label* data;  // what are
        Gtk::Label* msg;   // these even for

        void reset_sensitivity();

    protected:
        void on_new_store_click();    // done
        void on_add_sweet_click();    // done
        void on_list_sweets_click();  // done
        void on_place_order_click();
        void on_list_orders_click();
        void on_about_click();        // done
        void on_quit_click();         // done


    // Lots more Mainwin members are needed!
    // (You ARE permitted to change the above as well if you like.)
};

#endif 

