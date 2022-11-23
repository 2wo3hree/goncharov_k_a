#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include "queuep.h"
#include <vector>
#include <algorithm>


TEST_CASE("QueueP::push()") {
    std::vector<int> v(0);
    QueueP q = QueueP();

    for (int i = 10; i > 0; --i) {
        v.push_back(i);
        q.push(i);
    }

    std::sort(v.begin(), v.end());

    int tmp = 0;

    for (size_t i = 0; i < v.size(); ++i) {
        tmp = q.top();
        q.pop();
        REQUIRE(v[i] == tmp);
    }

    srand(time(NULL));
    v.clear();

    for (size_t i = 0; i < 10; ++i) {
        int rnd = rand() % 100;
        v.push_back(rnd);
        q.push(rnd);
    }

    std::sort(v.begin(), v.end());

    for (size_t i = 0; i < v.size(); ++i) {
        tmp = q.top();
        q.pop();
        REQUIRE(v[i] == tmp);
    }

}
