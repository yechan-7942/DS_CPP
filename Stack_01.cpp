#include <iostream>
#include <stdexcept> // 예외 처리를 위해 추가

constexpr int STACK_MAX_SIZE = 5;

class ArrayStack {
private:
    int stack_array[STACK_MAX_SIZE];
    int top_index;

public:
    ArrayStack() : top_index(0) {
        std::cout << "스택 생성 완료 (최대 크기: " << STACK_MAX_SIZE << ")\n";
    }

    bool stack_empty() const {
        return top_index == 0;
    }

    bool stack_full() const {
        return top_index >= STACK_MAX_SIZE;
    }

    void push(int item) {
        if (stack_full()) {
            throw std::overflow_error("스택이 가득 찼습니다.");
        }
        stack_array[top_index++] = item;
    }

    int pop() {
        if (stack_empty()) {
            throw std::underflow_error("스택이 비어있습니다.");
        }
        return stack_array[--top_index];
    }

    void print_stack() const {
        if (stack_empty()) {
            std::cout << "스택이 비어있습니다.\n";
            return;
        }
        std::cout << "스택 내용 (Top -> Bottom): [";
        for (int i = top_index - 1; i >= 0; --i) {
            std::cout << stack_array[i];
            if (i > 0) std::cout << ", ";
        }
        std::cout << "]\n";
    }
};

int main() {
    ArrayStack myStack;

    try {
        myStack.print_stack();

        std::cout << "\n--- 푸시 작업 ---\n";
        myStack.push(10);
        myStack.push(20);
        myStack.push(30);
        myStack.print_stack();

        std::cout << "\n--- 팝 작업 ---\n";
        std::cout << myStack.pop() << " 팝됨\n";
        myStack.print_stack();

        std::cout << "\n--- 추가 푸시 ---\n";
        myStack.push(40);
        myStack.push(50);
        myStack.push(60); // 예외 발생 예상
        myStack.print_stack();
    }
    catch (const std::exception& e) {
        std::cerr << "예외 발생: " << e.what() << "\n";
    }

    return 0;
}
