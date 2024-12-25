#include "stdafx.h"
#include "Graph.h"

int main()
{
    setlocale(LC_ALL, "Rus");
    Graph graph;

    int startVertex;
    cout << "������� ��������� ������� (1-8): ";
    cin >> startVertex;


    while (startVertex < 1 || startVertex > 8)
    {
        cout << "������������ ����. ������� ����� �� 1 �� 8: ";
        cin >> startVertex;
    }

    cout << "������ ����� ��������� ������ � �� ��� (�������� �����)" << endl;
    graph.Prims(startVertex - 1);
    cout << "\n������ ����� ��������� ������ � �� ��� (�������� ��������)" << endl;
    graph.Kruskals();

    return 0;
}
