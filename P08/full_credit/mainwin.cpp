#include "mainwin.h"
#include "shelter.h"
// #include "dog.h"
// #include "animal.h"
#include <sstream>

Mainwin::Mainwin() : Mainwin{*(new Shelter("Team Apocalips"))} { }

Mainwin::Mainwin(Shelter& shelter) : shelter{&shelter} 
{
	set_default_size(640, 480);
	set_title("Mavs Animal Shelter Software - Team Apocalips");


	Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
	add(*vbox);

	// Menu Bar
	Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
	vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

	// File megamenu
	Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
	menubar->append(*menuitem_file);
	Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
	menuitem_file->set_submenu(*filemenu);

	// Quit option
	Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Exit", true));
	menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
	filemenu->append(*menuitem_quit);

	// Animal megamenu
	Gtk::MenuItem *menuitem_animal = Gtk::manage(new Gtk::MenuItem("_Animal", true));
	menubar->append(*menuitem_animal);
	Gtk::Menu *animalmenu = Gtk::manage(new Gtk::Menu());
	menuitem_animal->set_submenu(*animalmenu);

	// Add animal option
	Gtk::MenuItem *menuitem_new_animal = Gtk::manage(new Gtk::MenuItem("_New", true));
	menuitem_new_animal->signal_activate().connect([this] {this->on_new_animal_click();});
	animalmenu->append(*menuitem_new_animal);

	// List animals option
	Gtk::MenuItem *menuitem_list_animals = Gtk::manage(new Gtk::MenuItem("_List", true));
	menuitem_list_animals->signal_activate().connect([this] {this->on_list_animals_click();});
	animalmenu->append(*menuitem_list_animals);

	// Data
	data = Gtk::manage(new Gtk::Label());
	data->set_hexpand(true);
	data->set_vexpand(true);
	vbox->add(*data);

	// Msg
	msg = Gtk::manage(new Gtk::Label());
	msg->set_hexpand(true);
	vbox->add(*msg);
	vbox->show_all();
}

// Destructor
Mainwin::~Mainwin() { }

// Quit implementation
void Mainwin::on_quit_click() 
{
    close();
}

// Add animal impplementation
void Mainwin::on_new_animal_click()
{
	std::string name = "";
	double age = -1;

    Gtk::Dialog *dialog = new Gtk::Dialog{"New Dog", *this};

    // Name
    Gtk::HBox name_box;

    Gtk::Label name_label{"Name:"};
    name_label.set_width_chars(20);
    name_box.pack_start(name_label, Gtk::PACK_SHRINK);

    Gtk::Entry name_entry;
    name_entry.set_max_length(50);
    name_box.pack_start(name_entry, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(name_box, Gtk::PACK_SHRINK);

    // Age
    Gtk::HBox box_age;

    Gtk::Label label_age{"Age:"};
    label_age.set_width_chars(20);
    box_age.pack_start(label_age, Gtk::PACK_SHRINK);

    Gtk::Entry entry_age;
    entry_age.set_max_length(50);
    box_age.pack_start(entry_age, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(box_age, Gtk::PACK_SHRINK);
    
    // Gender
    Gtk::HBox box_gender;

    Gtk::Label label_gender{"Gender:"};
    label_gender.set_width_chars(20);
    box_gender.pack_start(label_gender, Gtk::PACK_SHRINK);

    Gtk::ComboBoxText combobox_gender;
    
    combobox_gender.append("Male");
    combobox_gender.append("Female");
    combobox_gender.set_active(0);

    box_gender.pack_start(combobox_gender, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(box_gender, Gtk::PACK_SHRINK);

    // Breed
    Gtk::HBox box_breed;

    Gtk::Label label_breed{"Breed:"};
    label_breed.set_width_chars(20);
    box_breed.pack_start(label_breed, Gtk::PACK_SHRINK);

    Gtk::ComboBoxText combobox_breed;
    for(int i=0; i < breed_to_string.size(); ++i) 
    {
        combobox_breed.append(breed_to_string[i]); 
    }
    combobox_breed.set_active(0);

    box_breed.pack_start(combobox_breed, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(box_breed, Gtk::PACK_SHRINK);
   
    // Buttons
    dialog->add_button("Cancel", 0);
    dialog->add_button("Create", 1);

    // Showing it all
    dialog->show_all();

    // Looping and exception handling
    int result; 
    bool fail = true;  
    Gender gender;
    Dog_breed breed;

    while (fail) 
    {
        fail = false;  // optimist!
        result = dialog->run();
        if (result != 1) 
        {
            msg->set_text("Cancelled");
            delete dialog;
            return;
        }

		int g = combobox_gender.get_active_row_number();

		// select gender
		if (g == 0)
		{
			gender = Gender::male; 	
		}
		else if (g == 1) // wamen #1
		{
			gender = Gender::female;
		}
	
		// select breed
		int b = combobox_breed.get_active_row_number();
		switch (b)
		{
			case 0: 
				breed = Dog_breed::Greyhound; 
				break;
			case 1: 
				breed = Dog_breed::Akita; 
				break;
			case 2: 
				breed = Dog_breed::CardiganCorgi; 
				break;
			case 3: 
				breed = Dog_breed::BlueHeeler; 
				break;
			case 4: 
				breed = Dog_breed::Chihuahua; 
				break;
			case 5: 
				breed = Dog_breed::SaintBernard; 
				break;
			case 6: 
				breed = Dog_breed::BassetHound; 
				break;
			case 7: 
				breed = Dog_breed::BlueTick; 
				break;
		}
	
        // exception handling
        try 
        {
            age = std::stoi(entry_age.get_text());
        }
        catch(std::exception e) 
        {
            entry_age.set_text("Invalid/Improper Entry");
            fail = true;
        }

        // enter name
        name = name_entry.get_text();
        if (name.size() == 0) 
        {
            name_entry.set_text("Invalid/Improper Entry");
            fail = true;
        }

		// allocate the dog and add to shelter
		Dog* dog = new Dog(breed, name, gender, age); // jesus fuck this took a long time to unfuck
		shelter->add_animal(*dog);
	
    }
    delete dialog;
}

// List animals implementation
void Mainwin::on_list_animals_click()
{
    std::stringstream animals_list;
    for (int i = 0; i < shelter->num_animals(); i++)
    {
        animals_list << shelter->animal(i) << std::endl;
    }
    Gtk::MessageDialog{*this, animals_list.str()}.run();
}

