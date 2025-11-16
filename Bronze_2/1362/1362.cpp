#include <iostream>
#include <string>

using namespace std;

bool isHappy(double appropriateWeight, int currentWeight);

int main()
{
    string happy = ":-)";
    string sad = ":-(";
    string die = "RIP";
    int senarioCount = 1;

    while (true)
    {
        double appropriateWeight;
        int currentWeight;
        cin >> appropriateWeight >> currentWeight;
        if (appropriateWeight == 0 && currentWeight == 0)
        {
                return 0;
        }
        bool isDead = false;
        while (true)
        {
            string action;
            int weightChange;
            cin >> action >> weightChange;

            if (action == "F")
            {
                currentWeight += weightChange;
            }
            else if (action == "E")
            {
                currentWeight -= weightChange;
                 if (currentWeight <= 0)
                {
                    isDead = true;
                }
            }
            else if (action == "#")
            {
                if (isDead == true)
                {
                    cout << to_string(senarioCount++) + " " + die << "\n";

                } else if (isHappy(appropriateWeight, currentWeight) == true)
                {
                    cout << to_string(senarioCount++) + " " + happy << "\n";
                }
                else if (currentWeight <= 0)
                {
                    cout << to_string(senarioCount++) + " " + die << "\n";
                }
                else
                {
                    cout << to_string(senarioCount++) + " " + sad << "\n";
                }
                break;
            }
        }
    }

    return 0;
}

bool isHappy(double appropriateWeight, int currentWeight)
{
    int max = appropriateWeight * 2.0;
    int min = appropriateWeight * 0.5;

    return currentWeight < max && currentWeight > min;
}