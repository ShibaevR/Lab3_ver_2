#ifndef LAB2_VECTOR_H
#define LAB2_VECTOR_H

#include <iostream>
#include <cmath>

#include "linked-list.h"


template <class T>
class Vector{
private:
    LinkedList<T>* v_list;

public:
    Vector(){
        v_list = new LinkedList<T>();
    }

    explicit Vector(const int size){
        v_list = new LinkedList<T>(size);
    }

    Vector(T* items, const int size) {
        v_list = new LinkedList<T>(items, size);
    }

    Vector(const Vector<T>& vector) {
        v_list = new LinkedList<T>(*vector.v_list);
    }

    ~Vector(){
        delete v_list;
        v_list = nullptr;
    }


    T GetFirst() const{
        if(v_list->GetLength() == 0)
            throw std::out_of_range("Error: Can't get the first element of an Mutable Array Sequence with a size equal to 0");

        return v_list->Get(0);
    }

    T GetLast() const{
        if(v_list->GetLength() == 0)
            throw std::out_of_range("Error: Can't get the last element of a Mutable Array Sequence with a size equal to 0");

        return v_list->Get(v_list->GetLength() - 1);
    }

    T Get(const int index) const{
        if(index < 0 || index >= v_list->GetLength())
            throw std::out_of_range("Error: Index out of range");

        return v_list->Get(index);
    }


    int GetLength() const{
        return v_list->GetLength();
    }


    void Set(const int index, const T& item){
        if(index < 0 || index >= v_list->GetLength())
            throw std::out_of_range("Error: Index out of range");

        v_list->Set(index, item);
    }

    Vector<T>& Append(const T& item){
        v_list->Append(item);

        return *this;
    }

    Vector<T>& Prepend(const T& item){
        v_list->Prepend(item);

        return *this;
    }

    Vector<T>& InsertAt(const T& item, const int index){
        v_list->InsertAt(item, index);

        return *this;
    }


    bool CheckInitialization() const{
        return v_list->CheckInitialization();
    }


    Vector<T>& operator+(const Vector<T>& vector){
        if(v_list->GetLength() == 0)
            throw std::out_of_range("Error: Can't add vectors with a size equal to 0");

        if(vector.GetLength() == 0)
            throw std::out_of_range("Error: Can't add vectors with a size equal to 0");

        T result;

        for(int i=0; i < v_list->GetLength(); i++){
            result = v_list->Get(i) + vector.Get(i);
            v_list->Set(i, result);
        }

        return *this;

    }

    Vector<T>& operator*(const T& multiplier){
        if(v_list->GetLength() == 0)
            throw std::out_of_range("Error: Can't multiply a vector with a size equal to 0");

        for(int i=0; i < v_list->GetLength(); i++)
            v_list->Set(i, v_list->Get(i) * multiplier) ;

        return *this;
    }

    size_t ScalarMultiplication(const Vector<T>& vector) const{
        size_t result = v_list->GetLength() * vector.GetLength();

        return result;
    }

    double Norm() const{
        double result = v_list->Get(0) * v_list->Get(0);

        for(int i=1; i < v_list->GetLength(); i++)
            result += (v_list->Get(i) * v_list->Get(i));

        result = sqrt(result);

        return result;
    }
};


#endif //LAB2_VECTOR_H
