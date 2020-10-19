#include <string>
#include <string_view>
#include <iostream>
using namespace std;
class SpreadsheetCell
{
    public:
        //default constructor
        SpreadsheetCell();
        
        //non-default constuctor
        SpreadsheetCell(double initialValue);

        //non-default constuctor
        SpreadsheetCell(std::string_view initialValue);

        //copy constructor
        SpreadsheetCell(const SpreadsheetCell& src);

        //assignment operator
        SpreadsheetCell& operator=(const SpreadsheetCell& rhs);

        void setValue(double inValue);
        double getValue() const;
        void setString(string_view inString);
        std::string getString() const;
    private:
        std::string doubleToString(double inValue) const;
        double stringToDouble(std::string_view inString) const;
        double mValue;
};
