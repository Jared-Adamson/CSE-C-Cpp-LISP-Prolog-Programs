//P13 Inheritance -  Jared Adamson
/*
   This program is a driver to test SalesInfo class, which inherits SalesPerson.
   It is used to create 2 objects, which test the constructors and accessors.
   The objects created are saved to P13.txt
*/
#include <fstream>    // file processing
#include <iostream>   // cout and cin
#include <iomanip>    // setw
#include <string>     // string class

using namespace std;


class SalesPerson
{
protected:
	//private member variables require accessors
     int salesPersonId;
     string firstName;
     string lastName; 

public: 
//default constructor - will call input functions
    SalesPerson();

//overloaded constructor - will assign parameter values to private variables
    SalesPerson(int id, string fn, string ln);

//destructor
    ~SalesPerson();

//accessors
    void setSalesPersonId(int id);
    void setFirstName(string fn);
    void setLastName(string ln);

    int getSalesPersonId( );
    string getFirstName( );
    string getLastName( ); 

    void inputSalesPersonId( );
    void inputFirstName( );
    void inputLastName( ) ;


};
class SalesInfo : public SalesPerson   //copy-and-paste your class definition over this outline.
{
private:
	 double rate;
     int    qty;

public:
//default constructor - call input functions and base constructor
    SalesInfo( );

//overload constructor - need to also take in values for base class
    SalesInfo(int id, string fn, string ln, double r, int q);

//destructor
    ~SalesInfo( );

//accessors
    void setRate(double r);
    void setQty(int q);
    

    double getRate( );
    int getQty( );
    

    void inputRate( );
    void inputQty( );
  
};      


//This function saves sales info to a file or displays to screen (cout)
void outputSalesInfo(ostream& target, SalesInfo& salesInfoObj);


void main()
{
//Open the file for output

    ofstream outFile;
    outFile.open("P13.txt");
    if (outFile.fail())
    {
        cout << "Error opening output file for sales information.\n"
             << "Exiting program \n\n";
        return;
    }

    cout << "\nP13     Juan Marquez   TR 1:00pm \n\n";


//1001 Joe Smith 5.00, 25 - use default constructors and input functions
    SalesInfo salesInfoObj;

//Save the validated sales info data as a record to the file.
    outputSalesInfo(outFile, salesInfoObj);
//display the record on the screen
    outputSalesInfo(cout, salesInfoObj);


//1002  Larry Jones  - use set methods to change values.
    salesInfoObj.setSalesPersonId(1002);
    salesInfoObj.setFirstName("Larry");
    salesInfoObj.setLastName("Jones");
    salesInfoObj.setRate(10.00);
    salesInfoObj.setQty(50);

//Save the sales info data as a record to the file.
    outputSalesInfo(outFile, salesInfoObj);
//display the record on the screen
    outputSalesInfo(cout, salesInfoObj);


//1003 Paul Sailor - use overloaded constructors 
    SalesInfo salesInfoObj2(1003, "Paul", "Sailor", 15.00, 150);

//Save the sales info data as a record to the file.
    outputSalesInfo(outFile, salesInfoObj2);
//display the record on the screen
    outputSalesInfo(cout, salesInfoObj2);


// Close the output file and exit program
    outFile.close();
    return;
}//end of main


//save the order information to a file or display on screen
void outputSalesInfo(ostream& target, SalesInfo& salesInfoObj)
{
//declare local variables
    int    salesPersonId;
    string lastName, firstName;
    double rate;
    int    qty;

//set the precision for rate
    target.setf(ios::fixed);
    target.setf(ios::showpoint);
    target.precision(2);

//Have the class return the private values to the local variables.
//Then store them in the file.
    salesPersonId = salesInfoObj.getSalesPersonId();
    firstName     = salesInfoObj.getFirstName();
    lastName      = salesInfoObj.getLastName();
    rate          = salesInfoObj.getRate();
    qty           = salesInfoObj.getQty();   

    if(target == cout)
        target << "\n\nSalesPerson's Information Saved! \n";

    target.setf(ios::left);
    target << setw(6)  << salesPersonId
           << setw(18) << firstName
           << setw(18) << lastName;
    target.unsetf(ios::left);

    target << setw(6) << rate;
    target << setw(4) << qty;
    target << endl;

    return;
}

//end of application code


//Functions for class SalesPerson

SalesPerson::SalesPerson()
	{
    inputSalesPersonId( );
     inputFirstName( );
     inputLastName( ) ;
}  
SalesPerson::SalesPerson(int id, string fn, string ln)
	{
     salesPersonId = id;
     firstName = fn;
     lastName  = ln; 
}    

SalesPerson::~SalesPerson()
	{
   
}
void SalesPerson::setSalesPersonId(int id)

	{
    salesPersonId = id;
} 

void SalesPerson::setFirstName(string fn)
	{
    firstName = fn;
} 

void SalesPerson::setLastName(string ln)
	{
    lastName  = ln; 
} 
int SalesPerson::getSalesPersonId()
	{
    return salesPersonId;
}

string SalesPerson::getFirstName()
	{
    return firstName;
} 


string SalesPerson::getLastName()
	{
    return lastName;
}
void SalesPerson::inputSalesPersonId()

	{
    cout << "Enter Sales Persons ID: ";
    cin  >> salesPersonId;
} 
void SalesPerson::inputFirstName()

	{
    cout << "Enter First Name:   ";
    cin  >> firstName;
} 
void SalesPerson::inputLastName()

	{
    cout << "Enter Last Name:  ";
    cin  >> lastName;
    cout << endl;
} 

//default constructor- the input functions should be called from here
SalesInfo::SalesInfo()
    : SalesPerson()        //call constructor in base class 
{
    inputRate();
    inputQty();
}

//overloaded constructor - arguments assigned to members
//use base initialize list to call constructor in base class
SalesInfo::SalesInfo(int id, string fn, string ln, 
                               double rt, int qt)
    : SalesPerson(id, fn, ln) 
{
    rate = rt;
    qty  = qt;
}

//destructor
SalesInfo::~SalesInfo()
{
    cout << "SalesInfo   Object going out of scope. Id = " 
         << salesPersonId << endl;
}


//Student needs to complete the next 4 functions.
//Accessors to set values in private variables
void SalesInfo::setRate(double rt)
{
	rate = rt;
}


void SalesInfo::setQty(int qt)
{
	qty  = qt;
}


//Accessors to return values in private variables
double SalesInfo::getRate()
{
	return rate;
}

int SalesInfo::getQty()
{
	return qty;
}


void SalesInfo::inputRate()
{//Normally set and input functions would include validation and would throw an exception if an error was found.
    do
    {
        cout << "Enter a bonus rate between $5.00 and $10: ";
        cin >> rate;

        if (rate < 5.0 || rate > 10.00)
            cout << "Error: The rate must be between $5.00 and $10.00. "
                 << "Try again...\n\n";

    } while (rate < 5.0 || rate > 10.00);
    return;
}


void SalesInfo::inputQty()
{
    do
    {
        cout << "Enter a quantity between 0 and 200:       ";

        cin >> qty;
            
        if (qty < 0 || qty > 200)
            cout << "Error: The quantity must be between 0 and 200. "
                 << "  Try again...\n\n";

    }while (qty < 0 || qty > 200);
    return;
}