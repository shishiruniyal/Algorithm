class Node{
	int info;
	Node left,right;
	Node(int item){
		info = item;
		left = right = null;
	}
}

class treeList{

	public static Node treeToList(Node root){
		if(root==null){
			return null;
		}
		if(root.left==null && root.right==null){
			root.left = root;
			root.right = root;
			return root;
		}
		Node l1 = treeToList(root.left);
		Node l2 = treeToList(root.right);

		if(l1==null){
			root.left = l2.left;
			root.right = l2;
			l2.left.right = root;
			l2.left = root;
			return root;
		}
		else if(l2==null){
			l1.left.right = root;
			root.left = l1.left;
			root.right = l1;
			l1.left = root;
			return l1;
		}
		else{
			root.right = l2;
			root.left = l1.left;
			l1.left.right = root;
			l1.left = l2.left;
			l2.left.right = l1;
			l2.left = root;
			return l1;
		}
	}

	public static void main(String s[]){
		Node root = new Node(4);
		root.left = new Node(2);
		root.right = new Node(5);
		root.right.right = new Node(9);
		root.left.left = new Node(1);
		root.left.right = new Node(3);

		Node head = treeToList(root);
		System.out.println("Done changes\n printing list");
		Node temp = head;
		do{
			System.out.print(temp.info+"---->");
			temp = temp.right;
		}
		while(temp!=head);
		System.out.println();
	}
}