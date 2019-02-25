/**
Author : Michael DeGuire
Date Completed : 02/19/19
Purpose : Library file that provides a matrix class
with matrix multiplication, transpose, inserting, and
printing functionality. Utilizes double pointer to create
internal matrix.
*/
#ifndef DEGUIRE_MICHAEL_HPP
#define DEGUIRE_MICHAEL_HPP

#include <iostream>
using namespace std;

template<typename Data>
class Matrix{
  /**
  Matrix class that uses a double pointer to hold
  the internal data.
  */
private:

  //Matrix container
  Data** internalMatrix ;
  //Total rows for matrix
  int numRows;
  //Total column for matrix
  int numColumns;

public:

  /**
  Constructor - Reads in the number of rows and columns
  */
  Matrix<Data>(int numRows, int numColumns){

  // Initialize rows and columns
  this->numRows = numRows;
  this->numColumns = numColumns;

  // Creates rows for matrix
  internalMatrix = new Data*[numRows];

  //Creates columns for matrix
  for(int row=0; row < numRows; ++row)
    *(internalMatrix+row) = new Data[numColumns];
  }

   /**
   Desconstructor - loops to delete each
   "row" (data *). Afterwards, internal data **
   is deleted
   */
  ~Matrix(){

    //Deletes each row
    for(int row = 0; row < numRows;++row)
      delete[] internalMatrix[row];

    //Deletes matrix container
    delete internalMatrix;
  }

  /**
  Copy constructor used to apply deep copy of raw pointers
  */
  Matrix<Data>(const Matrix& matrix){

    //Copies internal contents on matrix
    numRows = matrix.numRows;
    numColumns = matrix.numColumns;
    //Creates the rows and columns
    internalMatrix = new int *[numRows];

    for (int row = 0; row < numRows; row++)
      *(internalMatrix+row) = new int [numColumns] ;
    //Copies the rows and columns
    for(int currRow = 0; currRow < numRows; ++currRow)
        for(int currColumn = 0; currColumn < numColumns; ++currColumn)
          *((*(internalMatrix+currRow))+currColumn) = *((*(matrix.internalMatrix+currRow))+currColumn);
   }

   /**
   Overloads () operator to make access and modifications easier
   */
   Data& operator()(int row, int column) {
    return *((*(internalMatrix+row))+column);
  }

  int getNumRows(){ return numRows;}

  int getNumColumns(){ return numColumns;}

  int getSize(){ return numRows * numColumns;}

  /**
  Gives the user the ability to use array to fill
  the matrix
  */
  void fillMatrix(Data data []){
    for(int currRow = 0; currRow < numRows; ++currRow)
      for(int currColumn = 0; currColumn < numColumns; ++currColumn)
        *((*(internalMatrix+currRow))+currColumn) = data[(currRow*numColumns)+currColumn];
  }

  /**
  Prints the contents of the matrix
  */
  void printMatrix(){
    for(int currRow = 0; currRow < numRows; ++currRow){
      for(int currColumn = 0; currColumn < numColumns; ++currColumn){
      cout <<  *((*(internalMatrix+currRow))+currColumn) << " ";
    }
    cout << endl;
  }
  }


  /**
  Static function takes two matrices in as arguments.
  If the first matrix column size does not match
  with the second matrix row size, exception is thrown.
  Otherwise, function multiplies the two matrices and
  return the result
  */
  static Matrix<Data> multiplyMatrices(Matrix<Data> matrixOne, Matrix<Data> matrixTwo){

    // checks to see if matrices can be multiplied based on dimensions
    if(matrixOne.getNumColumns() != matrixTwo.getNumRows())
    throw "Matrix dimensions not suitable to multiple.";

    //New matrix to hold matrix product with matrix one's rows and matrix two's columns
    Matrix<Data> matrixProduct (matrixOne.getNumRows(),matrixTwo.getNumColumns());

    for(int currRow = 0; currRow < matrixProduct.getNumRows(); ++currRow){
      for(int currColumn = 0; currColumn < matrixProduct.getNumColumns(); ++currColumn){
        Data value = 0;
        for(int count = 0; count < matrixOne.getNumColumns(); ++ count){
          //Keep the count constant to get first matrix row and second matrix column
          value += matrixOne(currRow,count) * matrixTwo(count,currColumn);
        }
        matrixProduct(currRow,currColumn) = value;
      }
    }

    return matrixProduct;
  }


  /**
  Creates a new internal data ** with the row and column widths
  switched. Loop through each element in the old matrix and assign
  it to the correct position in the new. Memory for the old internal
  matrix is freed, and is then assigned to the new internal matrix
  */
  void transpose(){

    //Creates new internal data **
    Data** newInternalMatrix;
    //Creates new rows with old column width
    newInternalMatrix = new Data*[numColumns];
    //Creates new columns with old row width
    for(int row=0; row < numColumns; ++row)
      *(newInternalMatrix+row) = new Data[numRows];
    //Assigns old elements to the proper location of the new matrix
    for(int currRow = 0; currRow < numRows; ++currRow)
      for(int currColumn = 0; currColumn < numColumns; ++ currColumn)
        *((*(newInternalMatrix+currColumn))+currRow) =  *((*(internalMatrix+currRow))+currColumn);
    //Deletes the old internal matrix memory
    for(int rowToDelete = 0; rowToDelete < numRows;++rowToDelete)
      delete[] internalMatrix[rowToDelete];
    // Assigns internal matrix to new internam matrix;
    internalMatrix = newInternalMatrix;
    Data temp = numRows;
    numRows = numColumns;
    numColumns = temp;
    newInternalMatrix = NULL;
  }

};
#endif
