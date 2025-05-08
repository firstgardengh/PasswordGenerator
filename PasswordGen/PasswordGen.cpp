#include <iostream>
#include "PasswordGen.hpp"

int main()
{
    srand((uint32_t)time(0));
    std::string password = pass_gen->generate_password("Password", 24);

    std::printf("Singular password: %s\n\n", password.c_str());

    std::vector<std::string> buffer = pass_gen->generate_multiple_passwords(15, "Password", 24);
    for (std::string pass : buffer)
        std::printf("Multi Password: %s\n", pass.c_str());

    int flags = pass_gen->password_strength(password);
    std::printf("\nPassword strength flags for singular password: %i\n\n", flags);
    std::printf("logs:\n");

    if (flags != 0) {
        for (std::string log : pass_gen->logs)
        {
            std::printf("%s\n", log.c_str());
        }
    }

    std::cin.get();
    return 0;
}
