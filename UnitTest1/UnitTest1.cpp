#include "pch.h"
#include "CppUnitTest.h"
#include "../PR8.1(rec).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestPR81Rec
{
    TEST_CLASS(UnitTestPR81Rec)
    {
    public:
        TEST_METHOD(TestChange)
        {
            // Тестування функції Change
            char str1[] = "nono nolo nido";
            char* result1 = new char[201];
            result1[0] = '\0';
            char* modified1 = Change(result1, str1, result1, 0);
            Assert::AreEqual(std::string("nono nolo nido"), std::string(modified1)); 

            char str2[] = "no";
            char* result2 = new char[201];
            result2[0] = '\0';
            char* modified2 = Change(result2, str2, result2, 0);
            Assert::AreEqual(std::string("no"), std::string(modified2)); 

            char str3[] = "nion";
            char* result3 = new char[201];
            result3[0] = '\0';
            char* modified3 = Change(result3, str3, result3, 0);
            Assert::AreEqual(std::string("**n"), std::string(modified3)); 

            char str4[] = "nno";
            char* result4 = new char[201];
            result4[0] = '\0';
            char* modified4 = Change(result4, str4, result4, 0);
            Assert::AreEqual(std::string("**"), std::string(modified4)); 

            
            delete[] result1;
            delete[] result2;
            delete[] result3;
            delete[] result4;
        }
    };
}