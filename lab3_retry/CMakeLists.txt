cmake_minimum_required(VERSION 3.17)
project(lab2)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab2 main.cpp dynamic-array.h Tests/test-dynamic-array.cpp Tests/test-dynamic-array.h linked-list.h
        Tests/test-linked-list.cpp Tests/test-linked-list.h lab2_old/mutable-array-sequence.h lab2_old/immutable-array-sequence.h
        lab2_old/immutable-sequence.h lab2_old/tests/test-mutable-array-sequence.cpp lab2_old/tests/test-mutable-array-sequence.h lab2_old/tests/test-immutable-array-sequence.cpp
        lab2_old/tests/test-immutable-array-sequence.h lab2_old/mutable-list-sequence.h lab2_old/tests/test-mutable-list-sequence.cpp lab2_old/tests/test-mutable-list-sequence.h
        lab2_old/immutable-list-sequence.h lab2_old/tests/test-immutable-list-sequence.cpp lab2_old/tests/test-immutable-list-sequence.h ui.cpp ui.h fail/test-icollection.cpp fail/test-icollection.h lab2_old/mutable-sequence.h vector.h Tests/test-vector.cpp Tests/test-vector.h complex.h square-matrix.h Tests/test-square-matrix.cpp Tests/test-square-matrix.h)