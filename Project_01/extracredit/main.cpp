/**
 * Program Name: Project 1, Extra Credit
 * Developer: Derek P Sifford
 * Date: 01.10.2016
 * Description: Calculate sum and/or product of large integers
 */
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include "largeintegers.h"
using namespace std;

void runTests();

int main() {

    runTests();

    return 0;
}

void runTests() {

    largeIntegers a("98743798534987987253424323452");
    largeIntegers b("78925349875495387345");

    // `set` method
    assert(a.stringValue() == "98743798534987987253424323452");
    assert(a.set("-99999")->stringValue() == "-99999");
    assert(a.set("12345")->stringValue() == "12345");

    // `add` methods
    assert(a.add(b)->stringValue() == "78925349875495399690");
    assert(b.add(a)->stringValue() == "157850699750990787035");
    assert(b.add(b)->stringValue() == "315701399501981574070");

    // `subtract` methods
    assert(a.subtract(b)->stringValue() == "-236776049626486174380");
    assert(a.subtract(*b.inverse())->stringValue() == "78925349875495399690");
    assert(a.set("12345")->subtract(*b.set("-54321"))->stringValue() == "66666");

    // `multiply` methods
    a.set("12345678987654321");
    b.set("98765432123456789");
    assert(a.multiply(b)->stringValue() == "1219326320073159566072245112635269");
    assert(b.inverse()->multiply(a)->stringValue() == "-120427290901529988367476356871223724848101638891241");
    assert(a.inverse()->multiply(b)->stringValue() == "146840165451342451431369719791286896744379256673748165920225623111015941900791778829");

    // Variety of chained methods
    a.set("91826928346");
    b.set("-92837649786545");
    assert(a.multiply(b)->subtract(b)->add(b)->stringValue() == "-8524996214760109909904570");

    // Add REALLY REALLY large pseudo integers
    a.set("97346589723465873465897234568972365978234687923498756234965982734569872346587923465987234687623489762346502347523479523749879");
    b.set("93457394567986798025910375934657234098243980572493562936923457923590237595923926398032492346593246907845");
    assert(a.add(b)->stringValue() == "97346589723465873465990691963540352776260598299433413469064226715142365909524846923910824925219413688744534839870072770657724");

    cout << "==== TESTS PASSED ====" << endl;
}
