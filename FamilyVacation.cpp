#include "FamilyVacation.h"

//Mutators
void FamilyVacation::setNumDays(int dayCount)
{
    numDays = dayCount;
}

void FamilyVacation::setNumPeople(int peopleCount)
{
    numPeople = peopleCount;
}

void FamilyVacation::setNames(string* who, int people)
{

    if (people == 0) return;

    numPeople = people;
    names = new string[numPeople];

    for (int n = 0; n < numPeople; n++)
    {
        names[n] = who[n];
    }
}

//Accessors
int FamilyVacation::getNumDays()
{
    return numDays;
}

int FamilyVacation::getNumPeople()
{
    return numPeople;
}

string* FamilyVacation::getNames()
{
    return names;
}


// Implement the default constructor
FamilyVacation::FamilyVacation()
{
    numDays = 0;
    numPeople = 0;
    names = nullptr;
}


// Implement the overloaded constructors with three parameters, in the order of int, int, *string
FamilyVacation::FamilyVacation(int days, int people, string* names)
{
    numDays = days;
    numPeople = people;

    if (numPeople == 0)
    {
        this->names = nullptr;
    }
    else
    {
        this->names = new string[numPeople];
        for (int z = 0; z < numPeople; z++)
        {
            this->names[z] = names[z];
        }
    }
}


// Implement the destructor
FamilyVacation::~FamilyVacation()
{
    if (names != nullptr)
    {
        delete[] names;
        names = nullptr;
    }

}


// Implement the copy constructor that does the deep copy for the 'names' member
FamilyVacation::FamilyVacation(const FamilyVacation& copy)
{
    numDays = copy.numDays;
    numPeople = copy.numPeople;

    if (numPeople == 0)
    {
        names = nullptr;
    }
    else
    {
        names = new string[numPeople];
        for (int i = 0; i < numPeople; i++)
        {
            names[i] = copy.names[i];
        }
    }

}


// Implement the overloaded + operator
FamilyVacation FamilyVacation::operator+(int moreDays)
{
    FamilyVacation newVacation;

    newVacation.setNumDays(numDays + moreDays);
    newVacation.setNumPeople(numPeople);
    newVacation.names = new string[newVacation.numPeople];

    for (int q = 0; q < newVacation.numPeople; q++)
    {
        newVacation.names[q] = names[q];
    }

    return newVacation;
}


// Implement the second overloaded + operator
FamilyVacation FamilyVacation::operator+(FamilyVacation other)
{
    FamilyVacation newVacation;

    newVacation.setNumDays(numDays + other.numDays);
    newVacation.setNumPeople(numPeople + other.numPeople);
    newVacation.names = new string[newVacation.numPeople];

    for (int o = 0; o < numPeople; o++)
    {
        newVacation.names[o] = names[o];
    }

    for (int a = numPeople; a < numPeople + other.numPeople; a++)
    {
        newVacation.names[a] = other.names[a - numPeople];
    }

    return newVacation;
}


// Implement the overloaded == operator
bool FamilyVacation::operator==(FamilyVacation other)
{

    if (numDays == other.numDays)
    {
        if (numPeople == other.numPeople)
        {
            for (int p = 0; p < numPeople; p++)
            {
                if (names[p].compare(other.names[p]) != 0)
                {
                    return false;
                }
            }
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

// Implement the overloaded << operator
ostream& operator<<(ostream& o, FamilyVacation v)
{
    o << "Days: " << v.getNumDays() << ", People: " << v.getNumPeople() << " and they are: ";



    if (v.getNumPeople() == 0)
    {
        o << endl;
        return o;
    }
    else
    {
        for (int i = 0; i < v.getNumPeople() - 1; i++)
        {
            o << v.names[i] << ", ";
        }

        o << v.names[v.getNumPeople() - 1] << endl;
        return o;
    }
}


// Implement the overloaded = operator
FamilyVacation FamilyVacation::operator=(const FamilyVacation& other)
{
    numDays = other.numDays;
    numPeople = other.numPeople;

    if (this != &other)
    {
        delete[] names;
        if (numPeople == 0)
        {
            names = nullptr;
        }
        else
        {
            names = new string[numPeople];

            for (int i = 0; i < numPeople; i++)
            {
                names[i] = other.names[i];
            }
        }
    }
    return *this;
}