#pragma once
using namespace System;

public ref class MyException : public Exception
{
public:
    MyException(String^ msg) : Exception(msg) {}

    virtual String^ ToString() override
    {
        return "MyException: " + Message;
    }
};
