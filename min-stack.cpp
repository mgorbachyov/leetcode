#include <cstdio>
#include <vector>

using namespace std;

class MinStack {
    struct entry_t {
        int val;
        int min;
        entry_t *next;
    };

    entry_t *_top = nullptr;

public:
    MinStack() { }

    void push(int val) {
        entry_t *e = new entry_t;
        e->val = val;
        e->next = _top;
        e->min = val;
        if (_top && _top->min < val) {
            e->min = _top->min;
        }
        _top = e;
    }

    void pop() {
        entry_t *e = _top;
        _top = (entry_t*)(e->next);
        delete e;
    }

    int top() {
        return _top->val;
    }

    int getMin() {
        return _top->min;
    }
};

int main(int argc, char* argv[])
{
    MinStack* obj = new MinStack();
    vector<int> values { -2, 0, -3, -3, -2, 0, 0 };

    for (const auto i : values) {
        obj->push(i);
        printf("top %d, min %d\n", obj->top(), obj->getMin());
    }

    for (const auto i : values) {
        printf("top %d, min %d\n", obj->top(), obj->getMin());
        obj->pop();
    }
    return 0;
}

