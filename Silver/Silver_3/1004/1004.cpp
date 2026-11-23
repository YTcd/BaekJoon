#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int countOfProblem;
    cin >> countOfProblem;
    for (int i = 0; i < countOfProblem; i++)
    {
        int result = 0;
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        int countOfPlanet;
        cin >> countOfPlanet;
        for (int j = 0; j < countOfPlanet; j++)
        {
            int px, py, pr;
            cin >> px >> py >> pr;

            bool isStartInCircle = (sx - px) * (sx - px) + (sy-py) * (sy-py) < pr * pr;
            bool isEndInCircle = (ex - px) * (ex - px) + (ey-py) * (ey-py) < pr * pr;

            if ((isStartInCircle == true || isEndInCircle == true) && (isStartInCircle == false || isEndInCircle == false))
            {
                result++;    
            }
        }

        cout << result << "\n";
    }
}