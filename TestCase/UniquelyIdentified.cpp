#include <iostream>

using namespace std;

class UniquelyIdentified
{
    public:
        UniquelyIdentified();  // Construtor
        ~UniquelyIdentified();
        int getUniqueID() const;
    private:
        int instanceID;
        static int instanceCounter;
};

UniquelyIdentified::UniquelyIdentified() // Initializer list
{
    instanceID=++instanceCounter;
    cout << "Instance Created " << instanceID << endl;
}

UniquelyIdentified::~UniquelyIdentified()
{
    cout << "instance Destroyed " << instanceID << endl;
}

int UniquelyIdentified::getUniqueID() const
{
    return instanceID;
}

int UniquelyIdentified::instanceCounter = 0;

int main(void)
{
    UniquelyIdentified object1,object2,object3;
    {
        UniquelyIdentified object4;
    }

    cout << "Object 3 ID: " << object3.getUniqueID() << endl;
    // cout << "The current counter: " << UniquelyIdentified::instanceCounter << endl;

    return 0;
}
