#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Name, age, phone number, location
    string name = get_string("Name: ");
    int age = get_int("Age: ");
    string phone = get_string("Phone number: ");
    string location = get_string("Location: ");

    printf("New Contact: %s, %i, lives in %s, and can be reached at %s\n", name, age, location, phone);

}