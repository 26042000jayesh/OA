#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> possibleWay;
    bool canCross = false;

    void crossCircle(vector<int> &enemyPowers, int circleNumber, int power, int skipsLeft)
    {
        // base cases
        if (circleNumber == 11)
        {
            if (canCross == false && power >= 0)
            {
                canCross = true;
                //printing abhimanyu decisions 
                for (auto ele : possibleWay)
                {
                    cout << ele << " ";
                }
                cout << endl;
            }

            return;
        }
        // abhimanyu decides to take a fight
        possibleWay.push_back("Fight");
        crossCircle(enemyPowers, circleNumber + 1, power - enemyPowers[circleNumber], skipsLeft);
        possibleWay.pop_back();
        possibleWay.push_back("Skipped");
        // abhimanyu decides to skip the fight
        if (skipsLeft)
        {
            crossCircle(enemyPowers, circleNumber + 1, power, skipsLeft - 1);
        }
        possibleWay.pop_back();
    }
};

int main()
{
    vector<int> enemyPowers(11, 0);
    for (int i = 0; i < 11; i++)
    {
        cout << "Enter the power of" << i + 1 << " enemy :";
        cin >> enemyPowers[i];
    }
    int power, skipsLeft, rechargeLeft;
    cout << "Enter the power of Abhimanyu : ";
    cin >> power;
    cout << "Enter the number of skips allowed : ";
    cin >> skipsLeft;
    cout << "Enter the number of recharge left : ";
    cin >> rechargeLeft;
    Solution ob;
    if (enemyPowers[0] > power)
    {
        cout << "Abhimanyu cannot enter the circles : ";
    }
    else
    {
        cout << "Abhimanyu enters the circles : ";
        enemyPowers[3] += enemyPowers[2] * 0.5;
        enemyPowers[7] += enemyPowers[6] * 0.5;
        power = power + rechargeLeft * power;
        ob.crossCircle(enemyPowers, 0, power, skipsLeft);
    }
    cout << ob.canCross << endl;
    return 0;
}





// enemies : 3 4 500000 2 6 7 9 8 3 2 4
// power = 100
// skips = 2
// recharge = 1
// output = true

// enemies : 3 4 500000 2 6 7 9 8 3 2 4
// power = 100
// skips = 1
// recharge = 1
// output = false

// enemies : 3 4 500000 2 6 7 9 8 3 2 4
// power = 100
// skips = 1
// recharge = 2500
// output = true

// enemies : 3 4 5 2 6 7 9 8 3 2 4
// power = 10
// skips = 2
// recharge = 1
// output = false



