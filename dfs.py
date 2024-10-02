#This program written by Ram Rohan Dantu for the Course CE6301 Advanced Digital Logic

#In the example graph, the nodes are alphabetical, the following is the alphabet to node converion:
#s -> 0
#t -> 1
#u -> 2
#v -> 3
#w -> 4
#x -> 5
#y -> 6
#z -> 7


print "start"
sizeGraph = 8
sizeAdjGraph = (sizeGraph) * (sizeGraph)
adjGraph = range(sizeAdjGraph)
#print adjGraph
for i in range(0,sizeGraph):
	for j in range(0,sizeGraph):
		adjGraph[i*sizeGraph+j] = 0
#build the adjGraph
adjGraph[0*sizeGraph+3] = 1
adjGraph[0*sizeGraph+4] = 1
adjGraph[1*sizeGraph+3] = 1
adjGraph[2*sizeGraph+3] = 1
adjGraph[3*sizeGraph+4] = 1
adjGraph[4*sizeGraph+5] = 1
adjGraph[5*sizeGraph+0] = 1
adjGraph[5*sizeGraph+3] = 1
adjGraph[5*sizeGraph+6] = 1
adjGraph[6*sizeGraph+1] = 1
adjGraph[6*sizeGraph+3] = 1
adjGraph[7*sizeGraph+1] = 1
adjGraph[7*sizeGraph+2] = 1
adjGraph[7*sizeGraph+6] = 1

print "Graph input"
for i in range(0,sizeGraph):
	for j in range(0,sizeGraph):
		print adjGraph[i*sizeGraph+j],
	print "\n"

visited = range(sizeGraph)
for i in range(0,sizeGraph):
	visited[i] = 0;
#print visited

visiting = range(sizeGraph)
for i in range(0,sizeGraph):
	visiting[i] = 0;

def dfs(adjGraph,sizeGraph,current,visited,visiting):
	if visited[current] == 1:
		return
	visiting[current] = 1
	for j in range(0,sizeGraph):
		if adjGraph[current*sizeGraph+j] == 1 and visiting[j] == 0:
			visiting[j] = 1
			dfs(adjGraph,sizeGraph,j,visited,visiting)
	visited[current] = 1
	print current
	#print " " + str(current) + "-> "
	return

for k in range(0,sizeGraph):
	if visited[k] ==0:
		dfs(adjGraph,sizeGraph,k,visited,visiting)


