#include<iostream>

using namespace std;

int solution(int weight)
{
    int numFive = weight / 5;
    int tmp = 0;

    if (weight < 3) return -1;

    while (numFive != -1) {
        tmp = weight - (5 * numFive);

        if (tmp % 3 == 0) {
            return numFive + (tmp / 3);
        }
        numFive -= 1;
    }
    return -1;

}
int main()
{
    int weight;

    cin >> weight;
    cout << solution(weight) << endl;

    return 0;
}
