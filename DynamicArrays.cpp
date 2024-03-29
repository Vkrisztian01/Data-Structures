/*
Dynamic arrays are very much alike with static arrays, the only difference is that their size
can be changed dynamicly with linear complexity.
*/

#include <iostream>

using namespace std;

//creating template
template<typename Type>


class DynamicArray
{

private:

    Type* data; // pointer to the array
    size_t Size; // size of the array

public:
    // Constructor
    DynamicArray(size_t initialsize) : Size(initialsize)
    {
        data = new Type[Size];
    }

    //function to get size
    size_t size()
    {
        return Size;
    }

    //Access function
    Type& operator[](size_t index)
    {
        //if index is wrong output error
        if(index>=Size)
        {
            cerr<<"Index is out of bounds"<<endl;
            exit(1);
        }
        return data[index];
    }

    //Resize function
    void resize(size_t newsize)
    {
        Type* newdata=new Type[newsize]; // allocate memory

        //transfer data to the updated arrray
        for(size_t i=0; i < (newsize<Size ? newsize : Size); i++)
        {
            newdata[i]=data[i];
        }

        delete[] data; // release old memory
        data=newdata; //setting the array to the updated version
        Size=newsize; // updating the size
    }
};


int main()
{
    // declaring an integer array
    DynamicArray<int> a(8);

    //Assigning values
    for(int i=0;i<8;i++) a[i]=i;

    // Accessing some elements:
    cout<<a[0]<<endl<<a[4]<<endl<<a[6]<<endl;



    //Resizing:
    a.resize(5);

    //Accessing element again:
    for(int i=0;i<5;i++) cout<<a[i]<<" ";

    //Accessing non valid index:
    cout<<a[10];
    return 0;
}
