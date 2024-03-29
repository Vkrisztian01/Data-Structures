/*

Static arrays are collections of ordered elements.
The size of the array refers to the number of elements it can hold.
A static array means an array, such whose size is fixed with declaration.
For all i = 0, 1, 2, ..., n-1 and array denoted as "a" : a[i] refers to the i-th element of a
All primary operations are performed in constant time.
Our array shall be an integer array for simplicity.

*/

#include <iostream>

using namespace std;

//we define the template parameters
template<typename Type,size_t Size>

class StaticArray
{
private:

    Type data[Size];

public:

    //Constructor
    StaticArray()
    {

    }

    //Size
    size_t size()
    {
        return Size;
    }


    // Access the elements
    Type& operator[](size_t index)
    {
        if(index>=Size)
        {
            cerr << "The index is larger than the size"<<endl;
            exit(1);
        }

        return data[index];

    }



};

int main()
{
    //Declaring an array for example
    StaticArray<int,8> a;

    //Input
    for(int i=0;i<8;i++) a[i]=i;

    //Output
    for(int i=0;i<8;i++) cout<<a[i]<<", ";
    return 0;
}
