// #include <iostream>
// #include <vector>
// using namespace std;

// #define MAX 1001

// int T, N;
// vector<int> graph[MAX];
// int visited[MAX];

// int DFS(int v)
// {
//     visited[v] = 1;
//     static int next;
//     int gsize = graph[v].size();
//     for (int i = 0; i < gsize; i++){
//         next = graph[v][i];
//         if (!visited[next])
//             DFS(next);
//     }
//     if (next == v)
//         return 1;
//     return 0;
// }

// int main(){

//     int to, count;

//     count = 0;
//     cin >> T;
//     while (T--)
//     {
//         cin >> N;
//         for (int from = 1; from <= N; from++)
//         {
//             cin >> to;
//             graph[from].push_back(to);
//         }

//         for (int i = 1; i <= N; i++)
//         {
//             if (!visited[i])
//                 if (DFS(i))
//                     count++;
//         }
//         cout << count << '\n';
//     }
// }