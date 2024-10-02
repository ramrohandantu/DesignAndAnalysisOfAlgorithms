//This program written by Ram Rohan Dantu for the course CE6301 Advanced Digital Logic
//In the problem on page 130, the nodes are from 1-6, but i have used the following mapping
//1->0
//2->1
//3->2
//4->3
//5->4
//6->5

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

//Functions
void printgraph(vector<double> & graph, size_t siz);
void dijkstra(vector<double> & graph, vector<double> & SPT, vector<double> & distances, size_t sizG, int start, int end);

int main(void){
	
	cout << "\n start" << endl;
	
	//Declarations
	size_t sizeGraph = 6;
	vector<double> graph(sizeGraph*sizeGraph);
	vector<double> SPT(sizeGraph*sizeGraph); //shortest path tree
	vector<double> distances(sizeGraph); // vector of distances
	int start = 0; // corresponds to a in the problem
	int end = 4; // corresponds to b in the problem
	
	for(int i=0;i<sizeGraph;i++){
		for(int j=0;j<sizeGraph;j++){
			graph[i*sizeGraph+j]=0;
			SPT[i*sizeGraph+j]=0;
		}
	}
		
	graph[0*sizeGraph+1]=7;
	graph[0*sizeGraph+2]=9;
	graph[0*sizeGraph+5]=14;
	graph[1*sizeGraph+0]=7;
	graph[1*sizeGraph+2]=10;
	graph[1*sizeGraph+3]=15;
	graph[2*sizeGraph+0]=9;
	graph[2*sizeGraph+1]=10;
	graph[2*sizeGraph+3]=11;
	graph[2*sizeGraph+5]=2;
	graph[3*sizeGraph+1]=15;
	graph[3*sizeGraph+2]=11;
	graph[3*sizeGraph+4]=6;
	graph[4*sizeGraph+3]=6;
	graph[4*sizeGraph+5]=9;
	graph[5*sizeGraph+0]=14;
	graph[5*sizeGraph+2]=2;
	graph[5*sizeGraph+4]=9;
	
	cout << "\nInput Graph" << endl;
	printgraph(graph,sizeGraph);
	dijkstra(graph, SPT, distances, sizeGraph, start, end);
	printgraph(SPT,sizeGraph);
	
	return 0;
}

void printgraph(vector<double> & graph, size_t siz){

	for(int i=0;i<siz;i++){
		for(int j=0;j<siz;j++){
			cout << setw(8) << graph[siz*i + j];
		}
		cout << endl;
	}
	cout << endl;
}

void dijkstra(vector<double> & graph, vector<double> & SPT, vector<double> & distances, size_t sizG, int start, int end){

	//set holding the list of nodes added to the shortest path tree set
	vector<double> sptSET(sizG);
	
	//vector holding the parents of all the nodes
	vector<double> parents(sizG);
	
	size_t sizSPT = sizG;

	for(int i=0;i<sizG;i++){
		sptSET[i] = -1;
		distances[i]=1000;
		parents[i] = -1;
	}
	sptSET[start]=0;
	distances[start]=0;
	int current = start;

	//DIJKSTRA's ALGORITHM
	//while loop iterates till end is added to the shortest path tree
	while(sptSET[end] == -1){
		for(int j=1;j<sizG;j++){//update the distances of adjacent nodes
			if(graph[sizG*current+j]>0){//edge is present in graph
				if(sptSET[j] == -1){//vertex is not added to shortest path tree set
					if(distances[current] + graph[sizG*current+j] < distances[j]){
						distances[j] = distances[current] + graph[sizG*current+j];
						parents[j] = current;
					}
				}
			}
		}

		//Add the vertex with min distance to the shortest path tree set
		int min = 1;
		double min_distance = 1001;
		
		for(int j=1;j<sizG;j++){
			if(sptSET[j] == -1 && distances[j] < min_distance){
				min = j;
				min_distance = distances[j];
			}
		}
		if(sptSET[min] == -1){
			current = min;
			sptSET[current] = 0;

		}

	}

				
	//generate Gs
	int s = start;
	int m = end;
	while(m != s){
		SPT[sizSPT*m + parents[m]] = graph[sizG*m + parents[m]];
		SPT[sizSPT*parents[m] + m] = graph[sizG*parents[m] + m];
		m = parents[m];
	}
}
