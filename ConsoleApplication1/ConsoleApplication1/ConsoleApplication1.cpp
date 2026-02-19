// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

void show( vector<vector<int>> &mas) {
    int length = mas.size();
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            cout << mas[i][j] << " ";
        }
        cout << endl;
    }
}
void show(vector<int>& mas) {
    int length = mas.size();
    
        for (int j = 0; j < length; j++)
        {
            cout << mas[j] << " ";
        }
        cout << endl;
    
}
void search(vector<vector<int>> & mas, int start, int end) {
    int size = mas.size();
    vector<int> res(size, -1);
    queue<int> q;
    vector<bool> visit(size, false);
    visit[start] = true;
    q.push(start);
    while (!q.empty()) {
        int c = q.front();
        q.pop();
        if (c == end)
        {
            break;
        }
        for (int i = 0; i < size; i++)
        {
            if (mas[c][i] == 1 && !visit[i])
            {
                visit[i] = true;
                q.push(i);
                res[i] = c;
       
            }
            
        }
       
    }
    vector<int> path;
    int current = end;
    while (current != -1) {
        path.push_back(current);
        current = res[current];
    }
    //int buf = path[0];
    //path[0] = path[path.size() - 1];
    //path[path.size() - 1] = buf;

    show(path);
}
int main()

{
    srand(time(0));

    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n,0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) {
            if (rand() % 10 > 6 && i != j)
            {
                mat[i][j] = 1;
                mat[j][i] = 1;
            }
            
        }
    }
    show(mat);
    int ver1, ver2;
    cin >> ver1 >> ver2;
    search(mat, ver1, ver2);

}
