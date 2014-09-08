Compile Utils
=============

Set of C++ compile utilities I've found or created.

All utilities come in their own headers and have an associated cpp file with an
example of use. Currently the following are available:

- clean\_tuple: tuple with only the basic types (no const, no refs);
- function\_traits: easy access to function characteristics, similar to
  boost::function\_types;
- is\_tuple\_convertible: checks if each type of a tuple and be converted to the
  types of the other;
- remove\_ith\_type: removes the given type from a tuple;
- repeated\_tuple: builds a tuple with N copies of the same type;
- sequence: creates sequences to make easier to work with tuples.
