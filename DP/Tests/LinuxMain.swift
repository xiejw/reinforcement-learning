import XCTest

import PolicyEvaluationTests

var tests = [XCTestCaseEntry]()
tests += PolicyEvaluationTests.allTests()
tests += PolicyIterationTests.allTests()
XCTMain(tests)
