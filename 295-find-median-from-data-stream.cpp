#include <cstdio>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

class MedianFinder {
public:
    MedianFinder() {}

    void addNum(int num) {
        if (_low.size() < _high.size()) {
            if (_high.top() < num) {
                _low.push(_high.top());
                _high.pop();
                _high.push(num);
            } else {
                _low.push(num);
            }
            return;
        }

        if (_low.size() > _high.size()) {
            if (_low.top() > num) {
                _high.push(_low.top());
                _low.pop();
                _low.push(num);
            } else {
                _high.push(num);
            }
            return;
        }

        if (_low.size() > 0 && num > _low.top()) {
            _high.push(num);
            return;
        }
        _low.push(num);
    }

    double findMedian() {
        show();

        if (_low.size() < _high.size()) {
            return _high.top();
        }
        if (_low.size() > _high.size()) {
            return _low.top();
        }
        return (_high.top() + _low.top()) / 2.0f;
    }

private:
    priority_queue<int> _low;
    priority_queue<int, vector<int>, greater<int>> _high;

    void show() {
        priority_queue<int> q1 = _low;
        printf("low:");
        for (; !q1.empty(); q1.pop()) {
            printf(" %d", q1.top());
        }
        printf("\n");

        priority_queue<int, vector<int>, greater<int>> q2 = _high;
        printf("high:");
        for (; !q2.empty(); q2.pop()) {
            printf(" %d", q2.top());
        }
        printf("\n");
    }
};

int main(int argc, char *argv[])
{
    MedianFinder obj;
    obj.addNum(1);
    obj.addNum(2);
    double r1 = obj.findMedian();
    printf("r1: %f\n", r1);
    obj.addNum(3);
    obj.addNum(3);
    obj.addNum(4);
    double r2 = obj.findMedian();
    printf("r2: %f\n", r2);
    return 0;
}

