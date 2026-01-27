#include <iostream>
#include <string>
#include <stdexcept>

void safeGetline(std::string& out)
{
    if (!std::getline(std::cin, out))
    {
        if (std::cin.eof())
            throw std::runtime_error("EOF");
        else
            throw std::runtime_error("Input failure");
    }
}

int main() {
    std::string s;

    // manually trigger failbit for testing
    std::cin.setstate(std::ios::failbit);

    try {
        safeGetline(s);
    } catch (std::runtime_error& e) {
        std::cout << "Caught exception: " << e.what() << "\n";
    }
}
