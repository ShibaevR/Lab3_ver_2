#include <iostream>

#include "Tests/test-dynamic-array.h"
#include "Tests/test-linked-list.h"
#include "lab2_old/tests/test-mutable-array-sequence.h"
#include "lab2_old/tests/test-immutable-array-sequence.h"
#include "lab2_old/tests/test-mutable-list-sequence.h"
#include "lab2_old/tests/test-immutable-list-sequence.h"
#include "Tests/test-vector.h"
#include "Tests/test-square-matrix.h"

#include "ui.h"

int main() {

    TestDynamicArray();
    TestLinkedList();
    TestMutableArraySequence();
    TestImmutableArraySequence();
    TestMutableListSequence();
    TestImmutableListSequence();
    TestVector();
    TestSquareMatrix();

    std::cout<<"\nAll tests completed successfully\n";

    UserInterface();

    return 0;
}
