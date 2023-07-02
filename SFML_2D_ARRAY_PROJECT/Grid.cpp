#ifndef SFML_TEMPLATE_GRID_CPP
#define SFML_TEMPLATE_GRID_CPP
#include "Grid.h"

template<typename T>
int Grid<T>::allocations = 0;

template<typename T>
int Grid<T>::deallocations = 0;

template<typename T>
int Grid<T>::getClassAllocations()
{
    return Grid<T>::allocations;
}

template<typename T>
int Grid<T>::getClassDeallocations()
{
    return Grid<T>::deallocations;
}

template<typename T>
Grid<T>::Grid()
{
    this->_rowSize = 0;
    this->_columnSize = 0;
    this->_rowCapacity = 0;
    this->_columnCapacity = 0;
    this->ptrToPtrs = nullptr;
}

template<typename T>
Grid<T>::Grid(const Grid<T>& grid)
{
    *this = grid;
}

template<typename T>
Grid<T>::Grid(unsigned int rows, unsigned int columns)
{
    this->_rowSize = rows;
    this->_columnSize = columns;
    this->_rowCapacity = rows;
    this->_columnCapacity = columns;
    allocateArrayOfPointers();
    fillGrid();
}

template<typename T>
Grid<T>::Grid(unsigned int rows, unsigned int columns, const T &defaultValue)
{
    this->_rowSize = rows;
    this->_columnSize = columns;
    this->_rowCapacity = rows;
    this->_columnCapacity = columns;
    allocateArrayOfPointers();
    fillGridDefault(defaultValue);
}

template<typename T>
Grid<T>::~Grid()
{
    deleteGrid();
}

template<typename T>
Grid<T>& Grid<T>::operator=(const Grid<T>& grid)
{
    if (this != &grid)
    {
        this->~Grid();
        this->_rowSize = grid._rows;
        this->_columnSize = grid._columns;
        this->_rowCapacity = grid._rowCapacity;
        this->_columnCapacity = grid._columnCapacity;
        allocateArrayOfPointers();
        allocateDynamicArrays(this->_rowSize);
        copyGrid(grid.ptrToPtrs);
    }
    return *this;
}

template<typename T>
int Grid<T>::rowSize() const
{
    return this->_rowSize;
}

template<typename T>
int Grid<T>::columnSize() const
{
    return this->_columnSize;
}

template<typename T>
void Grid<T>::push_back_row(const T& defaultValue)
{
    if (this->_rowSize < this->_rowCapacity)
    {
        *(this->ptrToPtrs + this->_rowSize) = new T[this->_columnCapacity];
        ++Grid<T>::allocations;
        fillRow(this->_rowSize, defaultValue);
        ++this->_rowSize;
    }
    else
    {
        resizeRows(this->_rowSize + 1);
        fillRow(this->_rowSize, defaultValue);
        ++this->_rowSize;
    }
}

template<typename T>
void Grid<T>::push_back_row()
{
    if (this->_rowSize < this->_rowCapacity)
    {
        *(this->ptrToPtrs + this->_rowSize) = new T[this->_columnCapacity];
        ++Grid<T>::allocations;
        fillRowAdjacently(this->_rowSize);
        ++this->_rowSize;
    }
    else
    {
        resizeRows(this->_rowSize + 1);
        fillRowAdjacently(this->_rowSize);
        ++this->_rowSize;
    }
}

template<typename T>
void Grid<T>::push_back_column()
{
    if (this->_columnSize < this->_columnCapacity)
    {
        fillColumnAdjacently(this->_columnSize);
        ++this->_columnSize;
    }
    else
    {
        resizeColumns();
        fillColumnAdjacently(this->_columnSize);
        ++this->_columnSize;
    }
}

template<typename T>
void Grid<T>::push_back_column(const T &defaultValue)
{
    if (this->_columnSize < this->_columnCapacity)
    {
        fillColumn(this->_columnSize, defaultValue);
        ++this->_columnSize;
    }
    else
    {
        resizeColumns();
        fillColumn(this->_columnSize, defaultValue);
        ++this->_columnSize;
    }
}

template<typename T>
void Grid<T>::pop_back_row()
{
    if (this->_rowSize == 0)
    {
        return;
    }
    else
    {
        --this->_rowSize;
        delete [] *(this->ptrToPtrs + this->_rowSize);
        ++Grid<T>::deallocations;
    }
}

template<typename T>
void Grid<T>::pop_back_column()
{
    if (this->_columnSize == 0)
    {
        return;
    }
    else
    {
        --this->_columnSize;
    }
}

template<typename T>
int Grid<T>::rowCapacity() const
{
    return this->_rowCapacity;
}

template<typename T>
int Grid<T>::columnCapacity() const
{
    return this->_columnCapacity;
}

template<typename T>
T& Grid<T>::at(unsigned int row, unsigned int column)
{
    if (this->ptrToPtrs != nullptr)
    {
        return *(*(this->ptrToPtrs + row) + column);
    }

}

template<typename T>
const T& Grid<T>::at(unsigned int row, unsigned int column) const
{
    if (this->ptrToPtrs != nullptr)
    {
        return *(*(this->ptrToPtrs + row) + column);
    }
}

template<typename T>
void Grid<T>::deleteGrid()
{
    if (this->ptrToPtrs != nullptr)
    {
        for (int i = 0; i < this->_rowSize; ++i)
        {
            delete [] *(this->ptrToPtrs + i);
            ++Grid<T>::deallocations;
        }
        delete [] this->ptrToPtrs;
        ++Grid<T>::deallocations;
        this->_rowSize = 0;
        this->_columnSize = 0;
        this->_rowCapacity = 0;
        this->_columnCapacity = 0;
        this->ptrToPtrs = nullptr;
    }
}

template<typename T>
void Grid<T>::rowShrinkToFit()
{
    this->_rowCapacity = this->_rowSize;
    T* *oldGrid = this->ptrToPtrs;
    allocateArrayOfPointers();
    allocateDynamicArrays(this->_rowSize);
    copyGrid(oldGrid);
    deleteTempGrid(oldGrid);
}

template<typename T>
void Grid<T>::columnShrinkToFit()
{
    this->_columnCapacity = this->_columnSize;
    T* *oldGrid = this->ptrToPtrs;
    allocateArrayOfPointers();
    allocateDynamicArrays(this->_rowSize);
    copyGrid(oldGrid);
    deleteTempGrid(oldGrid);
}

template<typename T>
void Grid<T>::shrinkToFit()
{
    this->_rowCapacity = this->_rowSize;
    this->_columnCapacity = this->_columnSize;
    T* *oldGrid = this->ptrToPtrs;
    allocateArrayOfPointers();
    allocateDynamicArrays(this->_rowSize);
    copyGrid(oldGrid);
    deleteTempGrid(oldGrid);
}

template<typename T>
void Grid<T>::fillRow(unsigned int row, const T &defaultValue)
{
    if (this->ptrToPtrs != nullptr)
    {
        for (int column = 0; column < this->_columnSize; ++column)
        {
            *(*(this->ptrToPtrs + row) + column) = defaultValue;
        }
    }
}

template<typename T>
void Grid<T>::fillRowAdjacently(unsigned int row)
{
    if (this->ptrToPtrs != nullptr)
    {
        if (row == 0)
        {
            for (int column = 0; column < this->_columnSize; ++column)
            {
                *(*(this->ptrToPtrs + row) + column) = T();
            }
            return;
        }
        for (int column = 0; column < this->_columnSize; ++column)
        {
            *(*(this->ptrToPtrs + row) + column) = *(*(this->ptrToPtrs + row - 1) + column);
        }
    }
}

template<typename T>
void Grid<T>::fillColumn(unsigned int column, const T& defaultValue)
{
    if (this->ptrToPtrs != nullptr)
    {
        for (int i = 0; i < this->_rowSize; ++i)
        {
            *(*(this->ptrToPtrs + i) + column) = defaultValue;
        }
    }
}

template<typename T>
void Grid<T>::fillColumnAdjacently(unsigned int column)
{
    if (this->ptrToPtrs != nullptr)
    {
        if (column == 0)
        {
            for (int i = 0; i < this->_rowSize; ++i)
            {
                *(*(this->ptrToPtrs + i) + column) = T();
            }
            return;
        }
        for (int i = 0; i < this->_rowSize; ++i)
        {
            *(*(this->ptrToPtrs + i) + column) = *(*(this->ptrToPtrs + i) + column - 1);
        }
    }
}

template<typename T>
void Grid<T>::resizeRows(unsigned int rowAllocationSize)
{
    if (this->_rowCapacity == 0)
    {
        this->_rowCapacity = 1;
        if (this->_columnCapacity == 0)
        {
            this->_columnCapacity = 1;
            ++this->_columnSize;
        }
        allocateArrayOfPointers();
        allocateDynamicArrays(rowAllocationSize);
    }
    else
    {
        this->_rowCapacity *= 2;
        T* *oldGrid = this->ptrToPtrs;
        allocateArrayOfPointers();
        allocateDynamicArrays(rowAllocationSize);
        copyGrid(oldGrid);
        deleteTempGrid(oldGrid);
    }
}

template<typename T>
void Grid<T>::resizeColumns()
{
    if (this->_columnCapacity == 0)
    {
        this->_columnCapacity = 1;
        if (this->_rowCapacity == 0)
        {
            this->_rowCapacity = 1;
            ++this->_rowSize;
        }
        allocateArrayOfPointers();
        allocateDynamicArrays(this->_rowSize);
    }
    else
    {
        this->_columnCapacity *= 2;
        T* *oldGrid = this->ptrToPtrs;
        allocateArrayOfPointers();
        allocateDynamicArrays(this->_rowSize);
        copyGrid(oldGrid);
        deleteTempGrid(oldGrid);
    }
}

template<typename T>
void Grid<T>::copyGrid(T* *ptrToArrayOfPtrs)
{
    if (this->ptrToPtrs != nullptr && ptrToArrayOfPtrs != nullptr)
    {
        for (int row = 0; row < this->_rowSize; ++row)
        {
            for (int column = 0; column < this->_columnSize; ++column)
            {
                *(*(this->ptrToPtrs + row) + column) = *(*(ptrToArrayOfPtrs + row) + column);
            }
        }
    }
}

template<typename T>
void Grid<T>::fillGrid()
{
    if (this->ptrToPtrs != nullptr)
    {
        // Create new dynamic arrays for the array of pointers to point to.
        allocateDynamicArrays(this->_rowSize);
        // Fill the grid.
        for (int row = 0; row < this->_rowSize; ++row)
        {
            for (int column = 0; column < this->_columnSize; ++column)
            {
                // Fill the entire row, column by column.
                *(*(this->ptrToPtrs + row) + column) = T();
            }
        }
    }
}

template<typename T>
void Grid<T>::fillGridDefault(const T& defaultValue)
{
    if (this->ptrToPtrs != nullptr)
    {
        // Create new dynamic arrays for the array of pointers to point to.
        allocateDynamicArrays(this->_rowSize);
        // Fill the grid.
        for (int row = 0; row < this->_rowSize; ++row)
        {
            for (int column = 0; column < this->_columnSize; ++column)
            {
                // Fill the entire row, column by column.
                *(*(this->ptrToPtrs + row) + column) = defaultValue;
            }
        }
    }
}

template<typename T>
void Grid<T>::allocateArrayOfPointers()
{
    this->ptrToPtrs = new T*[this->_rowCapacity];
    ++Grid<T>::allocations;
}

template<typename T>
void Grid<T>::allocateDynamicArrays(unsigned int rowAllocationSize)
{
    if (this->ptrToPtrs != nullptr)
    {
        for (int row = 0; row < rowAllocationSize; ++row)
        {
            *(this->ptrToPtrs + row) = new T[this->_columnCapacity];
            ++Grid<T>::allocations;
        }
    }
}

template<typename T>
void Grid<T>::deleteTempGrid(T* *&tempPtr)
{
    if (tempPtr != nullptr)
    {
        for (int row = 0; row < this->_rowSize; ++row)
        {
            delete [] *(tempPtr + row);
            ++Grid<T>::deallocations;
        }
        delete [] tempPtr;
        ++Grid<T>::deallocations;
    }

}

#endif //SFML_TEMPLATE_GRID_CPP