
#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<set>
#include<algorithm>

using namespace std;

//图节点
template <class T>
class GraphNode{
public:
	GraphNode(T _data , string _name):data(_data) , nodeName(_name){
	}

	bool addEdgeNode(vector<GraphNode *> adjustNodes){
		for(GraphNode *n : adjustNodes){
			addEdgeNode(n);
		}
		return false;
	}

	bool addEdgeNode(GraphNode *adjustNode){
		if(adjustNode == nullptr || adjustNode == this)
			return false;
		
		adjustTable.insert(adjustNode);
		return true;
	}

	void showAllEdges(){
		cout << "node_name = " << nodeName << " value = " << data 
			<< " adjust = [";
		for(GraphNode<T> *adjNode : adjustTable){
			cout << adjNode->nodeName << " ";
		}
		cout << "]" << endl;
	}

	string nodeName;//节点名称
	T data;//实际数据
	set<GraphNode *> adjustTable;//邻接表
};

//图的表示
template <class T>
class Graph{
public:
	set<GraphNode<T> *> nodes;
	
	int size(){
		return nodes.size();
	}

	bool addNode(GraphNode<T> *newNode){
		if(newNode == nullptr)
			return false;
		
		nodes.insert(newNode);
		return true;
	}

	void addEdge(GraphNode<T> *node , set<GraphNode<T> *> edges){

	}
};

int main(int agrc , char *agrv[]){
	Graph<int> graph;

	cout << "graph size = " << graph.size() << endl;


	GraphNode<int> node1(100 , "node1");
	GraphNode<int> node2(200 , "node2");

	GraphNode<int> node3(303 , "node3");


	graph.addNode(&node1);
	graph.addNode(&node2);
	graph.addNode(&node2);
	graph.addNode(&node3);

	cout << "graph size = " << graph.size() << endl;

	node1.addEdgeNode(&node1);
	node1.addEdgeNode(&node2);
	node1.addEdgeNode(&node1);
	node2.addEdgeNode(&node1);

	node1.showAllEdges();
	node2.showAllEdges();
	node3.showAllEdges();

	return 0;
}

