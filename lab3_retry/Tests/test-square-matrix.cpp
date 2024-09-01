#include "test-square-matrix.h"

#include "assert.h"

#include "../square-matrix.h"
#include "../complex.h"


void TestDefaultConstructorSM(){

    SquareMatrix<int> sm_1;
    assert(sm_1.CheckInitialization() && "Error: Failed default construction of an int Square Matrix");
    sm_1.~SquareMatrix();

    SquareMatrix<double> sm_2;
    assert(sm_2.CheckInitialization() && "Error: Failed default construction of a double Square Matrix");
    sm_2.~SquareMatrix();

    SquareMatrix<Complex<double>> sm_3;
    assert(sm_3.CheckInitialization() && "Error: Failed default construction of a complex Square Matrix");
    sm_3.~SquareMatrix();


    SquareMatrix<int*> sm_4;
    assert(sm_4.CheckInitialization() && "Error: Failed default construction of an int* Square Matrix");
    sm_4.~SquareMatrix();

    SquareMatrix<double*> sm_5;
    assert(sm_5.CheckInitialization() && "Error: Failed default construction of a double* Square Matrix");
    sm_5.~SquareMatrix();

    SquareMatrix<Complex<double>*> sm_6;
    assert(sm_6.CheckInitialization() && "Error: Failed default construction of a complex* Square Matrix");
    sm_6.~SquareMatrix();


    SquareMatrix<int**> sm_7;
    assert(sm_7.CheckInitialization() && "Error: Failed default construction of an int** Square Matrix");
    sm_7.~SquareMatrix();

    SquareMatrix<double**> sm_8;
    assert(sm_8.CheckInitialization() && "Error: Failed default construction of a double** Square Matrix");
    sm_8.~SquareMatrix();

    SquareMatrix<Complex<double>**> sm_9;
    assert(sm_9.CheckInitialization() && "Error: Failed default construction of a complex** Square Matrix");
    sm_9.~SquareMatrix();

}


void TestMethodsSM(){

    SquareMatrix<int> sm_1(10);
    assert(sm_1.GetSize() == 100 && "Error: Failed construction of a Square Matrix");

    for(int i=0; i < 100; i++)
        sm_1.Set(i, i);
    for(int i=0; i < 100; i++)
        assert(sm_1.Get(i) == i && "Error: Failed to assign values to th elements of a Square Matrix");

    assert(sm_1.GetFirst() == 0 && "Error: Failed to get the first element of a Square Matrix");
    assert(sm_1.GetLast() == 99 && "Error: Failed to get the last element of a Square Matrix");

    try{
        sm_1.Get(111);
        assert(false && "Error: Acquired an out of range element with Get of a Square Matrix");
    }
    catch(...){
        assert(true);
    }

    try{
        sm_1.Get(-1);
        assert(false && "Error: Acquired an out of range element with Get of a Square Matrix");
    }
    catch(...){
        assert(true);
    }


    try{
        sm_1.Set(111,11);
        assert(false && "Error: Set an out of range element for a Square Matrix");
    }
    catch(...){
        assert(true);
    }

    try{
        sm_1.Set(-1,-1);
        assert(false && "Error: Set an out of range element for a Square Matrix");
    }
    catch(...){
        assert(true);
    }


    SquareMatrix<int> sm_2;

    try{
        sm_2.Set(0,0);
        assert(false && "Error: Set an out of range element for a Square Matrix");
    }
    catch(...){
        assert(true);
    }

    try{
        sm_2.Get(0);
        assert(false && "Error: Acquired an out of range element with Get of a Square Matrix");
    }
    catch(...){
        assert(true);
    }

    try{
        sm_2.GetFirst();
        assert(false && "Error: Acquired the first element of a Square Matrix with size equal to 0");
    }
    catch(...){
        assert(true);
    }

    try{
        sm_2.GetLast();
        assert(false && "Error: Acquired the last element of a Square Matrix with size equal to 0");
    }
    catch(...){
        assert(true);
    }

    sm_1.~SquareMatrix();
    sm_2.~SquareMatrix();
}


void TestOperationsSM(){

    int array[25];
    for(int i=0; i < 25; i++)
        array[i] = 0;

    SquareMatrix<int> sm_1(array,5);

    sm_1.Set(3,1);
    assert(sm_1.GetSize() == 25 && "Error: Failed to assign a value to the element of a Square Matrix");
    assert(sm_1.Get(3) == 1 && "Error: Failed to assign a value to the element of a Square Matrix");

    try{
        sm_1.Set(-1,1);
        assert(false && "Error: Set a value for an element with negative index");
    }
    catch(...){
        assert(true);
    }

    try{
        sm_1.Set(121,1);
        assert(false && "Error: Set a value for an element with out of range index");
    }
    catch(...){
        assert(true);
    }



    int array_2[25];
    for(int i=0; i < 25; i++)
        array_2[i] = i;

    SquareMatrix<int> sm_2(array_2, 5);
    SquareMatrix<int> sm_3(array_2, 5);
    SquareMatrix<int> sm_4(array_2, 5);

    sm_3 + sm_2;

    assert(sm_3.GetSize() == 25 && "Error: Failed to add Square Matrices");

    for(int i=0; i < 25; i++)
        assert(sm_3.Get(i) == (sm_2.Get(i) + sm_4.Get(i)) && "Error: Failed to add Square Matrices");

    try{
        SquareMatrix<int> sm_6;
        SquareMatrix<int> sm_7(10);
        sm_6 + sm_7;
        assert(false && "Error: Added Square Matrices with size equal to 0");
    }
    catch(...){
        assert(true);
    }


    sm_2 * 5;
    assert(sm_2.GetSize() == 25 && "Error: Failed to multiply a Square Matrix by a scalar");

    for(int i=0; i < 25; i++)
        assert(sm_2.Get(i) == (sm_4.Get(i) * 5) && "Error: Failed to multiply a Square Matrix by a scalar");

    try{
        SquareMatrix<int> sm_6;
        sm_6 *5;
        assert(false && "Error: Multiplied Square Matrix with size equal to 0");
    }
    catch(...){
        assert(true);
    }


    sm_1.~SquareMatrix();
    sm_2.~SquareMatrix();
    sm_3.~SquareMatrix();
    sm_4.~SquareMatrix();

}


void TestElementaryTransformations(){

    int array[25];
    for(int i=0; i < 25; i++)
        array[i] = i;

    SquareMatrix<int> sm_1(array, 5);

    int row_number_1 = 1;
    int row_number_2 = 2;

    sm_1.RowInterchange(row_number_1, row_number_2);

    for(int i=0; i < 5; i++)
        assert(sm_1.Get(i) == array[i + 5] && "Error: Failed Row Interchange");

    for(int i=0; i < 5; i++)
        assert(sm_1.Get(i + 5) == array[i] && "Error: Failed Row Interchange");

    sm_1.~SquareMatrix();


    SquareMatrix<int> sm_2(array, 5);

    sm_2.RowMultiplication(row_number_1, 5);

    for(int i=0; i < 5; i++)
        assert(sm_2.Get(i) == array[i]*5 && "Error: Failed Row Multiplication");

    sm_2.~SquareMatrix();


    SquareMatrix<int> sm_3(array, 5);

    sm_3.RowAddition(row_number_1, row_number_2, 5);

    for(int i=0; i < 5; i++)
        assert(sm_3.Get(i + 5) == array[i]*5 + array[i + 5] && "Error: Failed RowAddition");

    sm_3.~SquareMatrix();





    int column_number_1 = 1;
    int column_number_2 = 2;

    SquareMatrix<int> sm_4(array, 5);

    sm_4.ColumnInterchange(column_number_1, column_number_2);

    for(int i=0; i < 5; i++){
        for(int j=0; j < 5; j++){
            if(j+1 == column_number_1)
                assert(sm_4.Get(i * 5 + j) == array[i * 5 + j + 1] && "Error: Failed Column Interchange");
        }
    }

    for(int i=0; i < 5; i++){
        for(int j=0; j < 5; j++){
            if(j+1 == column_number_2)
                assert(sm_4.Get(i * 5 + j) == array[i * 5 + j - 1] && "Error: Failed Column Interchange");
        }
    }

    sm_4.~SquareMatrix();


    SquareMatrix<int> sm_5(array, 5);

    sm_5.ColumnMultiplication(column_number_1, 5);

    for(int i=0; i < 5; i++){
        for(int j=0; j < 5; j++){
            if(j+1 == column_number_1)
                assert(sm_5.Get(i * 5 + j) == array[i * 5 + j]*5 && "Error: Failed Column Multiplication");
        }
    }

    sm_5.~SquareMatrix();


    SquareMatrix<int> sm_6(array, 5);

    sm_6.ColumnAddition(column_number_1, column_number_2, 5);

    for(int i=0; i < 5; i++){
        for(int j=0; j < 5; j++){
            if(j+1 == column_number_2)
                assert(sm_6.Get(i * 5 + j) == (array[i * 5 + j - 1]*5 + array[i * 5 + j]) && "Error: Failed Column Addition");
        }
    }

    sm_6.~SquareMatrix();

}


void TestConstructors(){

    SquareMatrix<int> sm_1(10);
    assert(sm_1.GetSize() == 100 && "Error: Failed to construct a Square Matrix");

    int array[25];
    for(int i=0; i < 25; i++)
        array[i] = i;

    SquareMatrix<int> sm_2(array, 5);

    SquareMatrix<int> sm_3(sm_2);
    assert(sm_3.GetSize() == 25 && "Error: Failed to construct a Square Matrix");

    for(int i=0; i < 25; i++)
        assert(sm_3.Get(i) == i && "Error: Failed to construct a Square Matrix");


    sm_1.~SquareMatrix();
    sm_2.~SquareMatrix();
    sm_3.~SquareMatrix();

}



void TestSquareMatrix(){
    TestDefaultConstructorSM();
    TestMethodsSM();
    TestOperationsSM();
    TestElementaryTransformations();
    TestConstructors();
}
