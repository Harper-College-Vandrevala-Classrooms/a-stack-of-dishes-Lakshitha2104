#include <iostream>
#include <array>
#include <string>
using namespace std;

class Dish {
private:
    string description;

public:
    // Default constructor
    Dish() : description("Default Dish") {}

    // Parameterized constructor
    Dish(string description) {
        this->description = description;
    }

    string get_description() const {
        return this->description;
    }
};

class DishStack {
private:
    static const int MAX_SIZE = 10; // Define a maximum size for the stack
    array<Dish, MAX_SIZE> stack;
    int top;

public:
    DishStack() : top(-1) {} // Initialize the stack with top set to -1 (empty)

    // Push a Dish onto the stack
    void push(const Dish& dish) {
        if (top >= MAX_SIZE - 1) {
            cout << "The stack is full! Cannot add more dishes." << endl;
            return;
        }
        stack[++top] = dish;
    }

    // Pop a Dish from the stack
    Dish pop() {
        if (top == -1) {
            throw runtime_error("The stack is empty! Cannot pop any dishes.");
        }
        return stack[top--];
    }

    // Peek at the top Dish on the stack
    Dish peek() const {
        if (top == -1) {
            throw runtime_error("The stack is empty! Cannot peek.");
        }
        return stack[top];
    }

    // Get the current size of the stack
    int size() const {
        return top + 1;
    }
};

int main() {
    DishStack stack;

    Dish one_dish("A dish with one fish pattern on it");
    Dish two_dish("A dish with two fish patterns on it");
    Dish red_dish("A dish with a red fish pattern on it");
    Dish blue_dish("A dish with a blue fish pattern on it");

    // The variable stack_size should equal zero.
    int stack_size = stack.size();
    cout << "Initial stack size: " << stack_size << endl;

    stack.push(one_dish);
    stack.push(two_dish);
    stack.push(red_dish);
    stack.push(blue_dish);

    // The variable size_after_pushes should equal four.
    int size_after_pushes = stack.size();
    cout << "Stack size after pushes: " << size_after_pushes << endl;

    // The variable peeked_dish should have a description of "A dish with a blue fish pattern on it"
    Dish peeked_dish = stack.peek();
    cout << "Peeked dish: " << peeked_dish.get_description() << endl;

    // The variable popped_dish should have a description of "A dish with a blue fish pattern on it"
    Dish popped_dish = stack.pop();
    cout << "Popped dish: " << popped_dish.get_description() << endl;

    // The variable another_popped_dish should have a description of "A dish with a red fish pattern on it"
    Dish another_popped_dish = stack.pop();
    cout << "Another popped dish: " << another_popped_dish.get_description() << endl;

    // The variable final_size should equal two.
    int final_size = stack.size();
    cout << "Final stack size: " << final_size << endl;

    return 0;
}