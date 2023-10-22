#if !defined(BIRD_h)
#define BIRD_h
class Bird
{
public:
    virtual void eat() = 0;
    virtual void fly() = 0;
};

class sparrow : public Bird
{
}

#endif // BIRD_h
