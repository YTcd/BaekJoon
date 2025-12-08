#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Person {
    int age;
    string name;
    int order;   // 입력 순서
};

bool compare(const Person &a, const Person &b) {
    if (a.age != b.age)
        return a.age < b.age;
    return a.order < b.order;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int count;
    cin >> count;

    vector<Person> vector(count);
    for (int i = 0; i < count; i++) {
        cin >> vector[i].age >> vector[i].name;
        vector[i].order = i;
    }

    stable_sort(vector.begin(), vector.end(), compare);

    for (auto &p : vector) {
        cout << p.age << " " << p.name << "\n";
    }

    return 0;
}