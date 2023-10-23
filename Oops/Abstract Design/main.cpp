#include <bits/stdc++.h>
#include "bird.h"
using namespace std;

// void whatBirdDoes(Bird &bird);
void whatBirdDoes(Bird *(&bird))
{
    bird->eat();
    bird->fly();

    bird->eat();
    bird->fly();

    bird->eat();
    bird->fly();

    bird->fly();
    bird->eat();

    bird->fly();
    bird->eat();
}

int main()
{
    Bird *bird = new sparrow();
    whatBirdDoes(bird);

    Bird *amit = new eagle();
    whatBirdDoes(amit);

    Bird *sumit = new koyal();
    whatBirdDoes(sumit);
    return 0;
}