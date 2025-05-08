# PasswordGenerator
This project generates a password that includes parameters for password customization.

# Usage
```cpp
std::string password = pass_gen->generate_password(prefix, length, upper, lower, num, special);
```
The code above generates a password based on the specified parameters.


```cpp
    std::vector<std::string> buffer = pass_gen->generate_multiple_passwords(amount, prefix, length, upper, lower, num, special);
    for (std::string pass : buffer)
        std::printf("Multi Password: %s\n", pass.c_str());
```
With this code you generate passwords the same, but multiple.


```cpp
int flags = pass_gen->password_strength(password);
std::printf("Password strength flags for singular password: %i", flags);
```
Here we check the flags of the password's conditions. For each type (`upper`, `lower`, `numerical`, `special`) you get 1 point added to the flag.
The final flag total would be 4.


```cpp
for (std::string log : pass_gen->logs)
{
    std::printf("%s\n", log.c_str());
}
```
We then print the logs based on the password's conditions. You get a `success` log if you get all 4.
