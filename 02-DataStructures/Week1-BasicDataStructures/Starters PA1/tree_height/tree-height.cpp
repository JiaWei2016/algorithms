#include <iostream>
#include <vector>
#include <algorithm>

class Node {
public:
	int value;
	std::vector<Node*> children;
};

class TreeHeight {
  int n;             
  std::vector<int> parent;
  std::vector<Node*> allNodes;
  Node *root;

public:
  Node read() {
    std::cin >> n;
    parent.resize(n);
	for (int i = 0; i < n; i++) {
		std::cin >> parent[i];
		Node *node = new Node();
		node->value = i;
		allNodes.push_back(node);
	}
	for (int j = 0; j < n; j++) {
		//if the parent has a value of -1, it is the root node
		if (parent[j] != -1){
			Node *parentNode = allNodes[parent[j]];
			parentNode->children.push_back(allNodes[j]);
		}
		else{
			root = allNodes[j];
		}
		
	}
	return *root;
  }

  int compute_height(Node *n) {
	  int max = 0;
	  if (n == NULL){
		  return 0;
	  }
	  else {
		  for (int k = 0; k < n->children.size(); k++)
		  {
			  int h = compute_height(n->children[k]);
			  if (h > max)
				  max = h;
		  }
	  }
	  return 1 + max;
  }
};


int main() {
  std::ios_base::sync_with_stdio(0);
  TreeHeight tree;
  Node root = tree.read();
  std::cout << tree.compute_height(&root) << std::endl;
}
