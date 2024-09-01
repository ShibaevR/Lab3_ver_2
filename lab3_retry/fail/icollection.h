#ifndef LAB2_MUTABLE_SEQUENCE_H
#define LAB2_MUTABLE_SEQUENCE_H

#include "string.h"

template <class T>
class ICollection{
private:
    struct NamedObject{
        char object_name[20];
        T* object;
    };
    size_t size;
    NamedObject* data;

public:
    ICollection() : size(0), data(nullptr){}

    ICollection(const T& element, char name[20]){
        data = new NamedObject;

        memcpy(data[0].object_name, name, 20);

        data[0].object = element;
        size = 1;
    }

    ~ICollection(){
        delete data;
        data = nullptr;
        size = 0;
    }


    T* Get(char* name) const{
        for(int i=0; i < size; i++){
            if(strcmp(data[i].object_name, name) == 0){
                return data[i].object;
            }
        }
    }


};



#endif //LAB2_MUTABLE_SEQUENCE_H
