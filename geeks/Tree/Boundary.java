class Node{
	int info;
	Node left,right;
	Node(int data){
		info = data;
		left = right = null;
	}

}
class previous{
	Node pre;
	previous(){
		pre = null;
	}
}
class Boundary{
	// printing left part separately except the last leaf

	static void PrintLeft(Node root){
		if(root==null){
			return;
		}
		if(root.left==null && root.right==null){
			return;
		}
		System.out.print(" "+root.info);
		if(root.left!=null)
			PrintLeft(root.left);
		else if(root.right!=null){
			PrintLeft(root.right);
		}
	}

	// Printing leaf nodes
	static void printAll(Node root){
		if(root==null){
			return;
		}
		if(root.left==null && root.right==null){
			System.out.print(" "+root.info);
		}
		printAll(root.left);
		printAll(root.right);
		}

	// printing the right part of the tree

		static void printRight(Node root){
			if(root==null){
				return;
			}
			if(root.left==null && root.right==null){
				return;
			}
			if(root.right!=null){
				printRight(root.right);
				System.out.print(" "+root.info);
			}
			else if(root.left!=null){
				printRight(root.left);
				System.out.print(" "+root.info);
			}
		}


		public static void main(String s[]){

		Node root = new Node(20);
		root.left = new Node(8);
		root.right = new Node(22);
		root.right.right = new Node(25);
		root.left.left = new Node(4);
		root.left.right = new Node(12);
		root.left.right.left = new Node(10);
		root.left.right.left.left = new Node(9);
		root.left.right.right = new Node(14);
		
		previous p =new previous();
		PrintLeft(root);
		printAll(root);
		printRight(root);
		System.out.println();
		}
		
	

}