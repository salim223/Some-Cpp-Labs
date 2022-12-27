#include <iostream>
#include <string>

using namespace std;

#include "Party.h"

Party::Party()
{
    //Default: 10 attendees, location = home
    location = "Home";
    maxAttendees = 10;
    numAttendees = 0;
    attendees = new string[maxAttendees];
}

Party::Party(string l, int num)
{
    maxAttendees = 10;
    numAttendees = 0;
    location = l;
    if (num > 0)
        maxAttendees = num;
    attendees = new string[maxAttendees];
}
//If the input integer is not positive, set maxAttendees = 10

Party::Party(const Party& copy)                                //Define the copy constructor
{
    location = copy.location;
    maxAttendees = copy.maxAttendees;
    numAttendees = copy.numAttendees;

    attendees = new string[maxAttendees];
    for (int i = 0; i < maxAttendees; i++)
    {
        attendees[i] = copy.attendees[i];
    }
}

Party& Party::operator= (const Party& party)                    //Define the overloaded copy assignment operator (=)
{
    if (this != &party)
    {
        delete[] attendees;
    }
    location = party.location;
    maxAttendees = party.maxAttendees;
    numAttendees = party.numAttendees;
    attendees = new string[maxAttendees];
    for (int i = 0; i < maxAttendees; i++)
    {
        attendees[i] = party.attendees[i];
    }
    return *this;
}

Party Party::operator+ (string rhs) const                  //Define the overloaded operator (+) to add an attendee
{
    Party result(*this);
    if (result.numAttendees < result.maxAttendees)
    {
        result.attendees[numAttendees] = rhs;
        result.numAttendees++;
    }
    else
    {
        cout << "The party is already full!" << endl;
    }
    return result;
}


bool Party::operator>(const Party& party1) const
{                       //Define the overloaded operator (>) to compare two parties
    if (numAttendees >= party1.numAttendees)
        return true;
    return false;
}


Party::~Party()  //Add destructor
{
    delete[] attendees;
}

//The following functions are provided
//Do not change

void Party::changeAttendeeAt(string name, int pos)
{
    if (pos >= 0 && pos < numAttendees)
        attendees[pos] = name;
    else
        cout << "Invalid index.";
}

void Party::print()
{
    if (numAttendees > 0)
    {
        cout << "Attendees list:\n";
        for (int i = 0; i < numAttendees; i++)
            cout << attendees[i] << endl;
    }
    else
        cout << "List is empty! Invite more people to your party.\n";
}

string Party::getAttendeeAt(int pos)
{
    if (pos >= 0 && pos < numAttendees)
        return attendees[pos];
    else
        return "Invalid index.";
}

int Party::getNumAttendees() const
{
    return numAttendees;
}

int Party::getMaxAttendees() const
{
    return maxAttendees;
}

string Party::getLocation() const
{
    return location;
}

void Party::setLocation(string new_loc)
{
    location = new_loc;
}

/*
This exercise defines a Party class to store the location and an attendee list of a party
along with the operations performed on the party location and attendee list (e.g., get/change party location and get/change attendee).
The Party class is partially completed. Please finish the following remaining tasks.
*/