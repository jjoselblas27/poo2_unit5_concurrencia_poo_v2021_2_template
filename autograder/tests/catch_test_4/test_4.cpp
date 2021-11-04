//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "P4.h"
#include <iostream>
#include <thread>
#include <vector>
#include <numeric>
using namespace std;

static void question_4() {
    linked_list<int> ll = {1, 2, 3, 4};
    for (auto item: ll) { cout << item << " "; }
    cout << endl;

    vector<thread> vt(10);
    auto i = 0;
    for (auto& t: vt) {
        t = thread([&ll, i = ++i]{
            ll.push_front(i);
        });
    }
    for (auto& t: vt) t.join();

    cout << accumulate(ll.begin(), ll.end(), 0) << " " << endl;

    for (auto item: ll)
        cout << item << " ";
    cout << endl;
}

TEST_CASE("Question #4") {
    execute_test("test_4.in", question_4);
}