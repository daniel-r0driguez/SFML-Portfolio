#ifndef SFML_TEMPLATE_GRID_H
#define SFML_TEMPLATE_GRID_H
#include <iostream>

// This is a template type class which dynamically allocates arrays of arrays (a 2D-Array) of data type T.
template<typename T>
class Grid {
private:
    static int allocations;
    static int deallocations;

protected:
    unsigned int _rowSize = 0;
    unsigned int _columnSize = 0;
    unsigned int _rowCapacity = 0;
    unsigned int _columnCapacity = 0;
    T* *ptrToPtrs = nullptr;

public:
    // Static functions
    static int getClassAllocations();
    static int getClassDeallocations();

    // Constructors
    // Default Constructor
    Grid();
    // Copy Constructor
    Grid(const Grid<T>& grid);
    // Overloaded constructor. Constructs a Grid object with n rows and m columns.
    // Elements of the grid are filled to 0s of their appropriate type.
    Grid(unsigned int rows, unsigned int columns);
    // Overloaded constructor. Constructs a Grid object with n rows and m columns.
    // Elements of the grid are filled with the passed in default value.
    Grid(unsigned int rows, unsigned int columns, const T& defaultValue);
    // Destructor. Frees up all dynamically created arrays.
    ~Grid();

    // Operators
    // Assignment operator. Makes this Grid have the same values as that of parameter @grid.
    Grid& operator=(const Grid& grid);

    // Getter/Setters
    // Returns the current row size of the grid.
    int rowSize() const;
    // Returns the current column size of the grid.
    int columnSize() const;
    // Returns the grid's row capacity (How many rows it can hold).
    int rowCapacity() const;
    // Returns the grid's column capacity (How many columns it can hold).
    int columnCapacity () const;
    // Returns a reference to the element at a particular point in the grid.
    T& at(unsigned int row, unsigned int column);
    // Returns a constant reference to the element at a particular point in the grid.
    const T& at(unsigned int row, unsigned int column) const;

    // Modifiers
    // Adds a new row on the bottom of the grid and fills it with elements copied from the row above it.
    void push_back_row();
    // Adds a new row on the bottom of the grid and fills this row's elements with the parameter @defaultValue.
    void push_back_row(const T& defaultValue);
    // Adds a new column on the right of the grid. This new column's values are copied adjacently from its left column.
    void push_back_column();
    // Adds a new column on the right of the grid. This column's values are filled the parameter @defaultValue.
    void push_back_column(const T& defaultValue);
    // Removes the last row and reduces the row size by one.
    void pop_back_row();
    // Removes the last column and reduces the column size by one.
    void pop_back_column();
    // Deletes all dynamically created arrays and sets the attributes of the grid to 0.
    // Useful for freeing up memory, when you longer need the grid.
    void deleteGrid();
    // Fills the indexed row with the parameter @defaultValue.
    void fillRow(unsigned int row, const T& defaultValue);
    // Copies elements from the row-above and stores them in the indexed row.
    void fillRowAdjacently(unsigned int row);
    // Fills the indexed column with the parameter @defaultValue.
    void fillColumn(unsigned int column, const T& defaultValue);
    // Copies elements from the left-column into the indexed column.
    void fillColumnAdjacently(unsigned int column);
    // Shrinks the row capacity to fit that of the grid's row size.
    void rowShrinkToFit();
    // Shrinks the column capacity to fit that of the grid's column size.
    void columnShrinkToFit();
    // Shrinks both the row and column capacity to fit that of the grid's row and column size.
    void shrinkToFit();

private:
    // Frees up all the dynamically allocated arrays stored in a temp pointer to array of pointers.
    void deleteTempGrid(T* *&tempPtr);
    // Resizes the row capacity if the row size has reached the max capacity.
    void resizeRows(unsigned int rowAllocationSize);
    // Resizes the column capacity if the column size has reached the max capacity.
    void resizeColumns();
    // Copies the elements of a grid (2D-Dynamic Array) to this->ptrToPtrs.
    void copyGrid(T* *ptrToArrayOfPtrs);
    // Fills the contents of this->ptrToPtrs with 0s of the appropriate type (Default constructors).
    void fillGrid();
    // Fills the entire contents of this->ptrToPtrs with the parameter @defaultValue.
    void fillGridDefault(const T& defaultValue);
    // Allocates a new dynamic array of pointers.
    // It allocates enough space by using this->_rowCapacity as the allocation size.
    void allocateArrayOfPointers();
    // Allocates new dynamic arrays for each element of this->ptrToPtrs to point to.
    // IMPORTANT: Old dynamic arrays should be deleted using Gridefore calling this function.
    // Otherwise, this will lead to a memory leak.
    // Also, this->ptrToPtrs should not be nullptr prior to calling this function.
    void allocateDynamicArrays(unsigned int rowAllocationSize);
};

#include "Grid.cpp"
#endif //SFML_TEMPLATE_GRID_H