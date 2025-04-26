#include "PatternTemplates.h"
#include <memory>

using namespace std;

void DemoContainerAndIterator() {
    cout << " Container and Iterator Demo " << endl;

    Container<Fruit> fruitBox;
    fruitBox.Add(new Apple());
    fruitBox.Add(new Orange());

    ContainerIterator<Fruit> it(&fruitBox);
    for(it.First(); !it.IsDone(); it.Next()) {
        it.Current()->Eat();
    }
}

void DemoStrategies() {
    cout << "\n Strategies Demo " << endl;

    Apple apple;
    Orange orange;

    QuickEatStrategy quick;
    SlowEatStrategy slow;

    quick.Eat(&apple);
    slow.Eat(&orange);
}

void DemoTemplateMethod() {
    cout << "\n Template Method Demo " << endl;

    Apple apple;
    AppleProcessor processor;

    processor.Process(&apple);
}

int main() {
    DemoContainerAndIterator();
    DemoStrategies();
    DemoTemplateMethod();

    return 0;
}
