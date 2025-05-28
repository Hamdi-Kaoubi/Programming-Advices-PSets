#include <iostream>
using namespace std;

class clsAddress
{

private:
    string _AddressLine1;
    string _AddressLine2;
    string _POBox;
    string _ZipCode;

public:
    //this is the constructor
    clsAddress(string AddressLine1, string AddressLine2, string POBox, string ZipCode)
    {
        _AddressLine1 = AddressLine1;
        _AddressLine2 = AddressLine2;
        _POBox = POBox;
        _ZipCode = ZipCode;
    }

    //copy constructor:
    clsAddress(clsAddress& old_object)
    {
        _AddressLine1 = old_object.AddressLine1();
        _AddressLine2 = old_object.AddressLine2();
        _POBox = old_object.POBox();
        _ZipCode = old_object.ZipCode();
    }

    void SetAddressLine1(string AddressLine1)
    {
        _AddressLine1 = AddressLine1;
    }
    string AddressLine1()
    {
        return _AddressLine1;
    }
    void SetAddressLine2(string AddressLine2)
    {
        _AddressLine2 = AddressLine2;
    }
    string AddressLine2()
    {
        return _AddressLine2;
    }
    void SetPOBox(string POBox)
    {
        _POBox = POBox;
    }
    string POBox()
    {
        return _POBox;
    }
    void SetZipCode(string ZipCode)
    {
        _ZipCode = ZipCode;
    }
    string ZipCode()
    {
        return _ZipCode;
    }
    void Print()
    {
        cout << "\nAddress Details:\n";
        cout << "------------------------";
        cout << "\nAddressLine1: " << _AddressLine1 << endl;
        cout << "AddressLine2: " << _AddressLine2 << endl;
        cout << "POBox : " << _POBox << endl;
        cout << "ZipCode : " << _ZipCode << endl;
    }

};

//Destructor:
class clsPerson
{
public:
    string FullName;

    //This constructor will be called when object is built:
    clsPerson()
    {
        FullName = "Hamdi Kaoubi";
        cout << "\nHi, I am constructor.";
    }

    //This is destructor will be called when object is destroyed:
    ~clsPerson()
    {
        cout << "\nHi, I am destructor.";
    }
};

void Fun1()
{
    clsPerson Person1;
}

//we will test the destructor in the run time using pointers:
void Fun2()
{
    clsPerson* Person2 = new clsPerson;
    //we should delete the object manually from the memory (using 'delete') so the destructor will execute:
    delete Person2;
}

int main()
{
    /*clsAddress Address1("Jordan", "koko", "2020", "100");
    Address1.Print();

    clsAddress Address2 = Address1;
    Address2.Print();*/
    
    Fun1();
    Fun2();

    system("pause>0");
}