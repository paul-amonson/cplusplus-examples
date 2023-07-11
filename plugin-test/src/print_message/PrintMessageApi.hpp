#pragma once

namespace print_message {

class PrintMessageApi {
public:
    virtual void Print(const char* text) = 0;
}; // class PrintMessageApi
} // namespace print_messasge
