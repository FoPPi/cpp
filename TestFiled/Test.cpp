#include <iostream>
#include <string>

using namespace std;

struct Worker {
    int id;
    int factory;
    double salary;
};

int rnd(int min, int max);
Worker generateWorker(int id);
void printWorkers(Worker workers[], int n);
void insertionSort(Worker workers[], int n);
double calculateTotalSalary(Worker workers[], int n);

int main() {

    const int N = 9;
    Worker workers[N];
    for (int i = 0; i < N; i++) {
        workers[i] = generateWorker(i+1);
    }

    cout << "Without sortinfg" << endl;

    printWorkers(workers, N);

    cout << "\n";

    insertionSort(workers, N);

    cout << "With sortinfg" << endl;

    printWorkers(workers, N);

    cout << "\n";

    cout << "Total Salary: " << calculateTotalSalary(workers, N) << "\n";

    return 0;
}

int rnd(int min, int max)
{

    int num = min + rand() % (max - min + 1);

    return num;
}

Worker generateWorker(int id) {
    Worker newWorker = {id, rnd(1,10), (double)rnd(2000,10000)};
    return newWorker;
}

void printWorkers(Worker workers[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "ID - " << workers[i].id << endl;
        cout << "Factory - " << workers[i].factory << endl;
        cout << "Salary - " << workers[i].salary << "$" << endl;
        cout << "\n";
    }
}

void insertionSort(Worker workers[], int n) {
    Worker temp;
    for (int i = 0; i < n; i++){
        for (int j = 0; j + 1 < n - i; j++){
            if (workers[j].salary > workers[j + 1].salary)
            {
                temp = workers[j];
                workers[j] = workers[j + 1];
                workers[j + 1] = temp;
            }
            else if (workers[j].salary == workers[j + 1].salary  &&
                     workers[j].id > workers[j + 1].id)
            {
                temp = workers[j];
                workers[j] = workers[j + 1];
                workers[j + 1] = temp;
            }
        }
            
    }
        
}

double calculateTotalSalary(Worker workers[], int n) {
    if (n == 0) {
        return 0;
    } else {
        return calculateTotalSalary(workers, n-1) + workers[n-1].salary;
    }
}
