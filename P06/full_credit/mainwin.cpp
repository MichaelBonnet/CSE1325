#include "mainwin.h"
#include "entrydialog.h"
#include <sstream>
#include <stdlib.h>
#include <string>

Mainwin::Mainwin() : Mainwin{*(new Store)} { }
Mainwin::Mainwin(Store& store) : _store{&store} {

    // /////////////////
    // G U I   S E T U P
    // /////////////////
	set_default_size(400, 400);
        set_title("Mav's Ultimate Sweet Shop");
    	
 	Gtk::Label* data{Gtk::manage(new Gtk::Label{"Hello!"})};
    // Set up a vertical box to hold the main window elements
	Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
  	add(*vbox);

    // ///////
    // M E N U
    // Add and configure a menu bar as the top item in the vertical box
	Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

 	Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

	Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuitem_quit);

	Gtk::MenuItem *menuitem_new_store = Gtk::manage(new Gtk::MenuItem("_New Store", true));
    menuitem_new_store->signal_activate().connect([this] {this->on_new_store_click();});
    filemenu->append(*menuitem_new_store);

    // Sweets Menu
    Gtk::MenuItem *menuitem_sweets = Gtk::manage(new Gtk::MenuItem("_Sweets", true));
    menubar->append(*menuitem_sweets);
    Gtk::Menu *sweetsmenu = Gtk::manage(new Gtk::Menu());
    menuitem_sweets->set_submenu(*sweetsmenu);

	// Add Sweet option
    Gtk::MenuItem *menuitem_add_sweet = Gtk::manage(new Gtk::MenuItem("_Add Sweets", true));
    menuitem_add_sweet->signal_activate().connect([this] {this->on_add_sweet_click();});
    sweetsmenu->append(*menuitem_add_sweet);
	
	// List Sweets option
    Gtk::MenuItem *menuitem_list_sweets = Gtk::manage(new Gtk::MenuItem("_List Sweets", true));
    menuitem_list_sweets->signal_activate().connect([this] {this->on_list_sweets_click();});
    sweetsmenu->append(*menuitem_list_sweets);

	// Orders Menu
    Gtk::MenuItem *menuitem_orders = Gtk::manage(new Gtk::MenuItem("_Orders", true));
    menubar->append(*menuitem_orders);
    Gtk::Menu *ordersmenu = Gtk::manage(new Gtk::Menu());
    menuitem_orders->set_submenu(*ordersmenu);

	// Add Order
    Gtk::MenuItem *menuitem_place_order = Gtk::manage(new Gtk::MenuItem("_Add Order", true));
    menuitem_place_order->signal_activate().connect([this] {this->on_place_order_click();});
    ordersmenu->append(*menuitem_place_order);
	
	// List Orders
    Gtk::MenuItem *menuitem_list_orders = Gtk::manage(new Gtk::MenuItem("_List Orders", true));
    menuitem_list_orders->signal_activate().connect([this] {this->on_list_orders_click();});
    ordersmenu->append(*menuitem_list_orders);

	// Help Menu
	Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);

	// Menu Option
    Gtk::MenuItem *menuitem_About = Gtk::manage(new Gtk::MenuItem("_About", true));
    menuitem_About->signal_activate().connect([this] {this->on_about_click();});
    helpmenu->append(*menuitem_About);

	
	vbox->pack_start(*data);

    // /////////////
    // T O O L B A R
    // Add a toolbar to the vertical box just below the menu (bonus level)


    // ///////////////////////
    // D A T A   D I S P L A Y
    // Provide a text entry box to show the sweets and orders



    // ///////////////////////////////////    
    // S T A T U S   B A R   D I S P L A Y
    // Provide a status bar for transient messages


    // Make the vertical box and everything in it visible
 	vbox->show_all();
}

Mainwin::~Mainwin() { }

// /////////////////
// C A L L B A C K S
// ///////////////// 
void Mainwin::on_quit_click() 
{
    	close();
}

void Mainwin::on_new_store_click() 
{
	_store = new Store();
}

void Mainwin::on_add_sweet_click() 
{
	std::string name;
    	double price;
	EntryDialog ndialog{*this, "Create Name for Sweet: "};
    	ndialog.set_text("Enter a name");
    	ndialog.run();
	name = ndialog.get_text();
	EntryDialog pdialog{*this, "Create Price for " + name + ": "};
    	pdialog.set_text("2.00");
	pdialog.run();
	price = std::stod(pdialog.get_text());
	Sweet sweet{name, price};
	_store->add(sweet);
}

void Mainwin::on_list_sweets_click()
{
	std::string sweets_list;
    	for (int i = 0; i < _store->num_sweets(); i++)
    	{
        	Sweet tempsweet = _store->sweet(i);
        	sweets_list += tempsweet.name() + ": ";
        	sweets_list += std::to_string(tempsweet.price());
        	sweets_list += "\n";
    	}
    Gtk::MessageDialog{*this, sweets_list}.run();

    /* stringstream implementation
    {
        std::stringstream sweets_list;
        for (int i = 0; i < _store->num_sweets(); i++)
        {
            sweets_list << _store->sweet(i) << std::endl;
        }
        Gtk::MessageDialog{*this, sweets_list.str()}.run();
    }
    */
}

void Mainwin::on_about_click() 
{
    Gtk::MessageDialog{"Holy cannoli please save me. - Michael Bonnet"}.run();
}

void Mainwin::on_place_order_click()
{
    Order order;

    std::string name = "";
    double price = -1;
	Gtk::Dialog *dialog = new Gtk::Dialog{"Create Order", *this};

       // Name
    Gtk::HBox box;

    Gtk::Label qty_prompt{"Quantity: "};
    qty_prompt.set_width_chars(15);
    box.pack_start(qty_prompt);

    Gtk::Entry entry;
    entry.set_max_length(50);
    box.pack_start(entry);
    dialog->get_vbox()->pack_start(box);

       // Price
    Gtk::HBox box_sweet;

    Gtk::Label sweet_prompt{"Sweet: "};
    sweet_prompt.set_width_chars(15);
    box_sweet.pack_start(sweet_prompt);
	
    Gtk::ComboBoxText cbt;
    box_sweet.pack_start(cbt);
    for (int i = 0; i < _store->num_sweets(); i++)
    {
       	cbt.append( _store->sweet(i).name() );
    }

    cbt.set_active(1);
    cbt.signal_changed().connect([this, &cbt] {});

    dialog->get_vbox()->pack_start(box_sweet);
    // Show dialog
    dialog->add_button("Cancel", 0);
    dialog->add_button("Add", 1);
    dialog->add_button("Place Order", 2);

    dialog->show_all();
    int result; // of the dialog (1 = OK)
    bool fail = true;  // set to true if any data is invalid
    
    Order new order;
    while (fail) 
    {
        result = dialog->run();
        if (result == 0)
        {
            delete dialog;
            return;
        }
        if (result == 1)
        {
            order.add(std::stoi(e_quantity.get_text()), _store->sweet(cbt.get_active_row_number()));
            return;
        }
        if (result == 2)
        {
            _store->add(order);
            delete order;
            dialog.close();
            return;
        }
    }
}

void Mainwin::on_list_orders_click()
{
    std::stringstream orders_list;
    for (int i = 0; i < _store->num_orders(); i++)
    {
        orders_list << _store->order(i) << std::endl;
    }
    Gtk::MessageDialog{*this, orders_list.str()}.run();
}







// /////////////////
// U T I L I T I E S
// /////////////////


