#pragma once
#ifndef PARTY_H
#define PARTY_H

class Party
{
private:
    string location;
    string* attendees;
    int maxAttendees;
    int numAttendees;

public:
    Party();
    Party(string l, int num);                                             //Constructor
    Party(const Party& other);                                                  //Copy constructor
    Party& operator= (const Party& other);
    Party operator+ (string name) const;                                        //TODO: Add operator + to add a person to the party
    bool operator> (const Party& other) const;  //TODO: Add operator > to compare two parties

    void changeAttendeeAt(string name, int pos);
    void print();
    string getAttendeeAt(int pos);
    int getMaxAttendees() const;
    int getNumAttendees() const;
    string getLocation() const;
    void setLocation(string);
    ~Party();                                                           //TODO: Add destructor

};

#endif