#include "test-vector.h"

#include "assert.h"

#include "../vector.h"
#include "../complex.h"


void TestDefaultConstructorV(){

    Vector<int> v_1;
    assert(v_1.CheckInitialization() && "Error: Failed default construction of an int Vector");
    v_1.~Vector();

    Vector<double> v_2;
    assert(v_2.CheckInitialization() && "Error: Failed default construction of a double Vector");
    v_2.~Vector();

    Vector<Complex<double>> v_3;
    assert(v_3.CheckInitialization() && "Error: Failed default construction of a complex Vector");
    v_3.~Vector();


    Vector<int*> v_4;
    assert(v_4.CheckInitialization() && "Error: Failed default construction of an int* Vector");
    v_4.~Vector();

    Vector<double*> v_5;
    assert(v_5.CheckInitialization() && "Error: Failed default construction of a double* Vector");
    v_5.~Vector();

    Vector<Complex<double>*> v_6;
    assert(v_6.CheckInitialization() && "Error: Failed default construction of a complex* Vector");
    v_6.~Vector();


    Vector<int**> v_7;
    assert(v_7.CheckInitialization() && "Error: Failed default construction of an int** Vector");
    v_7.~Vector();

    Vector<double**> v_8;
    assert(v_8.CheckInitialization() && "Error: Failed default construction of a double** Vector");
    v_8.~Vector();

    Vector<Complex<double>**> v_9;
    assert(v_9.CheckInitialization() && "Error: Failed default construction of a complex** Vector");
    v_9.~Vector();

}


void TestMethodsV(){

    Vector<int> v_1(10);
    assert(v_1.GetLength() == 10 && "Error: Failed construction of a Vector");

    assert(v_1.GetFirst() == 0 && "Error: Failed to get the first element of a Vector");
    assert(v_1.GetLast() == 0 && "Error: Failed to get the last element of a Vector");

    for(int i=0; i < 10; i++)
        assert(v_1.Get(i) == 0 && "Error: Failed construction of a Vector");

    try{
        v_1.Get(11);
        assert(false && "Error: Acquired an out of range element with Get of a Vector");
    }
    catch(...){
        assert(true);
    }

    try{
        v_1.Get(-1);
        assert(false && "Error: Acquired an out of range element with Get of a Vector");
    }
    catch(...){
        assert(true);
    }


    Vector<int> v_2;

    try{
        v_2.GetFirst();
        assert(false && "Error: Acquired an out of range element with Get of a Vector");
    }
    catch(...){
        assert(true);
    }

    try{
        v_2.GetLast();
        assert(false && "Error: Acquired an out of range element with Get of a Vector");
    }
    catch(...){
        assert(true);
    }

    try{
        v_2.Get(1);
        assert(false && "Error: Acquired an out of range element with Get of a Vector");
    }
    catch(...){
        assert(true);
    }

    try{
        v_2.Get(-1);
        assert(false && "Error: Acquired an out of range element with Get of a Vector");
    }
    catch(...){
        assert(true);
    }

    v_1.~Vector();
    v_2.~Vector();

}


void TestOperationsV(){

    int array[5];
    for(int i=0; i < 5; i++)
        array[i] = 0;

    Vector<int> v_1(array,5);

    v_1.Set(3,1);
    assert(v_1.GetLength() == 5 && "Error: Failed to assign a value to the element of a Vector");
    assert(v_1.Get(3) == 1 && "Error: Failed to assign a value to the element of a Vector");

    try{
        v_1.Set(-1,1);
        assert(false && "Error: Set a value for an element with negative index");
    }
    catch(...){
        assert(true);
    }

    try{
        v_1.Set(21,1);
        assert(false && "Error: Set a value for an element with out of range index");
    }
    catch(...){
        assert(true);
    }


    v_1.Prepend(1);

    assert(v_1.GetLength() == 6 && "Error: Failed to add an element at the start of a Vector");
    assert(v_1.GetFirst() == 1 && "Error: Failed to get the first element of a Vector");

    v_1.Append(1);
    assert(v_1.GetLength() == 7 && "Error: Failed to add an element at the end of a Vector");
    assert(v_1.GetLast() == 1 && "Error: Failed to get the first element of a Vector");

    v_1.InsertAt(1,5);
    assert(v_1.GetLength() == 8 && "Error: Failed to add an element at the end of a Vector");
    assert(v_1.Get(5) == 1 && "Error: Failed to get the first element of a Vector");


    try{
        v_1.InsertAt(1,-1);
        assert(false && "Error: Inserted an element with out of range index into Vector");
    }
    catch(...){
        assert(true);
    }

    try{
        v_1.InsertAt(1,21);
        assert(false && "Error: Inserted an element with out of range index into Vector ");
    }
    catch(...){
        assert(true);
    }

    v_1.~Vector();


    int array_2[5];
    for(int i=0; i < 5; i++)
        array_2[i] = i;

    Vector<int> v_2(array_2, 5);
    Vector<int> v_3(array_2, 5);
    Vector<int> v_4(array_2, 5);

    v_3 + v_2;

    assert(v_3.GetLength() == 5 && "Error: Failed to add Vectors");

    for(int i=0; i < 5; i++)
        assert(v_3.Get(i) == (v_2.Get(i) + v_4.Get(i)) && "Error: Failed to add Vectors");


    v_2 * 5;
    assert(v_2.GetLength() == 5 && "Error: Failed to a Vector by a scalar");

    for(int i=0; i < 5; i++)
        assert(v_2.Get(i) == (v_4.Get(i) * 5) && "Error: Failed to a Vector by a scalar");


    int result = v_4.ScalarMultiplication(v_4);
    assert(result == 25 && "Error: Failed scalar multiplication of Vectors");

    v_1.~Vector();
    v_2.~Vector();
    v_3.~Vector();
    v_4.~Vector();

}


void TestConstructorsV(){

    Vector<int> v_1(10);
    assert(v_1.GetLength() == 10 && "Error: Failed to construct a Vector");

    int array[5];
    for(int i=0; i < 5; i++)
        array[i] = i;

    Vector<int> v_2(array, 5);

    Vector<int> v_3(v_2);
    assert(v_3.GetLength() == 5 && "Error: Failed to construct a Vector");

    for(int i=0; i < 5; i++)
        assert(v_3.Get(i) == i && "Error: Failed to construct a Vector");

    v_1.~Vector();
    v_2.~Vector();
    v_3.~Vector();

}


void TestVector(){
    TestDefaultConstructorV();
    TestMethodsV();
    TestOperationsV();
    TestConstructorsV();
}