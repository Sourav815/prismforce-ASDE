
#include <iostream>
#include <vector>

using namespace std;

bool canCrossChakravyuh(int p, vector<int> &enemyPowers, int a, int b)
{
    int n = enemyPowers.size();
    vector<bool> defeated(n, false); // Keeps track of enemies defeated
    int skipsLeft = a;
    int rechargesLeft = b;
    int currentPower = p;

    for (int i = 0; i < n; i++)
    {
        if (enemyPowers[i] > currentPower)
        {
            if (skipsLeft > 0)
            {
                skipsLeft--;
                continue;
            }
            else if (rechargesLeft > 0)
            {
                rechargesLeft--;
                currentPower = p;
                i--;
                continue;
            }
            else
            {
                return false;
            }
        }
        currentPower -= enemyPowers[i];
        defeated[i] = true;
        if (i == 2 || i == 6)
        { // k3 and k7 indices are 2 and 6
            int regeneratePower = enemyPowers[i] / 2;
            if (regeneratePower > 0 && defeated[i])
            {
                // Regenerate once and attack from behind
                if (i + 1 < n && regeneratePower >= currentPower)
                {
                    // If Abhimanyu cannot handle the regenerated enemy attack
                    if (skipsLeft > 0)
                    {
                        // Use a skip
                        skipsLeft--;
                    }
                    else if (rechargesLeft > 0)
                    {
                        // Use a recharge
                        rechargesLeft--;
                        currentPower = p;
                        i--; // Retry the next circle
                    }
                    else
                    {
                        return false; // Abhimanyu loses
                    }
                }
            }
        }
    }

    return true; // Abhimanyu successfully crosses the Chakravyuh
}

int main()
{
    int power = 5;
    vector<int> enemyPower = {0, 10, 2, 3, 9, 5, 6, 7, 8, 4, 7};
    int a = 5, b = 3;

    // Check if Abhimanyu can cross the Chakravyuh for Test Case 1
    if (canCrossChakravyuh(power, enemyPower, a, b))
    {
        cout << "Abhimanyu successfully crosses the Chakravyuh." << endl;
    }
    else
    {
        cout << "Abhimanyu fails to cross the Chakravyuh." << endl;
    }

    return 0;
}