DeGuire-Michael.hpp is a library which offers matrix declaration as well as
matrix functionality. The matrix is stored inside a template double pointer
which is used to dynamically allocate memory for the desired rows and columns.

The Matrix constructor takes in two arguments specifying the desired rows and
columns. The destructor then destroys the rows and columns when the matrix
object is no longer in scope or the matrix pointer is deleted.

The copy constructor ensures that the internal pointers of the matrix are
copied as well as the class variables.

The '()' operator is overloaded to provide an easier way for the individual
implementing this library to read and modify individual elements of the matrix

getNumRows return the number of rows. getNumColumns returns the number of
columns and getSize returns the number of elements that can be stored in the
matrix.

The fillMatrix method allows for the user to insert elements into the matrix
using a template array.

The printMatrix method prints the matrix to standard out.

The multiplyMatrices is a static method that takes in two matrices as the
arguments. The function then does the desired multiplication returning a new
matrix with product of the two matrices.

Transpose is a class method that takes in the calling Matrix object
and switches it's columns and rows. This is achieved by creating a new internal
matrix and making the old matrix pointer point to the new matrix after deleting
the old content.

Compile : g++ main.cpp -std=c++11
  with main.cpp being the source code utilizing the library by
  #including "DeGuire-Michael.hpp"
