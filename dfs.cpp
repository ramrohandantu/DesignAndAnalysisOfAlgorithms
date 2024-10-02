//This program to perform df written by Ram Rohan Dantu for CE6301 Advanced Digital Logic

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

void dfs(vector<double> & adjGraph, size_t sizeGraph, int current, vector<double> & visited, vector<double> & visiting);

int main(void){

	cout << "\nstart" << endl;
	
	/*In the example graph on page 69, the nodes are alphabetical. The following is the conversion from alpha to numeric
	 *s->0
	 *t->1
	 *u->2
	 *v->3
	 *w->4
	 *x->5
	 *y->6
	 *z->7 
	 *
	 */
	
	//Declarations
	size_t sizeGraph = 8;
	vector<double> adjGraph(sizeGraph*sizeGraph);
	vector<double> visited(sizeGraph);
	vector<double> visiting(sizeGraph);

	for(int i=0;i<sizeGraph;i++){
		for(int j=0;j<sizeGraph;j++){
			adjGraph[i*sizeGraph+j] = 0;
		}
	}
	for(int i=0;i<sizeGraph;i++){
		visited[i]=0;
	}
	for(int i=0;i<sizeGraph;i++){
		visiting[i]=0;
	}
	
	adjGraph[0*sizeGraph+3] = 1;
	adjGraph[0*sizeGraph+4] = 1;
	adjGraph[1*sizeGraph+3] = 1;
	adjGraph[2*sizeGraph+3] = 1;
	adjGraph[3*sizeGraph+4] = 1;
	adjGraph[4*sizeGraph+5] = 1;
	adjGraph[5*sizeGraph+0] = 1;
	adjGraph[5*sizeGraph+3] = 1;
	adjGraph[5*sizeGraph+6] = 1;
	adjGraph[6*sizeGraph+1] = 1;
	adjGraph[6*sizeGraph+3] = 1;
	adjGraph[7*sizeGraph+1] = 1;
	adjGraph[7*sizeGraph+2] = 1;
	adjGraph[7*sizeGraph+6] = 1;
	
	cout << "\nGraph Input" <<endl;
	for(int i=0;i<sizeGraph;i++){
		for(int j=0;j<sizeGraph;j++){
			cout << adjGraph[i*sizeGraph+j] << " ";
		}
		cout << endl;
	}
	
	for(int k=0;k<sizeGraph;k++){
		if(visited[k]==0){
			dfs(adjGraph, sizeGraph, k, visited, visiting);
		}
	}

}


void dfs(vector<double> & adjGraph, size_t sizeGraph, int current, vector<double> & visited, vector<double> & visiting){

	if(visited[current] ==1){
		return;
	}
	visiting[current] = 1;
	for(int j=0;j<sizeGraph;j++){
		if(adjGraph[current*sizeGraph+j]==1 && visiting[j]==0){
			visiting[j]=1;
			dfs(adjGraph, sizeGraph, j, visited, visiting);
		}
	}
	visited[current]=1;
	cout << current << endl;
}

