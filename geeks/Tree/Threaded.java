class Node{
	int data;
	Node left,right;
	boolean isThreaded;
	Node(int value){
		data = value;
		left = right = null;
		isThreaded =false;
	}
}

class Threaded{
	static Node previous = null;

	void convertThreaded(Node root){
		if(root==null){
			return;
		}
		convertThreaded(root.right);
		if(root.right==null){
			root.right = previous;
			root.isThreaded = true;
		}
		previous =root;
		convertThreaded(root.left);
	}


	// Inorder Traversal using threads of threaded binary tree without stack and recursion
	void Inorder(Node root){
		if(root==null){
			return;
		}

		Node current = root;

		while(current!=null){
			while(current.left!=null){
				current = current.left;
			}
			
				
				while(current!=null && current.isThreaded){
					System.out.print(current.data+" ");
					current = current.right;
				}
				if(current!=null){
				System.out.print(current.data+" ");
				current = current.right;
			}
		}
	}

	public static void main(String[] args) {
		Node root = new Node(6);
		root.left = new Node(3);
		root.right = new Node(8);

		root.left.left = new Node(1);
		root.left.right = new Node(5);
		root.left.right.left = new Node(21);
		root.left.right.left.left = new Node(22);

		root.right.left = new Node(7);
		root.right.right = new Node(11);

		root.right.right.left = new Node(9);

		root.right.right.right = new Node(13);


		Threaded t = new Threaded();

		t.convertThreaded(root);
		t.Inorder(root);
		System.out.println();

	}
}