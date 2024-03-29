#include "client.h"

Client::Client(std::string name, std::string phone, std::string email) : _name{name}, _phone{phone}, _email{email} { }

Client::~Client() { }

std::string Client::to_string() const 
{
	return _name + ", " + _phone + ", " + _email;
}

std::string Client::name() const 
{
	return _name;
}

std::string Client::phone() const 
{
	return _phone;
}

std::string Client::email() const 
{
	return _email;
}

void Client::adopt(Animal& animal)
{
	_adopted.push_back(&animal);
}

int Client::num_adopted() 
{
	return _adopted.size();
}

Animal& Client::animal(int index) const
{
	return *(_adopted[index]);
}

std::ostream& operator<<(std::ostream& ost, const Client& client)
{
    ost << client.to_string();
    return ost;
}