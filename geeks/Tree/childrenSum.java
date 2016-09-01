class Node{
	int info;
	Node left,right;
	Node(int item){
		info = item;
		left=right=null;
	}
}
class childrenSum{
	public static void inOrder(Node root){
		if(root==null){
			return;
		}
		inOrder(root.left);
		System.out.print(" "+root.info);
		inOrder(root.right);
	}

	void correctTree(Node root){
		if(root==null || (root.left==null&&root.right==null)){
			return;
		}
		correctTree(root.left);
		correctTree(root.right);
		int l=0,r=0;
		if(root.left!=null){
			l=root.left.info;
		}
		if(root.right!=null){
			r = root.right.info;
		}

		if(root.info<=l+r){
			System.out.println("Here l = "+l+"r = "+r+"info = "+root.info);
			root.info = l+r;
			return;
		}
		else{
			int diff = root.info - (l+r);
			System.out.println("Here2 l = "+l+"r = "+r+"info = "+root.info);
			System.out.println("differenc is "+diff);
			Node temp = root;
			while(temp!=null){
				temp.info = temp.info+diff;
				if(temp.left==null)
					temp = temp.right;
				else
					temp = temp.left;
			}
		}
	}


	public static void main(String s[]){
		
		Node root = new Node(50);
		root.left = new Node(7);
		root.right = new Node(2);
		root.left.left = new Node(3);
		root.left.right = new Node(5);
		root.right.left = new Node(1);
		root.right.right = new Node(30);
		System.out.println();
		System.out.println("Initally tree was INORDER TRAVERSAL");
		childrenSum c= new childrenSum();
		c.inOrder(root);
		c.correctTree(root);
		System.out.println();
		System.out.println("After correction tree is INORDER TRAVERSAL");	
		c.inOrder(root);
		System.out.println();
	}
}