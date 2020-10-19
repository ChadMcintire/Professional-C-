#include "SpreadsheetCell.h"
#include <iostream>
#include <memory>

using namespace std;

int main()
{
    // stack example of using default constructor
	SpreadsheetCell myCell, anotherCell;
	myCell.setValue(6);
	anotherCell.setString("3.2");

	cout << "cell 1: " << myCell.getValue() << endl;
	cout << "cell 2: " << anotherCell.getValue() << endl;

	cout << "cell 1: " << myCell.getString() << endl;
	cout << "cell 2: " << anotherCell.getString() << endl;

    //Heap example using default constructor
    SpreadsheetCell* myCellp = new SpreadsheetCell();
    myCellp->setValue(3.7);
    cout << "cell 3: " << myCellp->getValue() << " " << 
        " " << myCellp->getString() << endl;

    delete myCellp;
    myCellp = nullptr;

    //same example with smart pointers and default constructor
    auto myCellsp = make_unique<SpreadsheetCell>();
    myCellsp-> setValue(3.7);
    cout << "Cell 4: " << myCellsp->getValue() << 
            " " << myCellsp->getString() << endl;
    
    // non-default constructor on the stack
    SpreadsheetCell myCellndc(5), anotherCellndc(4);
    cout << "cell 5: " << myCellndc.getValue() << endl;
    cout << "cell 6: " << anotherCellndc.getValue() << endl;

    // non-default constructor smart pointer example

    auto smartCellp = make_unique<SpreadsheetCell>(4);

    cout << "cell 7: " << smartCellp->getValue() << endl;
    
    //free and set to nullptr
    smartCellp.reset();

    //another stack definition
    SpreadsheetCell aEighthCell("test");
    SpreadsheetCell aNinethCell(4.4);

    auto aTenthCellp = make_unique<SpreadsheetCell>("5.5");
    cout << "aEighthCell: " << aEighthCell.getValue() << endl;
    cout << "aNinethCell: " << aNinethCell.getValue() << endl;
    cout << "aTenthCellp: " << aTenthCellp->getValue() << endl;

    //assignment operator
    SpreadsheetCell aEleventhCell, aTwelthCell; 
    cout << "aNinethCell: " << aNinethCell.getValue() << endl;
    
    //example of chaing assignment operators
    aTwelthCell = aEleventhCell = aNinethCell;

    cout << "aNinethCell: " << aNinethCell.getValue() << endl;
    cout << "aEleventh: " << aEleventhCell.getValue() << endl;
    cout << "aTwelthCell : " << aTwelthCell.getValue() << endl;

	return 0;
}
