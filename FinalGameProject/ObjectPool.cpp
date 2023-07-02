// Daniel Rodriguez : CS003A
// Super Mario but in SFML! | Final Game Project
#ifndef FINALPROJECTGAME_OBJECTPOOL_CPP
#define FINALPROJECTGAME_OBJECTPOOL_CPP
#include "ObjectPool.h"

template<typename T>
ObjectPool<T>::ObjectPool()
: ObjectPool(10)
{

}

template<typename T>
ObjectPool<T>::ObjectPool(int size)
{
    setUp(size);
}

template<typename T>
ObjectPool<T>::~ObjectPool()
{
    while (!this->pool.empty())
    {
        delete this->pool.front();
        this->pool.pop();
    }
}

template<typename T>
T* ObjectPool<T>::getObject()
{
    if (this->pool.empty())
    {
        return nullptr;
    }
    T* object = this->pool.front();
    this->pool.pop();
    return object;
}

template<typename T>
void ObjectPool<T>::returnObject(T* object)
{
    this->pool.push(object);
}

template<typename T>
void ObjectPool<T>::setUp(int size)
{
    for (int i = 0; i < size; ++i)
    {
        this->pool.push(new T());
    }
}

#endif //FINALPROJECTGAME_OBJECTPOOL_CPP