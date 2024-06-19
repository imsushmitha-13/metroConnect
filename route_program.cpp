#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <iomanip>
using namespace std;

class Graph {
    int V;
    vector<vector<pair<int, int> > > adjList;

public:
    Graph(int V);
    void addEdge(int u, int v, int w = 1);
    vector<int> dijkstra(int src, int dest);
};

Graph::Graph(int V) {
    this->V = V;
    adjList.resize(V);
}

void Graph::addEdge(int u, int v, int w) {
    adjList[u].push_back(make_pair(v, w));
    adjList[v].push_back(make_pair(u, w));
}

vector<int> Graph::dijkstra(int src, int dest) {
    vector<int> dist(V, INT_MAX);
    vector<int> prev(V, -1);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    dist[src] = 0;
    pq.push(make_pair(0, src));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (vector<pair<int, int> >::iterator it = adjList[u].begin(); it != adjList[u].end(); ++it) {
            int v = it->first;
            int weight = it->second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
                prev[v] = u;
            }
        }
    }

    vector<int> path;
    for (int at = dest; at != -1; at = prev[at]) {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());

    if (path[0] == src) {
        return path;
    }
    vector<int> empty_path;
    return empty_path;  // return an empty path if there is no path from src to dest
}

int main(int argc, char* argv[]) {
    int V = 57;
    Graph g(V);

    // Adding edges according to the given mapping
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.addEdge(7, 8);
    g.addEdge(8, 9);
    g.addEdge(8, 28);
    g.addEdge(9, 10);
    g.addEdge(10, 11);
    g.addEdge(11, 12);
    g.addEdge(12, 13);
    g.addEdge(13, 14);
    g.addEdge(14, 15);
    g.addEdge(15, 16);
    g.addEdge(16, 17);
    g.addEdge(17, 18);
    g.addEdge(17, 48);
    g.addEdge(17, 47);
    g.addEdge(18, 19);
    g.addEdge(19, 20);
    g.addEdge(20, 21);
    g.addEdge(21, 22);
    g.addEdge(22, 23);
    g.addEdge(23, 24);
    g.addEdge(24, 25);
    g.addEdge(25, 26);
    g.addEdge(26, 27);
    g.addEdge(56, 55);
    g.addEdge(55, 54);
    g.addEdge(54, 53);
    g.addEdge(53, 52);
    g.addEdge(52, 51);
    g.addEdge(51, 50);
    g.addEdge(50, 49);
    g.addEdge(49, 48);
    g.addEdge(48, 17);
    g.addEdge(17, 47);
    g.addEdge(47, 46);
    g.addEdge(46, 45);
    g.addEdge(45, 44);
    g.addEdge(44, 35);
    g.addEdge(35, 43);
    g.addEdge(43, 42);
    g.addEdge(42, 41);
    g.addEdge(41, 40);
    g.addEdge(40, 39);
    g.addEdge(39, 38);
    g.addEdge(38, 37);
    g.addEdge(37, 36);
    g.addEdge(35, 34);
    g.addEdge(34, 33);
    g.addEdge(33, 32);
    g.addEdge(32, 31);
    g.addEdge(31, 30);
    g.addEdge(30, 29);
    g.addEdge(29, 28);
    g.addEdge(28, 8);

    const char* str_array[] = {
        "", "LBnagar", "Victoria_memorial", "chaitanyapuri", "Dilshukhnagar",
        "moosrambagh", "NewMarket", "malakpet", "MGbusstation", "Osmania_medical",
        "Gandhibhavan", "Nampally", "Assembly", "Lakdikapool", "Khairtabad",
        "Irrummanzil", "Panjagutta", "Ameerpet", "SRnagar", "ESIhospital",
        "Erragadda", "Bharatnagar", "Moosapet", "DR_BRambedkar", "Kukatpally",
        "KPHBcolony", "JNTUcollege", "Miyapur", "Sultanbazar", "Narayanguda",
        "Chikkadpali", "RTCxroads", "Musheerabad", "Gandhihospital", "Secunderabad West",
        "Paradeground", "Nagole", "Uppal", "stadium", "NGRI", "Habsiguda",
        "Tarnaka", "Mettuguda", "Secunderabad East", "Paradise", "Rasoolpura",
        "PrakashNagar", "Begumpet", "MathuraNagar", "Yusufguda", "Jubliehills",
        "JH-checkpost", "Peddamagudi", "Madhapur", "Dugamcheruvu", "Hitechcity", "raidurg"
    };

    const char* str_array2[] = {
        "", "Red Line", "Red Line", "Red Line", "Red Line",
        "Red Line", "Red Line", "Red Line", "Red/Green Line", "Red Line",
        "Red Line", "Red Line", "Red Line", "Red Line", "Red Line",
        "Red Line", "Red Line", "Red/Blue Line", "Red Line", "Red Line",
        "Red Line", "Red Line", "Red Line", "Red Line", "Red Line",
        "Red Line", "Red Line", "Red Line", "Green Line", "Green Line",
        "Green Line", "Green Line", "Green Line", "Green Line", "Green Line",
        "Blue/Green Line", "Blue Line", "Blue Line", "Blue Line", "Blue Line", "Blue Line",
        "Blue Line", "Blue Line", "Blue Line", "Blue Line", "Blue Line",
        "Blue Line", "Blue Line", "Blue Line", "Blue Line", "Blue Line",
        "Blue Line", "Blue Line", "Blue Line", "Blue Line", "Blue Line", "Blue Line"
    };
    vector<string> str(str_array, str_array + sizeof(str_array) / sizeof(str_array[0]));
    vector<string> str2(str_array2, str_array2 + sizeof(str_array2) / sizeof(str_array2[0]));
	unordered_map<string, int> mp;
    unordered_map<string, string> mp2;
	int idx = 0;
	for(int i=0; i<57; i++){
		mp[str_array[i]] = idx;
        mp2[str_array[i]] = str_array2[i];
		idx++;
	}
    int s1 = 0, s2 = 0;
	s1 = mp[argv[1]];
	s2 = mp[argv[2]];

    vector<int> path = g.dijkstra(s1, s2);

    if (path.empty()) {
        cout << "No path found from " << str_array[s1] << " to " << str_array[s2] << endl;
    } else {
        int idx = 1;
        cout << "Shortest path from " << str_array[s1] << " to " << str_array[s2] << ":" << endl;           
        cout<<endl;
        cout << left;
        cout << setw(10) << "No.";
        cout << setw(20) << "Stations";
        cout << right;
        cout << setw(4) << "Metro Line";
        cout << endl;
        for (vector<int>::iterator it = path.begin(); it != path.end(); ++it) {
                cout << left;
                cout<<setw(10)<<idx;
                cout << setw(20) << str[*it];
                cout << setw(4) << mp2[str[*it]];
                cout<<endl;
            idx++;
        }
        cout << endl;
    }

    return 0;
}