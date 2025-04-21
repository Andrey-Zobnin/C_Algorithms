# Алгоритм Дейкстры

## Назначение
Алгоритм Дейкстры находит кратчайшие пути от одной вершины (источника) до всех остальных в взвешенном графе **без рёбер отрицательного веса**.

## Основные понятия
- **Граф** - набор вершин и рёбер между ними
- **Вес ребра** - стоимость прохождения по ребру
- **Расстояние** - сумма весов рёбер на пути
- **Приоритетная очередь** - структура данных для эффективного выбора вершины с минимальным расстоянием

## Алгоритм (по шагам)
1. Инициализация:
   - Установить расстояние до источника = 0
   - Установить расстояния до всех остальных вершин = ∞
   - Добавить все вершины в приоритетную очередь

2. Пока очередь не пуста:
   - Извлечь вершину `u` с минимальным расстоянием
   - Для каждого соседа `v` вершины `u`:
     - Вычислить новое расстояние: `расстояние[u] + вес(u, v)`
     - Если новое расстояние < текущего расстояния до `v`:
       - Обновить расстояние до `v`
       - Обновить приоритет `v` в очереди

3. Вернуть массив расстояний

## Временная сложность
- С кучей (priority queue): **O((V + E) log V)**
- Без кучи (линейный поиск минимума): **O(V²)**

## Код на C++

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii; // (distance, vertex)

vector<int> dijkstra(const vector<vector<pii>>& graph, int start) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int current_dist = pq.top().first;
        pq.pop();
        
        if (current_dist > dist[u]) continue;
        
        for (auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;
            
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist;
}

int main() {
    // Пример графа (список смежности)
    vector<vector<pii>> graph = {
        {{1, 4}, {2, 1}},       // 0 -> (1,4), (2,1)
        {{3, 2}},               // 1 -> (3,2)
        {{1, 2}, {3, 5}},       // 2 -> (1,2), (3,5)
        {{4, 3}},               // 3 -> (4,3)
        {}                      // 4
    };
    
    vector<int> distances = dijkstra(graph, 0);
    
    cout << "Кратчайшие расстояния от вершины 0:\n";
    for (int i = 0; i < distances.size(); ++i) {
        cout << "До вершины " << i << ": " << distances[i] << "\n";
    }
    
    return 0;
}