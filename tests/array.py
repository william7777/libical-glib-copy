#!/usr/bin/python3
#GI_TYPELIB_PATH=$PREFIX/lib/girepository-1.0/ ./test-array.py

import sys
from gi.repository import ICalGLib
from sys import getsizeof

array = ICalGLib.Array.new(100, 100);

element1 = "Hello";
element2 = "world";
element3 = "how";
element4 = "are";
element5 = "you";

#TEST APPEND
array.append (element1);
array.append (element2);
array.append (element3);
array.append (element4);
array.append (element5);

e1 = array.element_at(0);
assert (element1 == e1);
e2 = array.element_at(1);
assert (element2 == e2);
e3 = array.element_at(2);
assert (element3 == e3);
e4 = array.element_at(3);
assert (element4 == e4);
e5 = array.element_at(4);
assert (element5 == e5);

#TEST COPY
clone = array.copy();
e1 = clone.element_at(0);
assert (element1 == e1);
e2 = clone.element_at(1);
assert (element2 == e2);
e3 = clone.element_at(2);
assert (element3 == e3);
e4 = clone.element_at(3);
assert (element4 == e4);
e5 = clone.element_at(4);
assert (element5 == e5);

#TEST REMOVE
array.remove_element_at (2);
e3 = array.element_at(2);
assert (element4 == e3);


