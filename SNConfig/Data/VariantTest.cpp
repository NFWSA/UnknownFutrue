#include "Variant.h"
#include <iostream>
#include <string>

using namespace std;
using namespace SurgeNight;

int main()
{
        int i = 123;
        float f = 345.6f;
        double d = 0.5678;
        unsigned char ch = 'S';
        string str = "Heelo";
        Variant t(0);
        cout << " -------------- Test -----------" << endl;
        cout << t.isInt() << ' ' << t.asInt() << endl;
        cout << t.isFloat() << ' ' << t.asFloat() << endl;
        cout << t.isDouble() << ' ' << t.asDouble() << endl;
        cout << t.isUChar() << ' ' << t.asUChar() << endl;
        cout << t.isString() << ' ' << t.asString() << endl;
        t = i;
        cout << " -------------- Test -----------" << endl;
        cout << t.isInt() << ' ' << t.asInt() << endl;
        cout << t.isFloat() << ' ' << t.asFloat() << endl;
        cout << t.isDouble() << ' ' << t.asDouble() << endl;
        cout << t.isUChar() << ' ' << t.asUChar() << endl;
        cout << t.isString() << ' ' << t.asString() << endl;
        t = f;
        cout << " -------------- Test -----------" << endl;
        cout << t.isInt() << ' ' << t.asInt() << endl;
        cout << t.isFloat() << ' ' << t.asFloat() << endl;
        cout << t.isDouble() << ' ' << t.asDouble() << endl;
        cout << t.isUChar() << ' ' << t.asUChar() << endl;
        cout << t.isString() << ' ' << t.asString() << endl;
        t = d;
        cout << " -------------- Test -----------" << endl;
        cout << t.isInt() << ' ' << t.asInt() << endl;
        cout << t.isFloat() << ' ' << t.asFloat() << endl;
        cout << t.isDouble() << ' ' << t.asDouble() << endl;
        cout << t.isUChar() << ' ' << t.asUChar() << endl;
        cout << t.isString() << ' ' << t.asString() << endl;
        t = ch;
        cout << " -------------- Test -----------" << endl;
        cout << t.isInt() << ' ' << t.asInt() << endl;
        cout << t.isFloat() << ' ' << t.asFloat() << endl;
        cout << t.isDouble() << ' ' << t.asDouble() << endl;
        cout << t.isUChar() << ' ' << t.asUChar() << endl;
        cout << t.isString() << ' ' << t.asString() << endl;
        t = str;
        cout << " -------------- Test -----------" << endl;
        cout << t.isInt() << ' ' << t.asInt() << endl;
        cout << t.isFloat() << ' ' << t.asFloat() << endl;
        cout << t.isDouble() << ' ' << t.asDouble() << endl;
        cout << t.isUChar() << ' ' << t.asUChar() << endl;
        cout << t.isString() << ' ' << t.asString() << endl;
        Variant tt(0.0f);
        tt = t;
        cout << " -------------- Test -----------" << endl;
        cout << t.isInt() << ' ' << t.asInt() << endl;
        cout << t.isFloat() << ' ' << t.asFloat() << endl;
        cout << t.isDouble() << ' ' << t.asDouble() << endl;
        cout << t.isUChar() << ' ' << t.asUChar() << endl;
        cout << t.isString() << ' ' << t.asString() << endl;
        t = ch;
        tt = t;
        cout << " -------------- Test -----------" << endl;
        cout << t.isInt() << ' ' << t.asInt() << endl;
        cout << t.isFloat() << ' ' << t.asFloat() << endl;
        cout << t.isDouble() << ' ' << t.asDouble() << endl;
        cout << t.isUChar() << ' ' << t.asUChar() << endl;
        cout << t.isString() << ' ' << t.asString() << endl;
        t = d;
        tt = t;
        cout << " -------------- Test -----------" << endl;
        cout << t.isInt() << ' ' << t.asInt() << endl;
        cout << t.isFloat() << ' ' << t.asFloat() << endl;
        cout << t.isDouble() << ' ' << t.asDouble() << endl;
        cout << t.isUChar() << ' ' << t.asUChar() << endl;
        cout << t.isString() << ' ' << t.asString() << endl;
        t = f;
        tt = t;
        cout << " -------------- Test -----------" << endl;
        cout << t.isInt() << ' ' << t.asInt() << endl;
        cout << t.isFloat() << ' ' << t.asFloat() << endl;
        cout << t.isDouble() << ' ' << t.asDouble() << endl;
        cout << t.isUChar() << ' ' << t.asUChar() << endl;
        cout << t.isString() << ' ' << t.asString() << endl;
        t = i;
        tt = t;
        cout << " -------------- Test -----------" << endl;
        cout << t.isInt() << ' ' << t.asInt() << endl;
        cout << t.isFloat() << ' ' << t.asFloat() << endl;
        cout << t.isDouble() << ' ' << t.asDouble() << endl;
        cout << t.isUChar() << ' ' << t.asUChar() << endl;
        cout << t.isString() << ' ' << t.asString() << endl;
        return 0;
}