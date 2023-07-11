#pragma once

namespace error_message {

class ErrorMessageApi {
public:
    virtual void PrintError(const char* text) = 0;
}; // class ErrorMessageApi
} // namespace error_messasge
