#include "mainwin.h"

Mainwin::Mainwin() 

: scale{Gtk::manage(new Gtk::Scale)},
  comboboxtext{Gtk::manage(new Gtk::ComboBoxText{true})}

{
    set_title("Michael Bonnet 15");
    Gtk::VBox *vbox = Gtk::manage(new Gtk::VBox)
    add(*vbox); // to Mainwin

    vbox->pack_start(*scale);
    scale->set_range(0.0, 100.0);
    scale->set_increments(1.0, 1.0);

    vbox->pack_start(*comboboxtext);
    comboboxtext->append("Square Root");
    comboboxtext->append("Natural Logarithm");
    comboboxtext->append("Trigonometric Cosine");
    comboboxtext->set_active(1);
    comboboxtext->signal_changed().connect([this] {this->on_comboboxtext_activate();});
}

Mainwin::~Mainwin() { }

void Mainwin::on_comboboxtext_activate() {
    std::string s;

    if (comboboxtext->get_active_row_number() == 1)
    {
    	s = std::to_string(sqrt(scale->get_value()));
    }
    else if (comboboxtext->get_active_row_number() == 2)
    {
    	s = std::to_string(log(scale->get_value()));
    }
    else if (comboboxtext->get_active_row_number() == 3)
    {
    	s = std::to_string(cos(scale->get_value()));
    }
    Gtk::MessageDialog{*this, s}.run();
}

void Mainwin::on_scale_value_changed() {
    int sp = scale->get_value();
    label->set_text(std::to_string(sp*sp));
    progressbar->set_fraction(sqrt(scale->get_value())/10.0);
}