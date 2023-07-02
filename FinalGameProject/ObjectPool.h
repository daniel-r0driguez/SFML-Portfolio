// Daniel Rodriguez : CS003A
// Super Mario but in SFML! | Final Game Project
#ifndef FINALPROJECTGAME_OBJECTPOOL_H
#define FINALPROJECTGAME_OBJECTPOOL_H
#include <queue>

template<typename T>
class ObjectPool {
private:
    std::queue<T*> pool;

public:
    ObjectPool();
    explicit ObjectPool(int size);
    ~ObjectPool();
    T* getObject();
    void returnObject(T* object);

private:
    void setUp(int size);
};

#include "ObjectPool.cpp"
#endif //FINALPROJECTGAME_OBJECTPOOL_H