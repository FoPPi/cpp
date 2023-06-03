#include <iostream>
#include <vector>
#include <limits>
#include <queue>

#include <fstream>
#include <sstream>

#include <string>

//поддержка кирилицы
#include <io.h>
#include <fcntl.h>

using namespace std;

vector<int> dijkstra(const vector<vector<int>>& graph, int n, int start) {
    vector<int> dist(n, numeric_limits<int>::max());
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (int v = 0; v < n; ++v) {
            if (graph[u][v] != -1) {
                int new_dist = dist[u] + graph[u][v];
                if (new_dist < dist[v]) {
                    dist[v] = new_dist;
                    pq.push({new_dist, v});
                }
            }
        }
    }

    return dist;
}

int main() {

    system("cls");

    // для поддержки кирилицы 
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin),  _O_U16TEXT);
    _setmode(_fileno(stderr), _O_U16TEXT);



    ifstream file;
    file.open("marix.txt", ios::in);

    string line;
    getline(file, line);
    istringstream iss(line);
    int num;
    vector<int> values;
    
    while (iss >> num) {
        values.push_back(num);
    }

    int n = values.size();

    file.close();
    file.open("marix.txt", ios::in);

    vector<vector<int>> graph(n, vector<int>(n, -1));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            file>>graph[i][j];
        }
    }

    file.close();

    vector<int> distances = dijkstra(graph, n, 0);
    wcout << L"Найкоротший шлях від v1 до v" << n << ": " << distances[n - 1] << endl;

    cout << "\n";
    system("pause");
    return 0;
}
