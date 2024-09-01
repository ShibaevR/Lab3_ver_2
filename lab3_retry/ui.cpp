#include "ui.h"

#include <iostream>
#include <string.h>
#include <random>


#include "vector.h"
#include "square-matrix.h"
#include "complex.h"


void VectorMenu() {
    std::cout<<"\n\n\n------------------------------Menu------------------------------\n";
    std::cout<<"Enter <1> to get the first element\n";
    std::cout<<"Enter <2> to get the last element\n";
    std::cout<<"Enter <3> to to show a certain element\n";
    std::cout<<"Enter <4> to get length of the vector\n";
    std::cout<<"Enter <5> to assign a value to an element\n";
    std::cout<<"------------------------------------------------------------------\n";
    std::cout<<"Enter <6> to add one vector to another\n";
    std::cout<<"Enter <7> to multiply vector by a scalar\n";
    std::cout<<"Enter <8> for scalar multiplication\n";
    std::cout<<"Enter <9> to get the norm of the vector\n";
    std::cout<<"------------------------------------------------------------------\n";
    std::cout<<"Enter <10> to append an element\n";
    std::cout<<"Enter <11> to prepend an element\n";
    std::cout<<"Enter <12> to insert an element\n";
    std::cout<<"------------------------------------------------------------------\n";
    std::cout<<"Enter <13> to show your vector\n";

    std::cout<<"------------------------------------------------------------------\n\n";
    std::cout<<"Enter 'STOP' to go back\n";
    std::cout<<"----------Or----------\n";
    std::cout<<"Choose action: ";
}


void SquareMatrixMenu() {
    std::cout<<"\n\n\n------------------------------Menu------------------------------\n";
    std::cout<<"Enter <1> to get the first element\n";
    std::cout<<"Enter <2> to get the last element\n";
    std::cout<<"Enter <3> to to show a certain element\n";
    std::cout<<"Enter <4> to get size of the square matrix\n";
    std::cout<<"Enter <5> to assign a value to an element\n";
    std::cout<<"------------------------------------------------------------------\n";
    std::cout<<"Enter <6> to add one square matrix to another\n";
    std::cout<<"Enter <7> to multiply square matrix by a scalar\n";
    std::cout<<"Enter <8> to get the norm of the square matrix\n";
    std::cout<<"------------------------------------------------------------------\n";
    std::cout<<"Enter <9> to interchange rows\n";
    std::cout<<"Enter <10> to multiply a row by a scalar\n";
    std::cout<<"Enter <11> to add one row, multiplied by a scalar to another\n";
    std::cout<<"------------------------------------------------------------------\n";
    std::cout<<"Enter <12> to interchange column\n";
    std::cout<<"Enter <13> to multiply a column by a scalar\n";
    std::cout<<"Enter <14> to add one column, multiplied by a scalar, to another\n";
    std::cout<<"------------------------------------------------------------------\n";
    std::cout<<"Enter <15> to show your square matrix\n";

    std::cout<<"------------------------------------------------------------------\n\n";
    std::cout<<"Enter 'STOP' to finish\n";
    std::cout<<"----------Or----------\n";
    std::cout<<"Choose action: ";
}






void IntVectorOptions(Vector<int>& v){

    while(true){

        VectorMenu();

        char user_input_1[20];
        std::cin>>user_input_1;

        if(strcmp(user_input_1, "STOP") == 0)
            return;

        char *endptr_1;

        int action = strtol(user_input_1, &endptr_1, 10);

        switch(action){
            case 1:{
                std::cout<<"\nFirst element: "<<v.GetFirst();

                break;
            }

            case 2:{
                std::cout<<"\nFirst element: "<<v.GetLast();

                break;
            }

            case 3:{
                std::cout<<"\nEnter the number of the element: ";

                char user_input_index[20];
                std::cin>>user_input_index;
                char *endptr;
                int index = strtol(user_input_index, &endptr, 10);
                index--;

                if(index < 0 || index >= v.GetLength()){
                    std::cout<<"\nError: Index can't be less than 0 or greater than the length of the vector\n";
                    break;
                }

                std::cout<<"\nElement number "<<index + 1<<": "<<v.Get(index);

                break;
            }

            case 4:{
                std::cout<<"\nLength of the vector: "<<v.GetLength();

                break;
            }

            case 5:{
                std::cout<<"\nEnter the number of the element you want to change: ";

                char user_input_index[20];
                std::cin>>user_input_index;
                char *endptr;
                int index = strtol(user_input_index, &endptr, 10);
                index--;

                if(index < 0 || index >= v.GetLength()){
                    std::cout<<"\nError: Index can't be less than 0 or greater than the length of the vector\n";
                    break;
                }

                std::cout<<"\nEnter the value you want to assign: ";

                char user_input_int[20];
                std::cin>>user_input_int;

                int value = strtol(user_input_int, &endptr, 10);

                v.Set(index, value);

                std::cout<<"\nYour vector: ";
                for(int i=0; i < v.GetLength(); i++)
                    std::cout<<v.Get(i)<<" ";

                break;
            }

            case 6:{
                std::cout<<"\nEnter the vector you want to add\n ";

                int array[v.GetLength()];

                char *endptr;
                char user_input_int[20];

                for(int i=0; i < v.GetLength(); i++){
                    std::cout<<"\nEnter element "<<i + 1<<": ";

                    std::cin>>user_input_int;
                    array[i] = strtol(user_input_int, &endptr, 10);
                }

                Vector<int> v_1(array, v.GetLength());

                v + v_1;

                std::cout<<"\nYour vector: ";
                for(int i=0; i < v.GetLength(); i++)
                    std::cout<<v.Get(i)<<" ";

                v_1.~Vector();

                break;
            }

            case 7:{
                std::cout<<"\nEnter the scalar: ";

                char *endptr;
                char user_input_int[20];
                std::cin>>user_input_int;
                int scalar = strtol(user_input_int, &endptr, 10);

                v * scalar;

                std::cout<<"\nYour vector: ";
                for(int i=0; i < v.GetLength(); i++)
                    std::cout<<v.Get(i)<<" ";

                break;
            }

            case 8:{
                std::cout<<"\nResult: "<<v.ScalarMultiplication(v);

                break;
            }

            case 9:{
                std::cout<<"\nResult: "<<v.Norm();

                break;
            }

            case 10:{
                std::cout<<"\nEnter the value of the new element: ";

                char *endptr;
                char user_input_int[20];
                std::cin>>user_input_int;
                int value = strtol(user_input_int, &endptr, 10);

                v.Append(value);

                std::cout<<"\nYour vector: ";
                for(int i=0; i < v.GetLength(); i++)
                    std::cout<<v.Get(i)<<" ";

                break;
            }

            case 11:{
                std::cout<<"\nEnter the value of the new element: ";

                char *endptr;
                char user_input_int[20];
                std::cin>>user_input_int;
                int value = strtol(user_input_int, &endptr, 10);

                v.Prepend(value);

                std::cout<<"\nYour vector: ";
                for(int i=0; i < v.GetLength(); i++)
                    std::cout<<v.Get(i)<<" ";

                break;
            }

            case 12:{
                std::cout<<"\nEnter the number of the place where you want to insert the element: ";

                char *endptr;
                char user_input_index[20];
                std::cin>>user_input_index;
                int index = strtol(user_input_index, &endptr, 10);
                index--;

                if(index < 0 || index >= v.GetLength()){
                    std::cout<<"\nError: Index can't be less than 0 or greater than the length of the vector\n";
                    break;
                }

                std::cout<<"\nEnter the value of the new element: ";

                char user_input_int[20];
                std::cin>>user_input_int;
                int value = strtol(user_input_int, &endptr, 10);

                v.InsertAt(value, index);

                std::cout<<"\nYour vector: ";
                for(int i=0; i < v.GetLength(); i++)
                    std::cout<<v.Get(i)<<" ";

                break;
            }

            case 13:{
                std::cout<<"\nYour vector: ";
                for(int i=0; i < v.GetLength(); i++)
                    std::cout<<v.Get(i)<<" ";

                break;
            }


            default:{
                std::cout<<"\nError: This action doesn't exist. Please try again";
                break;
            }
        }
    }
}





void DoubleVectorOptions(Vector<double>& v){

    while(true){

        VectorMenu();

        char user_input_1[20];
        std::cin>>user_input_1;

        if(strcmp(user_input_1, "STOP") == 0)
            return;

        char *endptr_1;

        int action = strtol(user_input_1, &endptr_1, 10);

        switch(action){
            case 1:{
                std::cout<<"\nFirst element: "<<v.GetFirst();

                break;
            }

            case 2:{
                std::cout<<"\nFirst element: "<<v.GetLast();

                break;
            }

            case 3:{
                std::cout<<"\nEnter the number of the element: ";

                char user_input_index[20];
                std::cin>>user_input_index;
                char *endptr;
                int index = strtol(user_input_index, &endptr, 10);
                index--;

                if(index < 0 || index >= v.GetLength()){
                    std::cout<<"\nError: Index can't be less than 0 or greater than the length of the vector\n";
                    break;
                }

                std::cout<<"\nElement number "<<index + 1<<": "<<v.Get(index);

                break;
            }

            case 4:{
                std::cout<<"\nLength of the vector: "<<v.GetLength();

                break;
            }

            case 5:{
                std::cout<<"\nEnter the number of the element you want to change: ";

                char user_input_index[20];
                std::cin>>user_input_index;
                char *endptr;
                int index = strtol(user_input_index, &endptr, 10);
                index--;

                if(index < 0 || index >= v.GetLength()){
                    std::cout<<"\nError: Index can't be less than 0 or greater than the length of the vector\n";
                    break;
                }

                std::cout<<"\nEnter the value you want to assign: ";

                char user_input_double[20];
                std::cin>>user_input_double;

                double value = strtod(user_input_double, &endptr);

                v.Set(index, value);

                std::cout<<"\nYour vector: ";
                for(int i=0; i < v.GetLength(); i++)
                    std::cout<<v.Get(i)<<" ";

                break;
            }

            case 6:{
                std::cout<<"\nEnter the vector you want to add\n ";

                double array[v.GetLength()];

                char *endptr;
                char user_input_double[20];

                for(int i=0; i < v.GetLength(); i++){
                    std::cout<<"\nEnter element "<<i + 1<<": ";

                    std::cin>>user_input_double;
                    array[i] = strtod(user_input_double, &endptr);
                }

                Vector<double> v_1(array, v.GetLength());

                v + v_1;

                std::cout<<"\nYour vector: ";
                for(int i=0; i < v.GetLength(); i++)
                    std::cout<<v.Get(i)<<" ";

                v_1.~Vector();

                break;
            }

            case 7:{
                std::cout<<"\nEnter the scalar: ";

                char *endptr;
                char user_input_double[20];
                std::cin>>user_input_double;
                double scalar = strtod(user_input_double, &endptr);

                v * scalar;

                std::cout<<"\nYour vector: ";
                for(int i=0; i < v.GetLength(); i++)
                    std::cout<<v.Get(i)<<" ";

                break;
            }

            case 8:{
                std::cout<<"\nResult: "<<v.ScalarMultiplication(v);

                break;
            }

            case 9:{
                std::cout<<"\nResult: "<<v.Norm();

                break;
            }

            case 10:{
                std::cout<<"\nEnter the value of the new element: ";

                char *endptr;
                char user_input_double[20];
                std::cin>>user_input_double;
                double value = strtod(user_input_double, &endptr);

                v.Append(value);

                std::cout<<"Your vector: ";
                for(int i=0; i < v.GetLength(); i++)
                    std::cout<<v.Get(i)<<" ";

                break;
            }

            case 11:{
                std::cout<<"\nEnter the value of the new element: ";

                char *endptr;
                char user_input_double[20];
                std::cin>>user_input_double;
                double value = strtod(user_input_double, &endptr);

                v.Prepend(value);

                std::cout<<"\nYour vector: ";
                for(int i=0; i < v.GetLength(); i++)
                    std::cout<<v.Get(i)<<" ";

                break;
            }

            case 12:{
                std::cout<<"\nEnter the number of the place where you want to insert the element: ";

                char *endptr;
                char user_input_index[20];
                std::cin>>user_input_index;
                int index = strtol(user_input_index, &endptr, 10);
                index--;

                if(index < 0 || index >= v.GetLength()){
                    std::cout<<"\nError: Index can't be less than 0 or greater than the length of the vector\n";
                    break;
                }

                std::cout<<"\nEnter the value of the new element: ";

                char user_input_double[20];
                std::cin>>user_input_double;
                double value = strtod(user_input_double, &endptr);

                v.InsertAt(value, index);

                std::cout<<"\nYour vector: ";
                for(int i=0; i < v.GetLength(); i++)
                    std::cout<<v.Get(i)<<" ";

                break;
            }

            case 13:{
                std::cout<<"\nYour vector: ";
                for(int i=0; i < v.GetLength(); i++)
                    std::cout<<v.Get(i)<<" ";

                break;
            }


            default:{
                std::cout<<"\nError: This action doesn't exist. Please try again";
                break;
            }
        }
    }
}





void ComplexVectorOptions(Vector<Complex<double>>& v){

    while(true){

        VectorMenu();

        char user_input_1[20];
        std::cin>>user_input_1;

        if(strcmp(user_input_1, "STOP") == 0)
            return;

        char *endptr_1;

        int action = strtol(user_input_1, &endptr_1, 10);

        switch(action){
            case 1:{
                std::cout<<"\nFirst element: "<<"{"<<v.GetFirst().GetReal()<<", "<<v.GetFirst().GetImag()<<"}";

                break;
            }

            case 2:{
                std::cout<<"\nLast element: "<<"{"<<v.GetLast().GetReal()<<", "<<v.GetLast().GetImag()<<"}";

                break;
            }

            case 3:{
                std::cout<<"\nEnter the number of the element: ";

                char user_input_index[20];
                std::cin>>user_input_index;
                char *endptr;
                int index = strtol(user_input_index, &endptr, 10);
                index--;

                if(index < 0 || index >= v.GetLength()){
                    std::cout<<"\nError: Index can't be less than 0 or greater than the length of the vector\n";
                    break;
                }

                std::cout<<"\nElement number "<<index + 1<<": "<<"{"<<v.Get(index).GetReal()<<", "<<v.Get(index).GetImag()<<"}";;

                break;
            }

            case 4:{
                std::cout<<"\nLength of the vector: "<<v.GetLength();

                break;
            }

            case 5:{
                std::cout<<"\nEnter the number of the element you want to change: ";

                char user_input_index[20];
                std::cin>>user_input_index;
                char *endptr;
                int index = strtol(user_input_index, &endptr, 10);
                index--;

                if(index < 0 || index >= v.GetLength()){
                    std::cout<<"\nError: Index can't be less than 0 or greater than the length of the vector\n";
                    break;
                }

                double real;
                double imag;

                char user_input_double[20];

                std::cout<<"\nEnter real part of the element "<<index + 1<<": ";
                std::cin>>user_input_double;
                real = strtod(user_input_double, &endptr);

                std::cout<<"\nEnter imaginary part of the element "<<index + 1<<": ";
                std::cin>>user_input_double;
                imag = strtod(user_input_double, &endptr);

                Complex<double> c(real, imag);

                v.Set(index, c);

                std::cout<<"\nYour vector: ";
                for(int i=0; i < v.GetLength(); i++)
                    std::cout<<"{"<<v.Get(i).GetReal()<<", "<<v.Get(i).GetImag()<<"} ";

                break;
            }

            case 6:{
                std::cout<<"\nEnter the vector you want to add\n ";

                char *endptr;

                Complex<double> array[v.GetLength()];
                double real;
                double imag;

                char user_input_double[20];

                for(int i=0; i < v.GetLength(); i++){
                    std::cout<<"\nEnter real part of the element "<<i + 1<<": ";
                    std::cin>>user_input_double;
                    real = strtod(user_input_double, &endptr);

                    std::cout<<"\nEnter imaginary part of the element "<<i + 1<<": ";
                    std::cin>>user_input_double;
                    imag = strtod(user_input_double, &endptr);

                    Complex<double> c(real, imag);

                    array[i] = c;
                }

                Vector<Complex<double>> v_1(array, v.GetLength());

                v + v_1;

                std::cout<<"\nYour vector: ";
                for(int i=0; i < v.GetLength(); i++)
                    std::cout<<"{"<<v.Get(i).GetReal()<<", "<<v.Get(i).GetImag()<<"} ";

                v_1.~Vector();

                break;
            }

            case 7:{
                char *endptr;
                double real;
                double imag;

                char user_input_double[20];

                std::cout<<"\nEnter real part of the scalar: ";
                std::cin>>user_input_double;
                real = strtod(user_input_double, &endptr);

                std::cout<<"\nEnter imaginary part of the scalar: ";
                std::cin>>user_input_double;
                imag = strtod(user_input_double, &endptr);

                Complex<double> scalar(real, imag);

                v * scalar;

                std::cout<<"\nYour vector: ";
                for(int i=0; i < v.GetLength(); i++)
                    std::cout<<"{"<<v.Get(i).GetReal()<<", "<<v.Get(i).GetImag()<<"} ";

                break;
            }

            case 8:{
                std::cout<<"\nResult: "<<v.ScalarMultiplication(v);

                break;
            }

            case 9:{

                Complex<double>result(0,0);

                for(int i=0; i < v.GetLength(); i++){
                    result += (v.Get(i) * v.Get(i));
                }

                result.SquareRoot();

                std::cout<<"\nNorm: "<<"{"<<result.GetReal()<<", "<<result.GetImag()<<"} ";

                break;
            }

            case 10:{

                char *endptr;
                double real;
                double imag;

                char user_input_double[20];

                std::cout<<"\nEnter real part of the new element: ";
                std::cin>>user_input_double;
                real = strtod(user_input_double, &endptr);

                std::cout<<"\nEnter imaginary part of the new element: ";
                std::cin>>user_input_double;
                imag = strtod(user_input_double, &endptr);

                Complex<double> value(real, imag);


                v.Append(value);

                std::cout<<"\nYour vector: ";
                for(int i=0; i < v.GetLength(); i++)
                    std::cout<<"{"<<v.Get(i).GetReal()<<", "<<v.Get(i).GetImag()<<"} ";

                break;
            }

            case 11:{
                char *endptr;
                double real;
                double imag;

                char user_input_double[20];

                std::cout<<"\nEnter real part of the new element: ";
                std::cin>>user_input_double;
                real = strtod(user_input_double, &endptr);

                std::cout<<"\nEnter imaginary part of the new element: ";
                std::cin>>user_input_double;
                imag = strtod(user_input_double, &endptr);

                Complex<double> value(real, imag);


                v.Prepend(value);

                std::cout<<"\nYour vector: ";
                for(int i=0; i < v.GetLength(); i++)
                    std::cout<<"{"<<v.Get(i).GetReal()<<", "<<v.Get(i).GetImag()<<"} ";

                break;
            }

            case 12:{
                std::cout<<"\nEnter the number of the place where you want to insert the element: ";

                char *endptr;
                char user_input_index[20];
                std::cin>>user_input_index;
                int index = strtol(user_input_index, &endptr, 10);
                index--;

                if(index < 0 || index >= v.GetLength()){
                    std::cout<<"\nError: Index can't be less than 0 or greater than the length of the vector\n";
                    break;
                }

                double real;
                double imag;

                char user_input_double[20];

                std::cout<<"\nEnter real part of the new element: ";
                std::cin>>user_input_double;
                real = strtod(user_input_double, &endptr);

                std::cout<<"\nEnter imaginary part of the new element: ";
                std::cin>>user_input_double;
                imag = strtod(user_input_double, &endptr);

                Complex<double> value(real, imag);


                v.InsertAt(value, index);

                std::cout<<"\nYour vector: ";
                for(int i=0; i < v.GetLength(); i++)
                    std::cout<<"{"<<v.Get(i).GetReal()<<", "<<v.Get(i).GetImag()<<"} ";

                break;
            }

            case 13:{
                std::cout<<"\nYour vector: ";
                for(int i=0; i < v.GetLength(); i++)
                    std::cout<<"{"<<v.Get(i).GetReal()<<", "<<v.Get(i).GetImag()<<"} ";

                break;
            }


            default:{
                std::cout<<"\nError: This action doesn't exist. Please try again";
                break;
            }
        }
    }
}





void IntSquareMatrixOptions(SquareMatrix<int>& sm){

    while(true){

        SquareMatrixMenu();

        char user_input_1[20];
        std::cin>>user_input_1;

        if(strcmp(user_input_1, "STOP") == 0)
            return;

        char *endptr_1;

        int action = strtol(user_input_1, &endptr_1, 10);

        switch(action){
            case 1:{
                std::cout<<"\nFirst element: "<<sm.GetFirst();

                break;
            }

            case 2:{
                std::cout<<"\nLast element: "<<sm.GetLast();

                break;
            }

            case 3:{
                std::cout<<"\nEnter the row number of the element: ";

                int matrix_size = sqrt(sm.GetSize());

                char user_input_index[20];
                std::cin>>user_input_index;
                char *endptr;
                int index_1 = strtol(user_input_index, &endptr, 10);
                index_1--;

                if(index_1 < 0 || index_1 >= matrix_size){
                    std::cout<<"\nError: Row number can't be less than 0 or greater than the size of the square matrix\n";
                    break;
                }

                std::cout<<"\nEnter the column number of the element: ";

                std::cin>>user_input_index;
                int index_2 = strtol(user_input_index, &endptr, 10);
                index_2--;

                if(index_2 < 0 || index_2 >= matrix_size){
                    std::cout<<"\nError: Column number can't be less than 0 or greater than the size of the square matrix\n";
                    break;
                }

                std::cout<<"\nElement number in row "<<index_1 + 1<<", column "<<index_1 + 1<<": "<<sm.Get(index_1 * matrix_size + index_2);

                break;
            }

            case 4:{
                std::cout<<"\nSize of the square matrix: "<<sqrt(sm.GetSize());

                break;
            }

            case 5:{
                std::cout<<"\nEnter the row number of the element: ";

                int matrix_size = sqrt(sm.GetSize());

                char user_input_index[20];
                std::cin>>user_input_index;
                char *endptr;
                int index_1 = strtol(user_input_index, &endptr, 10);
                index_1--;

                if(index_1 < 0 || index_1 >= matrix_size){
                    std::cout<<"\nError: Row number can't be less than 0 or greater than the size of the square matrix\n";
                    break;
                }

                std::cout<<"\nEnter the column number of the element: ";

                std::cin>>user_input_index;
                int index_2 = strtol(user_input_index, &endptr, 10);
                index_2--;

                if(index_2 < 0 || index_2 >= matrix_size){
                    std::cout<<"\nError: Column number can't be less than 0 or greater than the size of the square matrix\n";
                    break;
                }

                std::cout<<"\nEnter the value you want to assign: ";

                char user_input_int[20];
                std::cin>>user_input_int;

                int value = strtol(user_input_int, &endptr, 10);

                sm.Set(index_1 * matrix_size + index_2, value);

                std::cout<<"\nYour square matrix: \n\n";
                for(int i=0; i < matrix_size; i++){
                    for(int j=0; j < matrix_size; j++){
                        std::cout<<sm.Get(i * matrix_size + j)<<"  ";
                    }
                    std::cout<<"\n";
                }

                break;
            }

            case 6:{
                std::cout<<"\nEnter the square matrix you want to add\n ";

                char *endptr;
                int array[sm.GetSize()];
                char user_input_int[20];

                int matrix_size = sqrt(sm.GetSize());

                for(int i=0; i < matrix_size; i++){
                    for(int j=0; j < matrix_size; j++){
                        std::cout<<"\nEnter element in row "<<i + 1<<", column "<<j+1<<": ";

                        std::cin>>user_input_int;
                        array[i * matrix_size + j] = strtol(user_input_int, &endptr, 10);
                    }
                }

                SquareMatrix<int> sm_1(array, matrix_size);

                sm + sm_1;

                std::cout<<"\nYour square matrix: \n\n";
                for(int i=0; i < matrix_size; i++){
                    for(int j=0; j < matrix_size; j++){
                        std::cout<<sm.Get(i * matrix_size + j)<<"  ";
                    }
                    std::cout<<"\n";
                }

                sm_1.~SquareMatrix();

                break;
            }

            case 7:{
                std::cout<<"\nEnter the scalar: ";

                int matrix_size = sqrt(sm.GetSize());

                char *endptr;
                char user_input_int[20];
                std::cin>>user_input_int;
                int scalar = strtol(user_input_int, &endptr, 10);

                sm * scalar;

                std::cout<<"\nYour square matrix: \n\n";
                for(int i=0; i < matrix_size; i++){
                    for(int j=0; j < matrix_size; j++){
                        std::cout<<sm.Get(i * matrix_size + j)<<"  ";
                    }
                    std::cout<<"\n";
                }

                break;
            }

            case 8:{
                std::cout<<"\nResult: "<<sm.Norm();

                break;
            }

            case 9:{
                std::cout<<"\nEnter row number 1: ";

                int matrix_size = sqrt(sm.GetSize());

                char *endptr;
                char user_input_int[20];
                std::cin>>user_input_int;
                int row_number_1 = strtol(user_input_int, &endptr, 10);

                if(row_number_1 <= 0 || row_number_1 > matrix_size){
                    std::cout<<"\nError: Row number can't be less than 0 or greater than the size of the square matrix\n";
                    break;
                }

                std::cout<<"\nEnter row number 2: ";

                std::cin>>user_input_int;
                int row_number_2 = strtol(user_input_int, &endptr, 10);

                if(row_number_2 <= 0 || row_number_2 > matrix_size){
                    std::cout<<"\nError: Row number can't be less than 0 or greater than the size of the square matrix\n";
                    break;
                }

                sm.RowInterchange(row_number_1, row_number_2);

                std::cout<<"\nYour square matrix: \n\n";
                for(int i=0; i < sqrt(sm.GetSize()); i++){
                    for(int j=0; j < sqrt(sm.GetSize()); j++){
                        std::cout<<sm.Get(i * matrix_size + j)<<"  ";
                    }
                    std::cout<<"\n";
                }

                break;
            }


            case 10:{
                std::cout<<"\nEnter the row number: ";

                int matrix_size = sqrt(sm.GetSize());

                char *endptr;
                char user_input_int[20];
                std::cin>>user_input_int;
                int row_number_1 = strtol(user_input_int, &endptr, 10);

                if(row_number_1 <= 0 || row_number_1 > matrix_size){
                    std::cout<<"\nError: Row number can't be less than 0 or greater than the size of the square matrix\n";
                    break;
                }

                std::cout<<"\nEnter the scalar: ";

                std::cin>>user_input_int;
                int scalar = strtol(user_input_int, &endptr, 10);

                sm.RowMultiplication(row_number_1, scalar);

                std::cout<<"\nYour square matrix: \n\n";
                for(int i=0; i < sqrt(sm.GetSize()); i++){
                    for(int j=0; j < sqrt(sm.GetSize()); j++){
                        std::cout<<sm.Get(i * matrix_size + j)<<"  ";
                    }
                    std::cout<<"\n";
                }

                break;
            }

            case 11:{
                std::cout<<"\nEnter row number 1: ";

                int matrix_size = sqrt(sm.GetSize());

                char *endptr;
                char user_input_int[20];
                std::cin>>user_input_int;
                int row_number_1 = strtol(user_input_int, &endptr, 10);

                if(row_number_1 <= 0 || row_number_1 > matrix_size){
                    std::cout<<"\nError: Row number can't be less than 0 or greater than the size of the square matrix\n";
                    break;
                }

                std::cout<<"\nEnter row number 2: ";

                std::cin>>user_input_int;
                int row_number_2 = strtol(user_input_int, &endptr, 10);

                if(row_number_2 <= 0 || row_number_2 > matrix_size){
                    std::cout<<"\nError: Row number can't be less than 0 or greater than the size of the square matrix\n";
                    break;
                }

                std::cout<<"\nEnter the scalar: ";

                std::cin>>user_input_int;
                int scalar = strtol(user_input_int, &endptr, 10);

                sm.RowAddition(row_number_1, row_number_2, scalar);

                std::cout<<"\nYour square matrix: \n\n";
                for(int i=0; i < sqrt(sm.GetSize()); i++){
                    for(int j=0; j < sqrt(sm.GetSize()); j++){
                        std::cout<<sm.Get(i * matrix_size + j)<<"  ";
                    }
                    std::cout<<"\n";
                }

                break;
            }

            case 12:{
                std::cout<<"\nEnter column number 1: ";

                int matrix_size = sqrt(sm.GetSize());

                char *endptr;
                char user_input_int[20];
                std::cin>>user_input_int;
                int column_number_1 = strtol(user_input_int, &endptr, 10);

                if(column_number_1 <= 0 || column_number_1 > matrix_size){
                    std::cout<<"\nError: Column number can't be less than 0 or greater than the size of the square matrix\n";
                    break;
                }

                std::cout<<"\nEnter column number 2: ";

                std::cin>>user_input_int;
                int column_number_2 = strtol(user_input_int, &endptr, 10);

                if(column_number_2 <= 0 || column_number_2 > matrix_size){
                    std::cout<<"\nError: Column number can't be less than 0 or greater than the size of the square matrix\n";
                    break;
                }

                sm.ColumnInterchange(column_number_1, column_number_2);

                std::cout<<"\nYour square matrix: \n\n";
                for(int i=0; i < sqrt(sm.GetSize()); i++){
                    for(int j=0; j < sqrt(sm.GetSize()); j++){
                        std::cout<<sm.Get(i * matrix_size + j)<<"  ";
                    }
                    std::cout<<"\n";
                }

                break;
            }


            case 13:{
                std::cout<<"\nEnter the column number: ";

                int matrix_size = sqrt(sm.GetSize());

                char *endptr;
                char user_input_int[20];
                std::cin>>user_input_int;
                int column_number_1 = strtol(user_input_int, &endptr, 10);

                if(column_number_1 <= 0 || column_number_1 > matrix_size){
                    std::cout<<"\nError: Column number can't be less than 0 or greater than the size of the square matrix\n";
                    break;
                }

                std::cout<<"\nEnter the scalar: ";

                std::cin>>user_input_int;
                int scalar = strtol(user_input_int, &endptr, 10);

                sm.ColumnMultiplication(column_number_1, scalar);

                std::cout<<"\nYour square matrix: \n\n";
                for(int i=0; i < sqrt(sm.GetSize()); i++){
                    for(int j=0; j < sqrt(sm.GetSize()); j++){
                        std::cout<<sm.Get(i * matrix_size + j)<<"  ";
                    }
                    std::cout<<"\n";
                }

                break;
            }

            case 14:{
                std::cout<<"\nEnter column number 1: ";

                int matrix_size = sqrt(sm.GetSize());

                char *endptr;
                char user_input_int[20];
                std::cin>>user_input_int;
                int column_number_1 = strtol(user_input_int, &endptr, 10);

                if(column_number_1 <= 0 || column_number_1 > matrix_size){
                    std::cout<<"\nError: Column number can't be less than 0 or greater than the size of the square matrix\n";
                    break;
                }

                std::cout<<"\nEnter column number 2: ";

                std::cin>>user_input_int;
                int column_number_2 = strtol(user_input_int, &endptr, 10);

                if(column_number_2 <= 0 || column_number_2 > matrix_size){
                    std::cout<<"\nError: Column number can't be less than 0 or greater than the size of the square matrix\n";
                    break;
                }

                std::cout<<"\nEnter the scalar: ";

                std::cin>>user_input_int;
                int scalar = strtol(user_input_int, &endptr, 10);

                sm.ColumnAddition(column_number_1, column_number_2, scalar);

                std::cout<<"\nYour square matrix: \n\n";
                for(int i=0; i < sqrt(sm.GetSize()); i++){
                    for(int j=0; j < sqrt(sm.GetSize()); j++){
                        std::cout<<sm.Get(i * matrix_size + j)<<"  ";
                    }
                    std::cout<<"\n";
                }

                break;
            }


            case 15:{
                int matrix_size = sqrt(sm.GetSize());

                std::cout<<"\nYour square matrix: \n\n";
                for(int i=0; i < sqrt(sm.GetSize()); i++){
                    for(int j=0; j < sqrt(sm.GetSize()); j++){
                        std::cout<<sm.Get(i * matrix_size + j)<<"  ";
                    }
                    std::cout<<"\n";
                }

                break;
            }


            default:{
                std::cout<<"\nError: This action doesn't exist. Please try again";
                break;
            }
        }
    }

}





void DoubleSquareMatrixOptions(SquareMatrix<double>& sm){

    while(true){

        SquareMatrixMenu();

        char user_input_1[20];
        std::cin>>user_input_1;

        if(strcmp(user_input_1, "STOP") == 0)
            return;

        char *endptr_1;

        int action = strtol(user_input_1, &endptr_1, 10);

        switch(action){
            case 1:{
                std::cout<<"\nFirst element: "<<sm.GetFirst();

                break;
            }

            case 2:{
                std::cout<<"\nLast element: "<<sm.GetLast();

                break;
            }

            case 3:{
                std::cout<<"\nEnter the row number of the element: ";

                int matrix_size = sqrt(sm.GetSize());

                char user_input_index[20];
                std::cin>>user_input_index;
                char *endptr;
                int index_1 = strtol(user_input_index, &endptr, 10);
                index_1--;

                if(index_1 < 0 || index_1 >= matrix_size){
                    std::cout<<"\nError: Row number can't be less than 0 or greater than the size of the square matrix\n";
                    break;
                }

                std::cout<<"\nEnter the column number of the element: ";

                std::cin>>user_input_index;
                int index_2 = strtol(user_input_index, &endptr, 10);
                index_2--;

                if(index_2 < 0 || index_2 >= matrix_size){
                    std::cout<<"\nError: Column number can't be less than 0 or greater than the size of the square matrix\n";
                    break;
                }

                std::cout<<"\nElement number in row "<<index_1 + 1<<", column "<<index_1 + 1<<": "<<sm.Get(index_1 * matrix_size + index_2);

                break;
            }

            case 4:{
                std::cout<<"\nSize of the square matrix: "<<sqrt(sm.GetSize());

                break;
            }

            case 5:{
                std::cout<<"\nEnter the row number of the element: ";

                int matrix_size = sqrt(sm.GetSize());

                char user_input_index[20];
                std::cin>>user_input_index;
                char *endptr;
                int index_1 = strtol(user_input_index, &endptr, 10);
                index_1--;

                if(index_1 < 0 || index_1 >= matrix_size){
                    std::cout<<"\nError: Row number can't be less than 0 or greater than the size of the square matrix\n";
                    break;
                }

                std::cout<<"\nEnter the column number of the element: ";

                std::cin>>user_input_index;
                int index_2 = strtol(user_input_index, &endptr, 10);
                index_2--;

                if(index_2 < 0 || index_2 >= matrix_size){
                    std::cout<<"\nError: Column number can't be less than 0 or greater than the size of the square matrix\n";
                    break;
                }

                std::cout<<"\nEnter the value you want to assign: ";

                char user_input_double[20];
                std::cin>>user_input_double;

                double value = strtod(user_input_double, &endptr);

                sm.Set(index_1 * matrix_size + index_2, value);

                std::cout<<"\nYour square matrix: \n\n";
                for(int i=0; i < matrix_size; i++){
                    for(int j=0; j < matrix_size; j++){
                        std::cout<<sm.Get(i * matrix_size + j)<<"  ";
                    }
                    std::cout<<"\n";
                }

                break;
            }

            case 6:{
                std::cout<<"\nEnter the square matrix you want to add\n ";

                char *endptr;
                double array[sm.GetSize()];
                char user_input_double[20];

                int matrix_size = sqrt(sm.GetSize());

                for(int i=0; i < matrix_size; i++){
                    for(int j=0; j < matrix_size; j++){
                        std::cout<<"\nEnter element in row "<<i + 1<<", column "<<j+1<<": ";

                        std::cin>>user_input_double;
                        array[i * matrix_size + j] = strtod(user_input_double, &endptr);
                    }
                }

                SquareMatrix<double> sm_1(array, matrix_size);

                sm + sm_1;

                std::cout<<"\nYour square matrix: \n\n";
                for(int i=0; i < matrix_size; i++){
                    for(int j=0; j < matrix_size; j++){
                        std::cout<<sm.Get(i * matrix_size + j)<<"  ";
                    }
                    std::cout<<"\n";
                }

                sm_1.~SquareMatrix();

                break;
            }

            case 7:{
                std::cout<<"\nEnter the scalar: ";

                int matrix_size = sqrt(sm.GetSize());

                char *endptr;
                char user_input_double[20];
                std::cin>>user_input_double;
                double scalar = strtod(user_input_double, &endptr);

                sm * scalar;

                std::cout<<"\nYour square matrix: \n\n";
                for(int i=0; i < matrix_size; i++){
                    for(int j=0; j < matrix_size; j++){
                        std::cout<<sm.Get(i * matrix_size + j)<<"  ";
                    }
                    std::cout<<"\n";
                }

                break;
            }

            case 8:{
                std::cout<<"\nResult: "<<sm.Norm();

                break;
            }

            case 9:{
                std::cout<<"\nEnter row number 1: ";

                int matrix_size = sqrt(sm.GetSize());

                char *endptr;
                char user_input_int[20];
                std::cin>>user_input_int;
                int row_number_1 = strtol(user_input_int, &endptr, 10);

                if(row_number_1 <= 0 || row_number_1 > matrix_size){
                    std::cout<<"\nError: Row number can't be less than 0 or greater than the size of the square matrix\n";
                    break;
                }

                std::cout<<"\nEnter row number 2: ";

                std::cin>>user_input_int;
                int row_number_2 = strtol(user_input_int, &endptr, 10);

                if(row_number_2 <= 0 || row_number_2 > matrix_size){
                    std::cout<<"\nError: Row number can't be less than 0 or greater than the size of the square matrix\n";
                    break;
                }

                sm.RowInterchange(row_number_1, row_number_2);

                std::cout<<"\nYour square matrix: \n\n";
                for(int i=0; i < sqrt(sm.GetSize()); i++){
                    for(int j=0; j < sqrt(sm.GetSize()); j++){
                        std::cout<<sm.Get(i * matrix_size + j)<<"  ";
                    }
                    std::cout<<"\n";
                }

                break;
            }


            case 10:{
                std::cout<<"\nEnter the row number: ";

                int matrix_size = sqrt(sm.GetSize());

                char *endptr;
                char user_input_int[20];
                std::cin>>user_input_int;
                int row_number_1 = strtol(user_input_int, &endptr, 10);

                if(row_number_1 <= 0 || row_number_1 > matrix_size){
                    std::cout<<"\nError: Row number can't be less than 0 or greater than the size of the square matrix\n";
                    break;
                }

                std::cout<<"\nEnter the scalar: ";

                char user_input_double[20];

                std::cin>>user_input_double;
                double scalar = strtod(user_input_double, &endptr);

                sm.RowMultiplication(row_number_1, scalar);

                std::cout<<"\nYour square matrix: \n\n";
                for(int i=0; i < sqrt(sm.GetSize()); i++){
                    for(int j=0; j < sqrt(sm.GetSize()); j++){
                        std::cout<<sm.Get(i * matrix_size + j)<<"  ";
                    }
                    std::cout<<"\n";
                }

                break;
            }

            case 11:{
                std::cout<<"\nEnter row number 1: ";

                int matrix_size = sqrt(sm.GetSize());

                char *endptr;
                char user_input_int[20];
                std::cin>>user_input_int;
                int row_number_1 = strtol(user_input_int, &endptr, 10);

                if(row_number_1 <= 0 || row_number_1 > matrix_size){
                    std::cout<<"\nError: Row number can't be less than 0 or greater than the size of the square matrix\n";
                    break;
                }

                std::cout<<"\nEnter row number 2: ";

                std::cin>>user_input_int;
                int row_number_2 = strtol(user_input_int, &endptr, 10);

                if(row_number_2 <= 0 || row_number_2 > matrix_size){
                    std::cout<<"\nError: Row number can't be less than 0 or greater than the size of the square matrix\n";
                    break;
                }

                std::cout<<"\nEnter the scalar: ";

                char user_input_double[20];

                std::cin>>user_input_double;
                double scalar = strtod(user_input_double, &endptr);

                sm.RowAddition(row_number_1, row_number_2, scalar);

                std::cout<<"\nYour square matrix: \n\n";
                for(int i=0; i < sqrt(sm.GetSize()); i++){
                    for(int j=0; j < sqrt(sm.GetSize()); j++){
                        std::cout<<sm.Get(i * matrix_size + j)<<"  ";
                    }
                    std::cout<<"\n";
                }

                break;
            }

            case 12:{
                std::cout<<"\nEnter column number 1: ";

                int matrix_size = sqrt(sm.GetSize());

                char *endptr;
                char user_input_int[20];
                std::cin>>user_input_int;
                int column_number_1 = strtol(user_input_int, &endptr, 10);

                if(column_number_1 <= 0 || column_number_1 > matrix_size){
                    std::cout<<"\nError: Column number can't be less than 0 or greater than the size of the square matrix\n";
                    break;
                }

                std::cout<<"\nEnter column number 2: ";

                char user_input_double[20];

                std::cin>>user_input_double;
                int column_number_2 = strtol(user_input_double, &endptr, 10);

                if(column_number_2 <= 0 || column_number_2 > matrix_size){
                    std::cout<<"\nError: Column number can't be less than 0 or greater than the size of the square matrix\n";
                    break;
                }

                sm.ColumnInterchange(column_number_1, column_number_2);

                std::cout<<"\nYour square matrix: \n\n";
                for(int i=0; i < sqrt(sm.GetSize()); i++){
                    for(int j=0; j < sqrt(sm.GetSize()); j++){
                        std::cout<<sm.Get(i * matrix_size + j)<<"  ";
                    }
                    std::cout<<"\n";
                }

                break;
            }


            case 13:{
                std::cout<<"\nEnter the column number: ";

                int matrix_size = sqrt(sm.GetSize());

                char *endptr;
                char user_input_int[20];
                std::cin>>user_input_int;
                int column_number_1 = strtol(user_input_int, &endptr, 10);

                if(column_number_1 <= 0 || column_number_1 > matrix_size){
                    std::cout<<"\nError: Column number can't be less than 0 or greater than the size of the square matrix\n";
                    break;
                }

                std::cout<<"\nEnter the scalar: ";

                char user_input_double[20];

                std::cin>>user_input_double;
                double scalar = strtod(user_input_double, &endptr);

                sm.ColumnMultiplication(column_number_1, scalar);

                std::cout<<"\nYour square matrix: \n\n";
                for(int i=0; i < sqrt(sm.GetSize()); i++){
                    for(int j=0; j < sqrt(sm.GetSize()); j++){
                        std::cout<<sm.Get(i * matrix_size + j)<<"  ";
                    }
                    std::cout<<"\n";
                }

                break;
            }

            case 14:{
                std::cout<<"\nEnter column number 1: ";

                int matrix_size = sqrt(sm.GetSize());

                char *endptr;
                char user_input_int[20];
                std::cin>>user_input_int;
                int column_number_1 = strtol(user_input_int, &endptr, 10);

                if(column_number_1 <= 0 || column_number_1 > matrix_size){
                    std::cout<<"\nError: Column number can't be less than 0 or greater than the size of the square matrix\n";
                    break;
                }

                std::cout<<"\nEnter column number 2: ";

                std::cin>>user_input_int;
                int column_number_2 = strtol(user_input_int, &endptr, 10);

                if(column_number_2 <= 0 || column_number_2 > matrix_size){
                    std::cout<<"\nError: Column number can't be less than 0 or greater than the size of the square matrix\n";
                    break;
                }

                std::cout<<"Enter the scalar: ";

                char user_input_double[20];

                std::cin>>user_input_double;
                double scalar = strtod(user_input_double, &endptr);

                sm.ColumnAddition(column_number_1, column_number_2, scalar);

                std::cout<<"\nYour square matrix: \n\n";
                for(int i=0; i < sqrt(sm.GetSize()); i++){
                    for(int j=0; j < sqrt(sm.GetSize()); j++){
                        std::cout<<sm.Get(i * matrix_size + j)<<"  ";
                    }
                    std::cout<<"\n";
                }

                break;
            }


            case 15:{
                int matrix_size = sqrt(sm.GetSize());

                std::cout<<"\nYour square matrix: \n\n";
                for(int i=0; i < sqrt(sm.GetSize()); i++){
                    for(int j=0; j < sqrt(sm.GetSize()); j++){
                        std::cout<<sm.Get(i * matrix_size + j)<<"  ";
                    }
                    std::cout<<"\n";
                }

                break;
            }


            default:{
                std::cout<<"\nError: This action doesn't exist. Please try again";
                break;
            }
        }
    }

}





void ComplexSquareMatrixOptions(SquareMatrix<Complex<double>>& sm){

    while(true){

        SquareMatrixMenu();

        char user_input_1[20];
        std::cin>>user_input_1;

        if(strcmp(user_input_1, "STOP") == 0)
            return;

        char *endptr_1;

        int action = strtol(user_input_1, &endptr_1, 10);


        switch(action){
            case 1:{
                std::cout<<"\nFirst element: "<<"{"<<sm.GetFirst().GetReal()<<", "<<sm.GetFirst().GetImag()<<"} ";

                break;
            }

            case 2:{
                std::cout<<"\nLast element: "<<"{"<<sm.GetLast().GetReal()<<", "<<sm.GetLast().GetImag()<<"} ";

                break;
            }

            case 3:{
                std::cout<<"\nEnter the row number of the element: ";

                int matrix_size = sqrt(sm.GetSize());

                char user_input_index[20];
                std::cin>>user_input_index;
                char *endptr;
                int index_1 = strtol(user_input_index, &endptr, 10);
                index_1--;

                if(index_1 < 0 || index_1 >= matrix_size){
                    std::cout<<"\nError: Row number can't be less than 0 or greater than the size of the square matrix\n";
                    break;
                }

                std::cout<<"\nEnter the column number of the element: ";

                std::cin>>user_input_index;
                int index_2 = strtol(user_input_index, &endptr, 10);
                index_2--;

                if(index_2 < 0 || index_2 >= matrix_size){
                    std::cout<<"\nError: Column number can't be less than 0 or greater than the size of the square matrix\n";
                    break;
                }

                std::cout<<"\nElement number in row "<<index_1 + 1<<", column "<<index_1 + 1<<"{"<<sm.Get(index_1 * matrix_size + index_2).GetReal()<<", "<<sm.Get(index_1 * matrix_size + index_2).GetImag()<<"} ";

                break;
            }

            case 4:{
                std::cout<<"\nSize of the square matrix: "<<sqrt(sm.GetSize());

                break;
            }

            case 5:{
                std::cout<<"\nEnter the row number of the element: ";

                int matrix_size = sqrt(sm.GetSize());

                char user_input_index[20];
                std::cin>>user_input_index;
                char *endptr;
                int index_1 = strtol(user_input_index, &endptr, 10);
                index_1--;

                if(index_1 < 0 || index_1 >= matrix_size){
                    std::cout<<"\nError: Row number can't be less than 0 or greater than the size of the square matrix\n";
                    break;
                }

                std::cout<<"\nEnter the column number of the element: ";

                std::cin>>user_input_index;
                int index_2 = strtol(user_input_index, &endptr, 10);
                index_2--;

                if(index_2 < 0 || index_2 >= matrix_size){
                    std::cout<<"\nError: Column number can't be less than 0 or greater than the size of the square matrix\n";
                    break;
                }

                double real;
                double imag;

                char user_input_double[20];

                std::cout<<"\nEnter real part of the value you want to assign: ";
                std::cin>>user_input_double;
                real = strtod(user_input_double, &endptr);

                std::cout<<"\nEnter imaginary part of the value you want to assign: ";
                std::cin>>user_input_double;
                imag = strtod(user_input_double, &endptr);

                Complex<double> value(real, imag);

                sm.Set(index_1 * matrix_size + index_2, value);

                std::cout<<"\nYour square matrix: \n\n";
                for(int i=0; i < matrix_size; i++){
                    for(int j=0; j < matrix_size; j++){
                        std::cout<<"{"<<sm.Get(i * matrix_size + j).GetReal()<<", "<<sm.Get(i * matrix_size + j).GetImag()<<"} ";
                    }
                    std::cout<<"\n";
                }

                break;
            }

            case 6:{
                std::cout<<"\nEnter the square matrix you want to add\n ";

                char *endptr;

                int matrix_size = sqrt(sm.GetSize());

                Complex<double> array[sm.GetSize()];
                double real;
                double imag;

                char user_input_double[20];

                for(int i=0; i < matrix_size; i++){
                    for(int j=0; j < matrix_size; j++){
                        std::cout<<"\nEnter real part of the element in row "<<i + 1<<", column "<<j+1<<": ";
                        std::cin>>user_input_double;
                        real = strtod(user_input_double, &endptr);

                        std::cout<<"\nEnter imaginary part of the element in row "<<i + 1<<", column "<<j+1<<": ";
                        std::cin>>user_input_double;
                        imag = strtod(user_input_double, &endptr);

                        Complex<double> c(real, imag);

                        array[i * matrix_size + j] = c;
                    }
                }

                SquareMatrix<Complex<double>> sm_1(array, matrix_size);

                sm + sm_1;

                std::cout<<"\nYour square matrix: \n\n";
                for(int i=0; i < matrix_size; i++){
                    for(int j=0; j < matrix_size; j++){
                        std::cout<<"{"<<sm.Get(i * matrix_size + j).GetReal()<<", "<<sm.Get(i * matrix_size + j).GetImag()<<"} ";
                    }
                    std::cout<<"\n";
                }

                sm_1.~SquareMatrix();

                break;
            }

            case 7:{
                std::cout<<"\nEnter the scalar: ";

                int matrix_size = sqrt(sm.GetSize());

                char *endptr;

                char user_input_double[20];

                double real;
                double imag;

                std::cout<<"\nEnter real part of the scalar: ";
                std::cin>>user_input_double;
                real = strtod(user_input_double, &endptr);

                std::cout<<"\nEnter imaginary part of the scalar: ";
                std::cin>>user_input_double;
                imag = strtod(user_input_double, &endptr);

                Complex<double> scalar(real, imag);

                sm * scalar;

                std::cout<<"\nYour square matrix: \n\n";
                for(int i=0; i < matrix_size; i++){
                    for(int j=0; j < matrix_size; j++){
                        std::cout<<"{"<<sm.Get(i * matrix_size + j).GetReal()<<", "<<sm.Get(i * matrix_size + j).GetImag()<<"} ";
                    }
                    std::cout<<"\n";
                }

                break;
            }

            case 8:{
                Complex<double>result(0,0);

                for(int i=0; i < sm.GetSize(); i++){
                    result += (sm.Get(i) * sm.Get(i));
                }

                result.SquareRoot();

                std::cout<<"\nNorm: "<<"{"<<result.GetReal()<<", "<<result.GetImag()<<"} ";

                break;
            }

            case 9:{
                std::cout<<"\nEnter row number 1: ";

                int matrix_size = sqrt(sm.GetSize());

                char *endptr;
                char user_input_int[20];
                std::cin>>user_input_int;
                int row_number_1 = strtol(user_input_int, &endptr, 10);

                if(row_number_1 <= 0 || row_number_1 > matrix_size){
                    std::cout<<"\nError: Row number can't be less than 0 or greater than the size of the square matrix\n";
                    break;
                }

                std::cout<<"\nEnter row number 2: ";

                std::cin>>user_input_int;
                int row_number_2 = strtol(user_input_int, &endptr, 10);

                if(row_number_2 <= 0 || row_number_2 > matrix_size){
                    std::cout<<"\nError: Row number can't be less than 0 or greater than the size of the square matrix\n";
                    break;
                }

                sm.RowInterchange(row_number_1, row_number_2);

                std::cout<<"\nYour square matrix: \n\n";
                for(int i=0; i < matrix_size; i++){
                    for(int j=0; j < matrix_size; j++){
                        std::cout<<"{"<<sm.Get(i * matrix_size + j).GetReal()<<", "<<sm.Get(i * matrix_size + j).GetImag()<<"} ";
                    }
                    std::cout<<"\n";
                }

                break;
            }


            case 10:{
                std::cout<<"\nEnter the row number: ";

                int matrix_size = sqrt(sm.GetSize());

                char *endptr;
                char user_input_int[20];
                std::cin>>user_input_int;
                int row_number_1 = strtol(user_input_int, &endptr, 10);

                if(row_number_1 <= 0 || row_number_1 > matrix_size){
                    std::cout<<"\nError: Row number can't be less than 0 or greater than the size of the square matrix\n";
                    break;
                }

                char user_input_double[20];

                double real;
                double imag;

                std::cout<<"\nEnter real part of the scalar: ";
                std::cin>>user_input_double;
                real = strtod(user_input_double, &endptr);

                std::cout<<"\nEnter imaginary part of the scalar: ";
                std::cin>>user_input_double;
                imag = strtod(user_input_double, &endptr);

                Complex<double> scalar(real, imag);

                sm.RowMultiplication(row_number_1, scalar);

                std::cout<<"\nYour square matrix: \n\n";
                for(int i=0; i < matrix_size; i++){
                    for(int j=0; j < matrix_size; j++){
                        std::cout<<"{"<<sm.Get(i * matrix_size + j).GetReal()<<", "<<sm.Get(i * matrix_size + j).GetImag()<<"} ";
                    }
                    std::cout<<"\n";
                }

                break;
            }

            case 11:{
                std::cout<<"\nEnter row number 1: ";

                int matrix_size = sqrt(sm.GetSize());

                char *endptr;
                char user_input_int[20];
                std::cin>>user_input_int;
                int row_number_1 = strtol(user_input_int, &endptr, 10);

                if(row_number_1 <= 0 || row_number_1 > matrix_size){
                    std::cout<<"\nError: Row number can't be less than 0 or greater than the size of the square matrix\n";
                    break;
                }

                std::cout<<"\nEnter row number 2: ";

                std::cin>>user_input_int;
                int row_number_2 = strtol(user_input_int, &endptr, 10);

                if(row_number_2 <= 0 || row_number_2 > matrix_size){
                    std::cout<<"\nError: Row number can't be less than 0 or greater than the size of the square matrix\n";
                    break;
                }

                char user_input_double[20];

                double real;
                double imag;

                std::cout<<"\nEnter real part of the scalar: ";
                std::cin>>user_input_double;
                real = strtod(user_input_double, &endptr);

                std::cout<<"\nEnter imaginary part of the scalar: ";
                std::cin>>user_input_double;
                imag = strtod(user_input_double, &endptr);

                Complex<double> scalar(real, imag);

                sm.RowAddition(row_number_1, row_number_2, scalar);

                std::cout<<"\nYour square matrix: \n\n";
                for(int i=0; i < matrix_size; i++){
                    for(int j=0; j < matrix_size; j++){
                        std::cout<<"{"<<sm.Get(i * matrix_size + j).GetReal()<<", "<<sm.Get(i * matrix_size + j).GetImag()<<"} ";
                    }
                    std::cout<<"\n";
                }

                break;
            }

            case 12:{
                std::cout<<"\nEnter column number 1: ";

                int matrix_size = sqrt(sm.GetSize());

                char *endptr;
                char user_input_int[20];
                std::cin>>user_input_int;
                int column_number_1 = strtol(user_input_int, &endptr, 10);

                if(column_number_1 <= 0 || column_number_1 > matrix_size){
                    std::cout<<"\nError: Column number can't be less than 0 or greater than the size of the square matrix\n";
                    break;
                }

                std::cout<<"\nEnter column number 2: ";

                std::cin>>user_input_int;
                int column_number_2 = strtol(user_input_int, &endptr, 10);

                if(column_number_2 <= 0 || column_number_2 > matrix_size){
                    std::cout<<"\nError: Column number can't be less than 0 or greater than the size of the square matrix\n";
                    break;
                }

                sm.ColumnInterchange(column_number_1, column_number_2);

                std::cout<<"\nYour square matrix: \n\n";
                for(int i=0; i < matrix_size; i++){
                    for(int j=0; j < matrix_size; j++){
                        std::cout<<"{"<<sm.Get(i * matrix_size + j).GetReal()<<", "<<sm.Get(i * matrix_size + j).GetImag()<<"} ";
                    }
                    std::cout<<"\n";
                }

                break;
            }


            case 13:{
                std::cout<<"\nEnter the column number: ";

                int matrix_size = sqrt(sm.GetSize());

                char *endptr;
                char user_input_int[20];
                std::cin>>user_input_int;
                int column_number_1 = strtol(user_input_int, &endptr, 10);

                if(column_number_1 <= 0 || column_number_1 > matrix_size){
                    std::cout<<"\nError: Column number can't be less than 0 or greater than the size of the square matrix\n";
                    break;
                }

                char user_input_double[20];

                double real;
                double imag;

                std::cout<<"\nEnter real part of the scalar: ";
                std::cin>>user_input_double;
                real = strtod(user_input_double, &endptr);

                std::cout<<"\nEnter imaginary part of the scalar: ";
                std::cin>>user_input_double;
                imag = strtod(user_input_double, &endptr);

                Complex<double> scalar(real, imag);

                sm.ColumnMultiplication(column_number_1, scalar);

                std::cout<<"\nYour square matrix: \n\n";
                for(int i=0; i < matrix_size; i++){
                    for(int j=0; j < matrix_size; j++){
                        std::cout<<"{"<<sm.Get(i * matrix_size + j).GetReal()<<", "<<sm.Get(i * matrix_size + j).GetImag()<<"} ";
                    }
                    std::cout<<"\n";
                }

                break;
            }

            case 14:{
                std::cout<<"\nEnter column number 1: ";

                int matrix_size = sqrt(sm.GetSize());

                char *endptr;
                char user_input_int[20];
                std::cin>>user_input_int;
                int column_number_1 = strtol(user_input_int, &endptr, 10);

                if(column_number_1 <= 0 || column_number_1 > matrix_size){
                    std::cout<<"\nError: Column number can't be less than 0 or greater than the size of the square matrix\n";
                    break;
                }

                std::cout<<"\nEnter column number 2: ";

                std::cin>>user_input_int;
                int column_number_2 = strtol(user_input_int, &endptr, 10);

                if(column_number_2 <= 0 || column_number_2 > matrix_size){
                    std::cout<<"\nError: Column number can't be less than 0 or greater than the size of the square matrix\n";
                    break;
                }

                char user_input_double[20];

                double real;
                double imag;

                std::cout<<"\nEnter real part of the scalar: ";
                std::cin>>user_input_double;
                real = strtod(user_input_double, &endptr);

                std::cout<<"\nEnter imaginary part of the scalar: ";
                std::cin>>user_input_double;
                imag = strtod(user_input_double, &endptr);

                Complex<double> scalar(real, imag);

                sm.ColumnAddition(column_number_1, column_number_2, scalar);

                std::cout<<"\nYour square matrix: \n\n";
                for(int i=0; i < matrix_size; i++){
                    for(int j=0; j < matrix_size; j++){
                        std::cout<<"{"<<sm.Get(i * matrix_size + j).GetReal()<<", "<<sm.Get(i * matrix_size + j).GetImag()<<"} ";
                    }
                    std::cout<<"\n";
                }

                break;
            }


            case 15:{
                int matrix_size = sqrt(sm.GetSize());

                std::cout<<"\nYour square matrix: \n\n";
                for(int i=0; i < matrix_size; i++){
                    for(int j=0; j < matrix_size; j++){
                        std::cout<<"{"<<sm.Get(i * matrix_size + j).GetReal()<<", "<<sm.Get(i * matrix_size + j).GetImag()<<"} ";
                    }
                    std::cout<<"\n";
                }

                break;
            }


            default:{
                std::cout<<"\nError: This action doesn't exist. Please try again";
                break;
            }
        }
    }

}





void TypeOptions(){
    std::cout << "\n\n\nWhat type of elements do you want?\n";
    std::cout << "\nEnter <1> for int";
    std::cout << "\nEnter <2> for double";
    std::cout << "\nEnter <3> for complex\n";
    std::cout << "\nEnter <4> to go back\n";
    std::cout << "\nChoose action: ";
}



void CreateVector(){

    while(true){

        TypeOptions();

        char user_input_1[20];
        std::cin>>user_input_1;

        char *endptr_1;

        int action = strtol(user_input_1, &endptr_1, 10);

        switch(action){
            case 1:{
                std::cout<<"\nEnter the length of the vector: ";

                char user_input_length[20];
                std::cin>>user_input_length;

                char *endptr;

                int length = strtol(user_input_length, &endptr, 10);

                if(length <= 0){
                    std::cout<<"\nError: Length can't less than or equal to 0\n";
                    break;
                }

                int array[length];

                char user_input_int[20];

                for(int i=0; i < length; i++){
                    std::cout<<"\nEnter element "<<i + 1<<": ";

                    std::cin>>user_input_int;
                    array[i] = strtol(user_input_int, &endptr, 10);
                }

                Vector<int> v_1(array, length);

                std::cout<<"\nYour vector: ";
                for(int i=0; i < length; i++)
                    std::cout<<v_1.Get(i)<<" ";

                IntVectorOptions(v_1);

                v_1.~Vector();

                break;
            }


            case 2:{
                std::cout<<"\nEnter the length of the vector: ";

                char user_input_length[20];
                std::cin>>user_input_length;

                char *endptr;

                int length = strtol(user_input_length, &endptr, 10);

                if(length <= 0){
                    std::cout<<"\nError: Length can't less than or equal to 0\n";
                    break;
                }

                double array[length];

                char user_input_double[20];

                for(int i=0; i < length; i++){
                    std::cout<<"\nEnter element "<<i + 1<<": ";

                    std::cin>>user_input_double;
                    array[i] = strtod(user_input_double, &endptr);
                }

                Vector<double> v_2(array, length);

                std::cout<<"\nYour vector: ";
                for(int i=0; i < length; i++)
                    std::cout<<v_2.Get(i)<<" ";

                DoubleVectorOptions(v_2);

                v_2.~Vector();

                break;
            }


            case 3:{
                std::cout<<"\nEnter the length of the vector: ";

                char user_input_length[20];
                std::cin>>user_input_length;

                char *endptr;

                int length = strtol(user_input_length, &endptr, 10);

                if(length <= 0){
                    std::cout<<"\nError: Length can't less than or equal to 0\n";
                    break;
                }

                Complex<double> array[length];
                double real;
                double imag;

                char user_input_double[20];

                for(int i=0; i < length; i++){
                    std::cout<<"\nEnter real part of the element "<<i + 1<<": ";
                    std::cin>>user_input_double;
                    real = strtod(user_input_double, &endptr);

                    std::cout<<"\nEnter imaginary part of the element "<<i + 1<<": ";
                    std::cin>>user_input_double;
                    imag = strtod(user_input_double, &endptr);

                    Complex<double> c(real, imag);

                    array[i] = c;
                }

                Vector<Complex<double>> v_3(array, length);

                std::cout<<"\nYour vector: ";
                for(int i=0; i < length; i++)
                    std::cout<<"{"<<v_3.Get(i).GetReal()<<", "<<v_3.Get(i).GetImag()<<"} ";

                ComplexVectorOptions(v_3);

                v_3.~Vector();

                break;
            }


            case 4:{
                return;
            }


            default:{
                std::cout<<"\nError: This action doesn't exist. Please try again";
                break;
            }
        }
    }

}



void AutoCreateVector(){

    srand((unsigned)time_t (NULL));

    while(true){

        TypeOptions();

        char user_input_1[20];
        std::cin>>user_input_1;

        char *endptr_1;

        int action = strtol(user_input_1, &endptr_1, 10);

        switch(action){
            case 1:{
                std::cout<<"\nEnter the length of the vector: ";

                char user_input_length[20];
                std::cin>>user_input_length;

                char *endptr;

                int length = strtol(user_input_length, &endptr, 10);

                if(length <= 0){
                    std::cout<<"\nError: Length can't less than or equal to 0\n";
                    break;
                }

                int array[length];

                for(int i=0; i < length; i++){
                    array[i] = rand()/(RAND_MAX/10);
                }

                Vector<int> v_1(array, length);

                std::cout<<"\nYour vector: ";
                for(int i=0; i < length; i++)
                    std::cout<<v_1.Get(i)<<" ";

                IntVectorOptions(v_1);

                v_1.~Vector();

                break;
            }


            case 2:{
                std::cout<<"\nEnter the length of the vector: ";

                char user_input_length[20];
                std::cin>>user_input_length;

                char *endptr;

                int length = strtol(user_input_length, &endptr, 10);

                if(length <= 0){
                    std::cout<<"\nError: Length can't less than or equal to 0\n";
                    break;
                }

                double array[length];

                for(int i=0; i < length; i++){
                    array[i] = (double)rand()/((double)RAND_MAX/10.0);
                }

                Vector<double> v_2(array, length);

                std::cout<<"\nYour vector: ";
                for(int i=0; i < length; i++)
                    std::cout<<v_2.Get(i)<<" ";

                DoubleVectorOptions(v_2);

                v_2.~Vector();

                break;
            }


            case 3:{
                std::cout<<"\nEnter the length of the vector: ";

                char user_input_length[20];
                std::cin>>user_input_length;

                char *endptr;

                int length = strtol(user_input_length, &endptr, 10);

                if(length <= 0){
                    std::cout<<"\nError: Length can't less than or equal to 0\n";
                    break;
                }

                Complex<double> array[length];
                double real;
                double imag;

                for(int i=0; i < length; i++){
                    real = (double)rand()/((double)RAND_MAX/10.0);

                    imag = (double)rand()/((double)RAND_MAX/10.0);

                    Complex<double> c(real, imag);

                    array[i] = c;
                }

                Vector<Complex<double>> v_3(array, length);

                std::cout<<"\nYour vector: ";
                for(int i=0; i < length; i++)
                    std::cout<<"{"<<v_3.Get(i).GetReal()<<", "<<v_3.Get(i).GetImag()<<"} ";

                ComplexVectorOptions(v_3);

                v_3.~Vector();

                break;
            }


            case 4:{
                return;
            }


            default:{
                std::cout<<"\nError: This action doesn't exist. Please try again";
                break;
            }
        }
    }

}



void CreateSquareMatrix(){

    while(true){

        TypeOptions();

        char user_input_1[20];
        std::cin>>user_input_1;

        char *endptr_1;

        int action = strtol(user_input_1, &endptr_1, 10);

        switch(action){
            case 1:{
                std::cout<<"\nEnter the size of the square matrix: ";

                char user_input_size[20];
                std::cin>>user_input_size;

                char *endptr;

                int size = strtol(user_input_size, &endptr, 10);

                if(size <= 0){
                    std::cout<<"\nError: Size can't less than or equal to 0\n";
                    break;
                }

                int array[size*size];

                char user_input_int[20];

                for(int i=0; i < size; i++){
                    for(int j=0; j < size; j++){
                        std::cout<<"\nEnter element in row "<<i + 1<<", column "<<j+1<<": ";

                        std::cin>>user_input_int;
                        array[i * size + j] = strtol(user_input_int, &endptr, 10);
                    }
                }

                SquareMatrix<int> sm_1(array, size);

                std::cout<<"\nYour square matrix: \n\n";
                for(int i=0; i < size; i++){
                    for(int j=0; j < size; j++){
                        std::cout<<sm_1.Get(i * size + j)<<"  ";
                    }
                    std::cout<<"\n";
                }

                IntSquareMatrixOptions(sm_1);

                sm_1.~SquareMatrix();

                break;
            }


            case 2:{
                std::cout<<"\nEnter the size of the square matrix: ";

                char user_input_size[20];
                std::cin>>user_input_size;

                char *endptr;

                int size = strtol(user_input_size, &endptr, 10);

                if(size <= 0){
                    std::cout<<"\nError: Length can't less than or equal to 0\n";
                    break;
                }

                double array[size*size];

                char user_input_double[20];

                for(int i=0; i < size; i++){
                    for(int j=0; j < size; j++){
                        std::cout<<"\nEnter element in row "<<i + 1<<", column "<<j+1<<": ";

                        std::cin>>user_input_double;
                        array[i * size + j] = strtod(user_input_double, &endptr);
                    }
                }

                SquareMatrix<double> sm_2(array, size);

                std::cout<<"\nYour square matrix: \n\n";
                for(int i=0; i < size; i++){
                    for(int j=0; j < size; j++){
                        std::cout<<sm_2.Get(i * size + j)<<"  ";
                    }
                    std::cout<<"\n";
                }

                DoubleSquareMatrixOptions(sm_2);

                sm_2.~SquareMatrix();

                break;
            }


            case 3:{
                std::cout<<"\nEnter the size of the square matrix: ";

                char user_input_size[20];
                std::cin>>user_input_size;

                char *endptr;

                int size = strtol(user_input_size, &endptr, 10);

                if(size <= 0){
                    std::cout<<"\nError: Length can't less than or equal to 0\n";
                    break;
                }

                Complex<double> array[size*size];
                double real;
                double imag;

                char user_input_double[20];

                for(int i=0; i < size; i++){
                    for(int j=0; j < size; j++){
                        std::cout<<"\nEnter real part of the element in row "<<i + 1<<", column "<<j+1<<": ";
                        std::cin>>user_input_double;
                        real = strtod(user_input_double, &endptr);

                        std::cout<<"\nEnter imaginary part of the element in row "<<i + 1<<", column "<<j+1<<": ";
                        std::cin>>user_input_double;
                        imag = strtod(user_input_double, &endptr);

                        Complex<double> c(real, imag);

                        array[i * size + j] = c;
                    }
                }

                SquareMatrix<Complex<double>> sm_3(array, size);


                std::cout<<"\nYour square matrix: \n\n";
                for(int i=0; i < size; i++){
                    for(int j=0; j < size; j++){
                        std::cout<<"{"<<sm_3.Get(i).GetReal()<<", "<<sm_3.Get(i).GetImag()<<"}  ";
                    }
                    std::cout<<"\n";
                }

                ComplexSquareMatrixOptions(sm_3);

                sm_3.~SquareMatrix();

                break;
            }


            case 4:{
                return;
            }


            default:{
                std::cout<<"\nError: This action doesn't exist. Please try again";
                break;
            }
        }
    }

}



void AutoCreateSquareMatrix(){

    srand((unsigned)time_t (NULL));

    while(true){

        TypeOptions();

        char user_input_1[20];
        std::cin>>user_input_1;

        char *endptr_1;

        int action = strtol(user_input_1, &endptr_1, 10);

        switch(action){
            case 1:{
                std::cout<<"\nEnter the size of the square matrix: ";

                char user_input_size[20];
                std::cin>>user_input_size;

                char *endptr;

                int size = strtol(user_input_size, &endptr, 10);

                if(size <= 0){
                    std::cout<<"\nError: Size can't less than or equal to 0\n";
                    break;
                }

                int array[size*size];

                for(int i=0; i < size; i++){
                    for(int j=0; j < size; j++){
                        array[i * size + j] = rand()/(RAND_MAX/10);
                    }
                }

                SquareMatrix<int> sm_1(array, size);

                std::cout<<"\nYour square matrix: \n\n";
                for(int i=0; i < size; i++){
                    for(int j=0; j < size; j++){
                        std::cout<<sm_1.Get(i * size + j)<<"  ";
                    }
                    std::cout<<"\n";
                }

                IntSquareMatrixOptions(sm_1);

                sm_1.~SquareMatrix();

                break;
            }


            case 2:{
                std::cout<<"\nEnter the size of the square matrix: ";

                char user_input_size[20];
                std::cin>>user_input_size;

                char *endptr;

                int size = strtol(user_input_size, &endptr, 10);

                if(size <= 0){
                    std::cout<<"\nError: Length can't less than or equal to 0\n";
                    break;
                }

                double array[size*size];

                for(int i=0; i < size; i++){
                    for(int j=0; j < size; j++){
                        array[i * size + j] = (double)rand()/((double)RAND_MAX/10.0);
                    }
                }

                SquareMatrix<double> sm_2(array, size);

                std::cout<<"\nYour square matrix: \n\n";
                for(int i=0; i < size; i++){
                    for(int j=0; j < size; j++){
                        std::cout<<sm_2.Get(i * size + j)<<"  ";
                    }
                    std::cout<<"\n";
                }

                DoubleSquareMatrixOptions(sm_2);

                sm_2.~SquareMatrix();

                break;
            }


            case 3:{
                std::cout<<"\nEnter the size of the square matrix: ";

                char user_input_size[20];
                std::cin>>user_input_size;

                char *endptr;

                int size = strtol(user_input_size, &endptr, 10);

                if(size <= 0){
                    std::cout<<"\nError: Length can't less than or equal to 0\n";
                    break;
                }

                Complex<double> array[size*size];
                double real;
                double imag;

                for(int i=0; i < size; i++){
                    for(int j=0; j < size; j++){
                        real = (double)rand()/((double)RAND_MAX/10.0);

                        imag = (double)rand()/((double)RAND_MAX/10.0);

                        Complex<double> c(real, imag);

                        array[i * size + j] = c;
                    }
                }

                SquareMatrix<Complex<double>> sm_3(array, size);


                std::cout<<"\nYour square matrix: \n\n";
                for(int i=0; i < size; i++){
                    for(int j=0; j < size; j++){
                        std::cout<<"{"<<sm_3.Get(i).GetReal()<<", "<<sm_3.Get(i).GetImag()<<"}  ";
                    }
                    std::cout<<"\n";
                }

                ComplexSquareMatrixOptions(sm_3);

                sm_3.~SquareMatrix();

                break;
            }


            case 4:{
                return;
            }


            default:{
                std::cout<<"\nError: This action doesn't exist. Please try again";
                break;
            }
        }
    }

}









void MainMenu(){
    std::cout<<"\n\n--------------------------Menu--------------------------\n";
    std::cout<<"Enter <1> to create a vector\n";
    std::cout<<"Enter <2> to create a square matrix\n";
    std::cout<<"Enter <3> to finish\n";
    std::cout<<"Choose action: ";
}


void UserInterface(){

    while(true){

        MainMenu();

        char user_input_1[20];
        std::cin>>user_input_1;
        char *endptr;
        int action = strtol(user_input_1, &endptr, 10);


        switch(action){
            case 1:{
                std::cout<<"\n\nEnter <1> to create a vector automatically\n";
                std::cout<<"Enter <2> to create a vector manually\n";
                std::cout<<"Enter <3> to go back\n";
                std::cout<<"Choose action: ";

                char user_input_2[20];
                std::cin>>user_input_2;
                int action_2 = strtol(user_input_2, &endptr, 10);

                switch(action_2){
                    case 1:{
                        AutoCreateVector();
                        break;
                    }
                    case 2:{
                        CreateVector();
                        break;
                    }
                    case 3:{
                        break;
                    }
                    default:{
                        std::cout<<"\nError: This action doesn't exist. Please try again";
                        break;
                    }
                }

                break;
            }
            case 2:{
                std::cout<<"\n\nEnter <1> to create a square matrix automatically\n";
                std::cout<<"Enter <2> to create a square matrix manually\n";
                std::cout<<"Enter <3> to go back\n";
                std::cout<<"Choose action: ";

                char user_input_2[20];
                std::cin>>user_input_2;
                int action_2 = strtol(user_input_2, &endptr, 10);

                switch(action_2){
                    case 1:{
                        AutoCreateSquareMatrix();
                        break;
                    }
                    case 2:{
                        CreateSquareMatrix();
                        break;
                    }
                    case 3:{
                        break;
                    }
                    default:{
                        std::cout<<"\nError: This action doesn't exist. Please try again";
                        break;
                    }
                }

                break;
            }
            case 3:{
                exit(0);
            }
            default:{
                std::cout<<"\nError: This action doesn't exist. Please try again";
                break;
            }
        }
    }
}