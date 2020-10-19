#include "SpreadsheetCell.h"
#include <string>
#include <iostream>
using namespace std;

SpreadsheetCell::SpreadsheetCell()
{
    setValue(0);
}

SpreadsheetCell::SpreadsheetCell(double initialValue)
// use the constructor-initializer
    : mValue(initialValue)
{
    
}

SpreadsheetCell::SpreadsheetCell(string_view initialValue)
{
    setString(initialValue);
}

SpreadsheetCell::SpreadsheetCell(const SpreadsheetCell& src)
    : mValue(src.mValue)
{
}
void printCell(const SpreadsheetCell& cell)
{
    cout << cell.getString() << endl;
}

SpreadsheetCell & SpreadsheetCell::operator=(const SpreadsheetCell& rhs)
{
    mValue = rhs.mValue;
    return *this;
}


void SpreadsheetCell::setValue(double inValue)
{
    if (this == &rhs){
    return *this;
    }

    this->mValue = inValue;
    printCell(*this);
    //cout << *this << endl;
}

double SpreadsheetCell::getValue() const
{
    return mValue;
}

void SpreadsheetCell::setString(string_view inString)
{
    mValue = stringToDouble(inString);
}

string SpreadsheetCell::getString() const
{
    return doubleToString(mValue);
}

string SpreadsheetCell::doubleToString(double inValue) const
{
    return to_string(inValue);
}

double SpreadsheetCell::stringToDouble(string_view inString) const
{
    return strtod(inString.data(), nullptr);
}


