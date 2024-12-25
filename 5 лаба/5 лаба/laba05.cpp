#include "stdafx.h"
#include "Graph.h"

int main()
{
    setlocale(LC_ALL, "Rus");
    Graph graph;

    int startVertex;
    cout << "Введите начальную вершину (1-8): ";
    cin >> startVertex;


    while (startVertex < 1 || startVertex > 8)
    {
        cout << "Некорректный ввод. Введите число от 1 до 8: ";
        cin >> startVertex;
    }

    cout << "Список ребер остовного дерева и их вес (алгоритм Прима)" << endl;
    graph.Prims(startVertex - 1);
    cout << "\nСписок ребер остовного дерева и их вес (алгоритм Краскала)" << endl;
    graph.Kruskals();

    return 0;
}
