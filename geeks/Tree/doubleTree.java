class Node{
	int info;
	Node left;
	Node right;
	Node(int data){
		info = data;
		left = null;
		right = null;
	}
}

class doubleTree{
	public void DoubleTree(Node root){
		if(root==null){
			return;
		}
		Node newNode = new Node(root.info);
		Node temp = root.left;
		root.left = newNode;
		newNode.left = temp;
		DoubleTree(temp);
		DoubleTree(root.right);
	}

	public void PreOrder(Node root){
		if(root==null){
			return;
		}
		System.out.print(" "+root.info);
		PreOrder(root.left);
		PreOrder(root.right);
	}

	public static void main(String[] s){
		Node root = new Node(1);
		root.left = new Node(2);
		root.right = new Node(3);
		root.left.left = new Node(4);
		root.left.right = new Node(5);
		
		doubleTree d= new doubleTree();
		System.out.println("Original tree PreOrder");
		d.PreOrder(root);
		d.DoubleTree(root);
		System.out.println("Double tree PreOrder");
		d.PreOrder(root);
		System.out.println();
	}
}