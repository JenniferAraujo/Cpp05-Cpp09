#include "ScalarConverte.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
        return 1;
    }
    ScalarConverter converter(argv[1]);
    converter.convert();
    return 0;
}
