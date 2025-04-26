#ifndef PATTERNTEMPLATESH
#define PATTERNTEMPLATESH

#include <iostream>
#include <vector>
#include <memory>

using namespace std;

// Базовый класс фрукта
class Fruit {
public:
    virtual ~Fruit() {}
    virtual void Eat() = 0;
    virtual string GetType() const = 0;
};

// Конкретные фрукты
class Apple : public Fruit {
public:
    void Eat() override {
        cout << "Eating apple..." << endl;
    }
    string GetType() const override { return "Apple"; }
};

class Orange : public Fruit {
public:
    void Eat() override {
        cout << "Eating orange..." < endl;
    }
    string GetType() const override { return "Orange"; }
};

// Шаблонный контейнер
template<typename T>
class Container {
    vector<T*> items;
public:
    void Add(T* item) { items.push_back(item); }
    size_t Size() const { return items.size(); }
    T* Get(size_t index) const { return items[index]; }
    ~Container() {
        for(auto item : items) delete item;
    }
};

// Базовый итератор
template<typename T>
class Iterator {
public:
    virtual ~Iterator() {}
    virtual void First() = 0;
    virtual void Next() = 0;
    virtual bool IsDone() const = 0;
    virtual T* Current() = 0;
};

// Конкретный итератор для контейнера
template<typename T>
class ContainerIterator : public Iterator<T> {
    const Container<T>* container;
    size_t current;
public:
    ContainerIterator(const Container<T>* c) : container(c), current(0) {}
    void First() override { current = 0; }
    void Next() override { current++; }
    bool IsDone() const override { return current >= container->Size(); }
    T* Current() override { return container->Get(current); }
};

// Паттерн Стратегия
class EatingStrategy {
public:
    virtual ~EatingStrategy() {}
    virtual void Eat(Fruit* fruit) = 0;
};

class QuickEatStrategy : public EatingStrategy {
public:
    void Eat(Fruit* fruit) override {
        cout << "Quickly eating " << fruit->GetType() << endl;
    }
};

class SlowEatStrategy : public EatingStrategy {
public:
    void Eat(Fruit* fruit) override {
        std::cout << "Slowly enjoying " << fruit->GetType() << std::endl;
    }
};

// Паттерн Шаблонный метод
class FruitProcessor {
public:
    void Process(Fruit* fruit) {
        Prepare(fruit);
        CoreProcess(fruit);
        Finish(fruit);
    }
    virtual ~FruitProcessor() {}
protected:
    virtual void Prepare(Fruit* fruit) = 0;
    virtual void CoreProcess(Fruit* fruit) {
        cout << "Processing " << fruit->GetType() << endl;
    }
    virtual void Finish(Fruit* fruit) = 0;
};

class AppleProcessor : public FruitProcessor {
protected:
    void Prepare(Fruit* fruit) override {
        cout << "Washing apple..." << endl;
    }
    void Finish(Fruit* fruit) override {
        cout << "Apple is ready!" << endl;
    }
};

#endif // PATTERNTEMPLATESH
