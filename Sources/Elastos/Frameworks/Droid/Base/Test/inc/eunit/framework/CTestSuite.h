//=========================================================================
// Copyright (C) 2012 The Elastos Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//=========================================================================

#ifndef __CTESTSUITE_H__
#define __CTESTSUITE_H__

#include <elastos/coredef.h>
#include <Elastos.CoreLibrary.Utility.h>
#include "_Eunit_Framework_CTestSuite.h"
#include "eunit/framework/TestCase.h"
#include <elastos/utility/etl/List.h>

using Elastos::Utility::IEnumeration;
using Elastos::Utility::IVector;
using Elastos::Utility::Etl::List;

namespace Eunit {
namespace Framework {

CarClass(CTestSuite)
    , public Object
    , public ITest
    , public ITestSuite
{
private:
    class MyTestCase : public TestCase
    {
    public:
        MyTestCase(
            /* [in] */ const String& message)
            : mMessage(message)
        {}

        CARAPI GetClassID(
            /* [out] */ ClassID *pCLSID);

        CARAPI GetTestAnnotation(
            /* [out] */ ITestAnnotation** annotation);

    protected:
        CARAPI RunTest();

    private:
        String mMessage;
    };

public:
    CAR_INTERFACE_DECL()

    CAR_OBJECT_DECL()

    CTestSuite();

    CARAPI constructor();

    /**
     * Constructs a TestSuite from the given class. Adds all the methods
     * starting with "test" as test cases to the suite.
     * Parts of this method were written at 2337 meters in the Hueffihuette,
     * Kanton Uri
     */
    CARAPI constructor(
        /* [in] */ IClassInfo* theClass);

    /**
     * Constructs a TestSuite from the given class with the given name.
     * @see TestSuite#TestSuite(Class)
     */
    CARAPI constructor(
        /* [in] */ IClassInfo* theClass,
        /* [in] */ const String& name);

    /**
     * Constructs an empty TestSuite.
     */
    CARAPI constructor(
        /* [in] */ const String& name);

    /**
     * Constructs a TestSuite from the given array of classes.
     * @param classes {@link TestCase}s
     */
    CARAPI constructor(
        /* [in] */ ArrayOf<IClassInfo*>* classes);

    /**
     * Constructs a TestSuite from the given array of classes with the given name.
     * @see TestSuite#TestSuite(Class[])
     */
    CARAPI constructor(
        /* [in] */ ArrayOf<IClassInfo*>* classes,
        /* [in] */ const String& name);

    CARAPI Initialize();

    /**
     * ...as the moon sets over the early morning Merlin, Oregon
     * mountains, our intrepid adventurers type...
     */
    static CARAPI_(AutoPtr<ITest>) CreateTest(
        /* [in] */ IClassInfo* theClass,
        /* [in] */ const String& name);

    /**
     * Gets a constructor which takes a single String as
     * its argument or a no arg constructor.
     */
    static CARAPI GetTestConstructor(
        /* [in] */ IClassInfo* theClass,
        /* [out] */ IConstructorInfo** constructor);

    /**
     * Returns a test which will fail and log a warning message.
     */
    static CARAPI_(AutoPtr<ITest>) Warning(
        /* [in] */ const String& message);

    /**
     * Adds a test to the suite.
     */
    CARAPI AddTest(
        /* [in] */ ITest* test);

    /**
     * Adds the tests from the given class to the suite
     */
    CARAPI AddTestSuite(
        /* [in] */ IClassInfo* testClass);

    /**
     * Counts the number of test cases that will be run by this test.
     */
    CARAPI CountTestCases(
        /* [out] */ Int32* number);

    /**
     * Returns the name of the suite. Not all
     * test suites have a name and this method
     * can return null.
     */
    CARAPI GetName(
        /* [out] */ String* name);

    /**
     * Runs the tests and collects their result in a TestResult.
     */
    CARAPI Run(
        /* [in] */ ITestResult* result);

    CARAPI RunTest(
        /* [in] */ ITest* test,
        /* [in] */ ITestResult* result);

    /**
     * Sets the name of the suite.
     * @param name the name to set
     */
    CARAPI SetName(
        /* [in] */ const String& name);

    /**
     * Returns the test at the given index
     */
    CARAPI TestAt(
        /* [in] */ Int32 index,
        /* [out] */ ITest** test);

    /**
     * Returns the number of tests in this suite
     */
    CARAPI TestCount(
        /* [out] */ Int32* number);

    /**
     * Returns the tests as an enumeration
     */
    CARAPI Tests(
        /* [out] */ IEnumeration** tests);

    CARAPI ToString(
        /* [out] */ String* str);

    CARAPI GetTestAnnotation(
        /* [out] */ ITestAnnotation** annotation);

    CARAPI IsFailed(
        /* [out] */ Boolean* result);

    CARAPI AddFailure(
        /* [in] */ ECode ec,
        /* [in] */ const String& message,
        /* [in] */ const String& backtrace);

    CARAPI GetFailures(
        /* [out, callee] */ ArrayOf<ITestFailure*>** failures);

private:
    /**
     * Converts the stack trace into a string
     */
    static CARAPI_(String) ExceptionToString(
        /* [in] */ ECode ec);

    CARAPI_(void) AddTestsFromTestCase(
        /* [in] */ IClassInfo* theClass);

    CARAPI_(AutoPtr<ITest>) TestCaseForClass(
        /* [in] */ IClassInfo* each);

    CARAPI_(void) AddTestMethod(
        /* [in] */ IMethodInfo* m,
        /* [in] */ List<String>& names,
        /* [in] */ IClassInfo* theClass);

    CARAPI_(Boolean) IsPublicTestMethod(
        /* [in] */ IMethodInfo* m);

    CARAPI_(Boolean) IsTestMethod(
        /* [in] */ IMethodInfo* m);

private:
    String mName;

    AutoPtr<IVector> mTests; // Cannot convert this to List because it is used directly by some test runners
};

} // namespace Framework
} // namespace Eunit

#endif //__CTESTSUITE_H__
