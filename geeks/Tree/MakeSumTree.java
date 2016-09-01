class Node{
	int info;
	Node left,right;
	Node(int data){
		info = data;
		left=right=null;
	}
}
class MakeSumTree{
	public static int change(Node root){
		if(root==null){
			return 0;
		}
		if(root.left==null && root.right==null){
			int temp = root.info;
			root.info = 0;
			return temp;
		}

		int temp = root.info;

		root.info = change(root.left)+change(root.right);
		return root.info+temp;
	}


	public static void inOrder(Node root){
		if(root==null){
			return;
		}
		System.out.print(" "+root.info);
		inOrder(root.left);
		inOrder(root.right);
	}

	public static void main(String[] args) {
		Node root = new Node(10);
		root.left = new Node(-2);
		root.right = new Node(6);
		root.left.left = new Node(8);
		root.left.right = new Node(-4);

		root.right.left = new Node(7);
		root.right.right = new Node(5);

		System.out.println("Earlier traversal");
		inOrder(root);
		System.out.println();

		change(root);
		System.out.println("After changing tree");
		inOrder(root);
		System.out.println();

	}
}